/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:05:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:32:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Free a token and its content
 * 
 * @param token Token to free
 */
void	ft_free_token(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}

/**
 * @brief Free entire token list
 * 
 * @param token_list Token list to free
 */
void	ft_free_token_list(t_list *token_list)
{
	t_list	*current;
	t_list	*next;

	current = token_list;
	while (current)
	{
		next = current->next;
		if (current->type == TYPE_TOKEN && current->content.token)
			ft_free_token(current->content.token);
		free(current);
		current = next;
	}
}

/**
 * @brief Print token for debugging
 * 
 * @param token Token to print
 */
void	ft_print_token(t_token *token)
{
	char	*type_str;

	if (!token)
		return ;
	type_str = ft_get_token_type_string(token->type);
	ft_printf("Token: type=%s, value=\"%s\"\n", type_str, 
		token->value ? token->value : "(null)");
}

/**
 * @brief Print entire token list for debugging
 * 
 * @param token_list Token list to print
 */
void	ft_print_token_list(t_list *token_list)
{
	t_list	*current;
	int		i;

	current = token_list;
	i = 0;
	ft_printf("=== TOKEN LIST ===\n");
	while (current)
	{
		if (current->type == TYPE_TOKEN)
		{
			ft_printf("[%d] ", i);
			ft_print_token(current->content.token);
		}
		current = current->next;
		i++;
	}
	ft_printf("==================\n");
}

/**
 * @brief Get string representation of token type
 * 
 * @param type Token type
 * @return char* String representation
 */
char	*ft_get_token_type_string(t_token_type type)
{
	static char	*type_strings[] = {
		"WORD", "OR", "APPEND", "HEREDOC", "AND", "STATUS", "ERROR",
		"PIPE", "REDIR_OUT", "REDIR_IN", "VAR", "QUOTE", "DQUOTE",
		"PAREN_OPEN", "PAREN_CLOSE", "WILDCARD", "ASSIGN", "EOF",
		"BSLASH", "SPACE"
	};

	if (type >= 0 && type < 20)
		return (type_strings[type]);
	return ("UNKNOWN");
}
