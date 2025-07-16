/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:34:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Check if character needs expansion
 * 
 * @param c Character to check
 * @return bool true if needs expansion, false otherwise
 */
bool	ft_needs_expansion(char c)
{
	return (c == '$');
}

/**
 * @brief Expand variables in a token value
 * 
 * @param shell Shell structure
 * @param value Original token value
 * @return char* Expanded value, NULL on error
 */
char	*ft_expand_token_value(t_shell *shell, char *value)
{
	char	*result;
	char	*temp;

	if (!value || !shell)
		return (NULL);
	
	// First expand variables
	result = ft_process_var_expansion(shell, value);
	if (!result)
		return (NULL);
	
	// Then expand exit codes
	temp = ft_process_exit_code_expansion(shell, result);
	free(result);
	
	return (temp);
}

/**
 * @brief Main expansion function - expands variables in token list
 * 
 * @param shell Shell structure
 * @param token_list Token list to expand
 * @return int 0 on success, -1 on error
 */
int	ft_expansion(t_shell *shell, t_list *token_list)
{
	t_list	*current;
	char	*expanded_value;

	if (!shell || !token_list)
		return (-1);
	current = token_list;
	while (current)
	{
		if (current->type == TYPE_TOKEN && current->content.token)
		{
			if (current->content.token->type == TOKEN_WORD &&
				current->content.token->value)
			{
				// Only expand if the token contains variables
				if (ft_contains_variables(current->content.token->value))
				{
					expanded_value = ft_expand_token_value(shell, 
						current->content.token->value);
					if (!expanded_value)
						return (-1);
					free(current->content.token->value);
					current->content.token->value = expanded_value;
				}
			}
		}
		current = current->next;
	}
	return (0);
}
