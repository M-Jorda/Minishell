/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:25:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:13:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Expand variables inside double quotes
 * 
 * @param shell Shell structure
 * @param input Input string (content inside double quotes)
 * @return char* Expanded string, NULL on error
 */
char	*ft_expand_in_double_quotes(t_shell *shell, char *input)
{
	char	*result;
	char	*temp;
	int		i;
	int		eov;

	if (!input)
		return (ft_strdup(""));
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			temp = ft_expand_exit_code(shell);
			result = ft_safe_strjoin(result, temp);
			free(temp);
			i += 2;
		}
		else if (input[i] == '$' && (eov = ft_eov(&input[i + 1])) > 0)
		{
			temp = ft_getenv_value(shell, input, i + 1, eov);
			result = ft_safe_strjoin(result, temp);
			free(temp);
			i += eov + 1;
		}
		else
		{
			temp = ft_substr(input, i, 1);
			result = ft_safe_strjoin(result, temp);
			free(temp);
			i++;
		}
		if (!result)
			return (NULL);
	}
	return (result);
}

/**
 * @brief Update double quote handler to include expansion
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @param shell Shell structure for expansion
 * @return int 0 on success, -1 on error
 */
int	ft_handle_double_quotes_with_expansion(char *input, int *pos, 
	t_token *token, t_shell *shell)
{
	int		start;
	int		end;
	int		len;
	char	*quoted_content;
	char	*expanded_content;

	start = *pos + 1; // Skip opening quote
	end = ft_find_closing_quote(input, start, '"');
	if (end == -1)
		return (-1); // Unclosed quote error
	len = end - start;
	quoted_content = ft_substr(input, start, len);
	if (!quoted_content)
		return (-1);
	
	// Expand variables inside double quotes
	expanded_content = ft_expand_in_double_quotes(shell, quoted_content);
	free(quoted_content);
	if (!expanded_content)
		return (-1);
	
	token->value = expanded_content;
	token->type = TOKEN_WORD;
	*pos = end + 1; // Move past closing quote
	return (0);
}
