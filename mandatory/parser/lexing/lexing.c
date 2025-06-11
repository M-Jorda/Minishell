/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:00:10 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/23 23:08:31 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

static int	ft_fill_token(t_content *tok, char *s, int *i, bool *quote)
{
	int	start;
	int	end;

	if (!tok || !s)
		return (-1);
	start = *i;
	tok->token->type = ft_get_type(s, i, quote);
	
	if (tok->token->type == TOKEN_ERROR)
		return (ft_new_token_err(tok->token, -2));
	
	// Skip quotes for quoted tokens
	if (tok->token->type == TOKEN_DQUOTE || tok->token->type == TOKEN_QUOTE)
		start++;
	
	// Skip $ for variable tokens
	if (tok->token->type == TOKEN_VAR)
	{
		start++;
		++(*i);
	}
	
	end = *i - start;
	tok->token->value = ft_substr(s, start, end);
	if (!tok->token->value)
		return (ft_new_token_err(tok->token, -1));
	
	return (0);
}

/**
 * @brief Creates a new token and adds it to the token list
 * 
 * @param s The input string
 * @param tok_h Pointer to the head of the token list
 * @param i Current position in the string
 * @param quote Flag indicating if we're inside quotes
 * @return int 0 on success, -1 on memory allocation failure, -2 on parsing error
 */
static int	ft_new_token(char *s, t_list **tok_h, int *i, bool *quote)
{
	t_content	tok;

	// Skip spaces unless they are significant
	if (ft_isspace(s[*i]))
	{
		while (s[*i] && ft_isspace(s[*i]))
			(*i)++;
		return (0);
	}
	
	if (*quote)
	{
		(*i)++;
		*quote = false;
	}
	
	tok.token = (t_token *)malloc(sizeof(t_token));
	if (!tok.token)
		return (-1);
	
	if (ft_fill_token(&tok, s, i, quote) < 0)
		return (-1);
	
	// Don't add space tokens to the list
	if (tok.token->type == TOKEN_SPACE)
	{
		free(tok.token->value);
		free(tok.token);
		return (0);
	}
	
	if (!ft_lstadd_back(tok_h, tok, TYPE_TOKEN))
	{
		free(tok.token->value);
		return (ft_new_token_err(tok.token, -1));
	}
	
	return (0);
}

/**
 * @brief Main lexing function to tokenize a string
 * 
 * @param shell The shell structure
 * @return t_list* Head of the token list, NULL on error
 */
t_list	*ft_lexing(t_shell *shell)
{
	t_list	*tok_h;
	bool	quote;
	int		status;
	int		i;

	if (!shell || !shell->current_line)
		return (NULL);
	
	tok_h = NULL;
	quote = false;
	i = 0;
	
	while (shell->current_line[i])
	{
		status = ft_new_token(shell->current_line, &tok_h, &i, &quote);
		if (status < 0)
			return (ft_lstfree_t(tok_h));
	}
	
	// Perform expansions
	status = 0;
	if (ft_expansion(shell, &tok_h, &status) < 0)
		return (ft_lstfree_t(tok_h));
	
	shell->token = tok_h;
	return (tok_h);
}
