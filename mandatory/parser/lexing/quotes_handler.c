/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:32:04 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Find matching quote in input
 * 
 * @param input Input string
 * @param start_pos Starting position (after opening quote)
 * @param quote_char Quote character to match
 * @return int Position of closing quote, -1 if not found
 */
static int	ft_find_closing_quote(char *input, int start_pos, char quote_char)
{
	int	pos;

	pos = start_pos;
	while (input[pos])
	{
		if (input[pos] == quote_char)
			return (pos);
		pos++;
	}
	return (-1); // Quote not closed
}

/**
 * @brief Handle single quotes - no expansion inside
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @return int 0 on success, -1 on error
 */
int	ft_handle_single_quotes(char *input, int *pos, t_token *token)
{
	int		start;
	int		end;
	int		len;

	start = *pos + 1; // Skip opening quote
	end = ft_find_closing_quote(input, start, '\'');
	if (end == -1)
		return (-1); // Unclosed quote error
	len = end - start;
	token->value = ft_substr(input, start, len);
	if (!token->value)
		return (-1);
	token->type = TOKEN_WORD; // Single quoted content becomes a word
	*pos = end + 1; // Move past closing quote
	return (0);
}

/**
 * @brief Handle double quotes - allow $ expansion inside
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @return int 0 on success, -1 on error
 */
int	ft_handle_double_quotes(char *input, int *pos, t_token *token)
{
	int		start;
	int		end;
	int		len;

	start = *pos + 1; // Skip opening quote
	end = ft_find_closing_quote(input, start, '"');
	if (end == -1)
		return (-1); // Unclosed quote error
	len = end - start;
	token->value = ft_substr(input, start, len);
	if (!token->value)
		return (-1);
	// TODO: Expansion will be handled in Phase 3
	token->type = TOKEN_WORD; // Double quoted content becomes a word
	*pos = end + 1; // Move past closing quote
	return (0);
}

/**
 * @brief Check if quotes are properly closed in input
 * 
 * @param input Input string
 * @return bool true if balanced, false otherwise
 */
bool	ft_quotes_are_balanced(char *input)
{
	int		i;
	char	quote_char;
	bool	in_quotes;

	i = 0;
	in_quotes = false;
	quote_char = 0;
	while (input[i])
	{
		if (!in_quotes && (input[i] == '\'' || input[i] == '"'))
		{
			quote_char = input[i];
			in_quotes = true;
		}
		else if (in_quotes && input[i] == quote_char)
		{
			in_quotes = false;
			quote_char = 0;
		}
		i++;
	}
	return (!in_quotes);
}
