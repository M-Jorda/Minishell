/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_classifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:55:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:31:32 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Check if character is an operator character
 * 
 * @param c Character to check
 * @return true if operator, false otherwise
 */
bool	ft_is_operator_char(char c)
{
	return (c == '|' || c == '>' || c == '<' || c == '&' || 
			c == '$' || c == '\'' || c == '"' || c == '(' || 
			c == ')' || c == '*' || c == '=');
}

/**
 * @brief Check if character is a redirection operator
 * 
 * @param c Character to check
 * @return true if redirection, false otherwise
 */
bool	ft_is_redirection_char(char c)
{
	return (c == '>' || c == '<');
}

/**
 * @brief Check if character is a logical operator
 * 
 * @param c Character to check
 * @return true if logical operator, false otherwise
 */
bool	ft_is_logical_operator_char(char c)
{
	return (c == '|' || c == '&');
}

/**
 * @brief Get token type from character(s)
 * 
 * @param input Input string
 * @param pos Current position
 * @return t_token_type Token type identified
 */
t_token_type	ft_get_token_type(char *input, int pos)
{
	char	c;
	char	next_c;

	c = input[pos];
	next_c = input[pos + 1];
	
	if (c == '|' && next_c == '|')
		return (TOKEN_OR);
	else if (c == '|')
		return (TOKEN_PIPE);
	else if (c == '>' && next_c == '>')
		return (TOKEN_APPEND);
	else if (c == '>')
		return (TOKEN_REDIR_OUT);
	else if (c == '<' && next_c == '<')
		return (TOKEN_HEREDOC);
	else if (c == '<')
		return (TOKEN_REDIR_IN);
	else if (c == '&' && next_c == '&')
		return (TOKEN_AND);
	else if (c == '$' && next_c == '?')
		return (TOKEN_STATUS);
	else if (c == '$')
		return (TOKEN_VAR);
	else if (c == '\'')
		return (TOKEN_QUOTE);
	else if (c == '"')
		return (TOKEN_DQUOTE);
	else if (c == '(')
		return (TOKEN_PAREN_OPEN);
	else if (c == ')')
		return (TOKEN_PAREN_CLOSE);
	else if (c == '*')
		return (TOKEN_WILDCARD);
	else if (c == '=')
		return (TOKEN_ASSIGN);
	else if (c == '\0')
		return (TOKEN_EOF);
	else
		return (TOKEN_WORD);
}
