/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:15:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:12:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Check if character is a quote
 * 
 * @param c Character to check
 * @return bool true if quote, false otherwise
 */
static bool	ft_is_quote(char c)
{
	return (c == '\'' || c == '"');
}

/**
 * @brief Remove outer quotes from a string
 * 
 * @param input Input string
 * @return char* String without outer quotes, NULL on error
 */
char	*ft_remove_quotes(char *input)
{
	int		len;
	char	*result;

	if (!input)
		return (NULL);
	len = ft_strlen(input);
	
	// Check if string has quotes at both ends
	if (len >= 2 && ft_is_quote(input[0]) && 
		input[0] == input[len - 1])
	{
		// Remove outer quotes
		result = ft_substr(input, 1, len - 2);
		return (result);
	}
	
	// No quotes to remove, return copy
	return (ft_strdup(input));
}

/**
 * @brief Process quote removal for all tokens in list
 * 
 * @param token_list Token list to process
 * @return int 0 on success, -1 on error
 */
int	ft_process_quote_removal(t_list *token_list)
{
	t_list	*current;
	char	*new_value;

	if (!token_list)
		return (0);
	current = token_list;
	while (current)
	{
		if (current->type == TYPE_TOKEN && current->content.token &&
			current->content.token->type == TOKEN_WORD &&
			current->content.token->value)
		{
			new_value = ft_remove_quotes(current->content.token->value);
			if (!new_value)
				return (-1);
			free(current->content.token->value);
			current->content.token->value = new_value;
		}
		current = current->next;
	}
	return (0);
}
