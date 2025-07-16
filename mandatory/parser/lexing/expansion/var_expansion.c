/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:05:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:29:51 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Get variable name from input starting at position
 * 
 * @param input Input string
 * @param pos Starting position (after $)
 * @return char* Variable name, NULL on error
 */
static char	*ft_get_var_name(char *input, int pos)
{
	int		start;
	int		len;

	start = pos;
	while (input[pos] && (ft_isalnum(input[pos]) || input[pos] == '_'))
		pos++;
	len = pos - start;
	if (len == 0)
		return (NULL);
	return (ft_substr(input, start, len));
}

/**
 * @brief Expand a single variable using getenv
 * 
 * @param shell Shell structure
 * @param var_name Variable name to expand
 * @return char* Variable value, empty string if not found
 */
char	*ft_expand_variable(t_shell *shell, char *var_name)
{
	char	*env_value;

	if (!shell || !var_name)
		return (ft_strdup(""));
	
	// Try to get from environment using getenv (standard function)
	env_value = getenv(var_name);
	if (env_value)
		return (ft_strdup(env_value));
	
	// If not found, try local environment
	if (shell->env && shell->env->local_env)
	{
		env_value = ft_getenv_value(shell, var_name, 0, ft_strlen(var_name));
		if (env_value && *env_value)
			return (env_value);
		if (env_value)
			free(env_value);
	}
	
	// Return empty string if not found
	return (ft_strdup(""));
}

/**
 * @brief Process variable expansion in input string
 * 
 * @param shell Shell structure
 * @param input Input string with potential variables
 * @return char* String with variables expanded
 */
char	*ft_process_var_expansion(t_shell *shell, char *input)
{
	char	*result;
	char	*var_name;
	char	*var_value;
	char	*temp;
	int		i;
	int		var_len;

	if (!input)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] && 
			(ft_isalpha(input[i + 1]) || input[i + 1] == '_'))
		{
			var_name = ft_get_var_name(input, i + 1);
			if (var_name)
			{
				var_len = ft_strlen(var_name);
				var_value = ft_expand_variable(shell, var_name);
				temp = ft_strjoin(result, var_value);
				free(result);
				free(var_name);
				free(var_value);
				result = temp;
				i += var_len + 1; // Skip $ + variable name
			}
			else
			{
				temp = ft_strjoin(result, "$");
				free(result);
				result = temp;
				i++;
			}
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
