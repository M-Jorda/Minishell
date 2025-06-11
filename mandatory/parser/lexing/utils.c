/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:22:45 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/14 13:50:53 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Updates the iterator and returns the token type
 * 
 * @param type The token type to return
 * @param i Pointer to the current position in the string
 * @param add Number of positions to advance
 * @return t_token_type The token type, or TOKEN_ERROR on error
 */
static t_token_type	ft_getite(t_token_type type, int *i, int add)
{
	ft_printerr("TOKEN_TYPE: %d\n", add);
	if (add == -1)
		return (TOKEN_ERROR);
	*i += add;
	return (type);
}

/**
 * @brief Finds the end of a word token
 * 
 * @param s The input string
 * @param c The delimiter character
 * @param var If it is a variable or not
 * @return int Position of the end of the word
 */
static int	ft_eow(char *s, int c, bool var)
{
	int	i;

	i = 0;
	if (c == ' ')
	{
		while (ft_isspace(s[i]))
			i++;
		return (i);
	}
	if (s[i] && (ft_isalnum(s[i]) || s[i] == '_') && var)
	{
		while (s[i] && (ft_isalnum(s[i]) || s[i] == '_') && s[i] != ' ')
			i++;
		return (i);
	}
	if (!s[i])
		return (i);
	i++;
	while (s[i] && !ft_ismeta("|><$\"'()*=\\", s[i]) && s[i] != ' ')
	// {
	// 	ft_printerr("Q\n");
		i++;
	// }
	// ft_printerr("EOW: %d\n", i);
	return (i);
}

/**
 * @brief Identifies double character tokens like ||, >>, <<, etc.
 * 
 * @param s The input string
 * @param i Pointer to the current position
 * @return t_token_type The identified token type
 */
static t_token_type	ft_isdouble(char *s, int *i)
{
	if (s[*i] == '|' && s[*i + 1] == '|')
		return (ft_getite(TOKEN_OR, i, 2));
	else if (s[*i] == '|')
		return (ft_getite(TOKEN_PIPE, i, 1));
	else if (s[*i] == '<' && s[*i + 1] == '<')
		return (ft_getite(TOKEN_HEREDOC, i, 2));
	else if (s[*i] == '<')
		return (ft_getite(TOKEN_REDIR_IN, i, 1));
	else if (s[*i] == '>' && s[*i + 1] == '>')
		return (ft_getite(TOKEN_APPEND, i, 2));
	else if (s[*i] == '>')
		return (ft_getite(TOKEN_REDIR_OUT, i, 1));
	else if (s[*i] == '$' && s[*i + 1] == '?')
		return (ft_getite(TOKEN_STATUS, i, 2));
	else if (s[*i] == '$' && (ft_isalpha(s[*i + 1]) || s[*i + 1] == '_'))
	// {
	// 	ft_printerr("VAR\n");
		return (ft_getite(TOKEN_VAR, i, ft_eow(&s[*i + 1], 'w', true)));
	// }
	else if (s[*i] == '&' && s[*i + 1] == '&')
		return (ft_getite(TOKEN_AND, i, 2));
	return (ft_getite(TOKEN_WORD, i, ft_eow(&s[*i], 'w', false)));
}

static t_token_type	ft_allquote(char *s, int *i, bool *quote, char c)
{
	int	y;
	int	end;

	y = 0;
	while (s[*i + ++y])
	{
		if (s[*i + y] == c)
		{
			if (y > 0 && s[*i + y - 1] == '\\')
				y++;
			else
			{
				*quote = true;
				break ;
			}
		}
	}
	end = -1;
	if (y != -1)
		end = y;
	if (c == '"')
		return (ft_getite(TOKEN_DQUOTE, i, end));
	return (ft_getite(TOKEN_QUOTE, i, end));
}

/**
 * @brief Identifies the token type at the current position
 * 
 * @param s The input string
 * @param i Pointer to the current position
 * @param quote Flag to track quote status
 * @return t_token_type The identified token type
 */
t_token_type	ft_get_type(char *s, int *i, bool *quote)
{
	if (!s[*i])
		return (ft_getite(TOKEN_EOF, i, 0));
	if (ft_ismeta("|<>$", s[*i]) || (s[*i] == '&' && s[*i + 1] == '&'))
		return (ft_isdouble(s, i));
	else if (s[*i] == '(')
		return (ft_getite(TOKEN_PAREN_OPEN, i, 1));
	else if (s[*i] == ')')
		return (ft_getite(TOKEN_PAREN_CLOSE, i, 1));
	else if (s[*i] == '*')
		return (ft_getite(TOKEN_WILDCARD, i, 1));
	else if (s[*i] == '=')
		return (ft_getite(TOKEN_ASSIGN, i, 1));
	else if (s[*i] == '\\')
		return (ft_getite(TOKEN_BSLASH, i, 1));
	else if (s[*i] == '\'')
		return (ft_allquote(s, i, quote, '\''));
	else if (s[*i] == '"')
		return (ft_allquote(s, i, quote, '"'));
	else if (ft_isspace(s[*i]))
		return (ft_getite(TOKEN_SPACE, i, ft_eow(&s[*i + 1], ' ', false) + 1));
	return (ft_getite(TOKEN_WORD, i, ft_eow(&s[*i], 'w', false)));
}
