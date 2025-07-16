/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:10:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:30:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Get exit code as string
 * 
 * @param shell Shell structure
 * @return char* Exit code as string, NULL on error
 */
char	*ft_expand_exit_code(t_shell *shell)
{
	if (!shell || !shell->env)
		return (ft_strdup("0"));
	return (ft_itoa(shell->env->last_exit_code));
}

/**
 * @brief Process $? expansion in input string
 * 
 * @param shell Shell structure
 * @param input Input string with potential $?
 * @return char* String with $? expanded
 */
char	*ft_process_exit_code_expansion(t_shell *shell, char *input)
{
	char	*result;
	char	*exit_code_str;
	char	*temp;
	int		i;

	if (!input)
		return (NULL);
	
	// If no $? in string, return copy
	if (!ft_strstr(input, "$?"))
		return (ft_strdup(input));
	
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			exit_code_str = ft_expand_exit_code(shell);
			temp = ft_strjoin(result, exit_code_str);
			free(result);
			free(exit_code_str);
			result = temp;
			i += 2; // Skip $?
		}
		else
		{
			temp = ft_substr(input, i, 1);
			if (temp)
			{
				result = ft_strjoin_f(result, temp);
				free(temp);
			}
			i++;
		}
		if (!result)
			return (NULL);
	}
	return (result);
}
