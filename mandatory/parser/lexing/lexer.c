/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:45:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:27:10 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Skip whitespace characters in input
 * 
 * @param input Input string
 * @param pos Current position pointer
 */
static void	ft_skip_whitespace(char *input, int *pos)
{
	while (input[*pos] && ft_isspace(input[*pos]))
		(*pos)++;
}

/**
 * @brief Check if we reached end of input
 * 
 * @param input Input string
 * @param pos Current position
 * @return true if at end, false otherwise
 */
static bool	ft_is_end_of_input(char *input, int pos)
{
	return (input[pos] == '\0');
}

/**
 * @brief Add EOF token to token list
 * 
 * @param token_list Token list to add to
 * @return int 0 on success, -1 on error
 */
static int	ft_add_eof_token(t_list **token_list)
{
	t_token		*eof_token;
	t_content	content;

	eof_token = malloc(sizeof(t_token));
	if (!eof_token)
		return (-1);
	eof_token->type = TOKEN_EOF;
	eof_token->value = NULL;
	content.token = eof_token;
	return (ft_lstadd_back(token_list, content, TYPE_TOKEN) ? 0 : -1);
}

/**
 * @brief Main lexer function - tokenizes input string
 * 
 * @param input Input string to tokenize
 * @param shell Shell structure (for context)
 * @return t_list* List of tokens, NULL on error
 */
t_list	*ft_lexer(char *input, t_shell *shell)
{
	t_list	*token_list;
	int		pos;
	int		result;

	if (!input || !shell)
		return (NULL);
	token_list = NULL;
	pos = 0;
	while (!ft_is_end_of_input(input, pos))
	{
		ft_skip_whitespace(input, &pos);
		if (ft_is_end_of_input(input, pos))
			break ;
		result = ft_tokenize_next(input, &pos, &token_list, shell);
		if (result == -1)
		{
			ft_free_token_list(token_list);
			return (NULL);
		}
	}
	if (ft_add_eof_token(&token_list) == -1)
	{
		ft_free_token_list(token_list);
		return (NULL);
	}
	return (token_list);
}
