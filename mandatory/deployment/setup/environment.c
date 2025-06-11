/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:56:49 by alearroy          #+#    #+#             */
/*   Updated: 2025/06/11 11:21:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Duplicates environment variables array
 * 
 * @param envp Original environment variables
 * @return char** Duplicated environment array, NULL on error
 */
char	**ft_envdup(char **envp)
{
	char	**new_env;
	int		env_count;
	int		i;

	if (!envp)
		return (NULL);
	
	// Count environment variables
	env_count = 0;
	while (envp[env_count])
		env_count++;
	
	// Allocate memory for new environment array
	new_env = (char **)malloc(sizeof(char *) * (env_count + 1));
	if (!new_env)
		return (NULL);
	
	// Duplicate each environment variable
	i = 0;
	while (i < env_count)
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
		{
			// Free previously allocated strings on error
			while (--i >= 0)
				free(new_env[i]);
			free(new_env);
			return (NULL);
		}
		i++;
	}
	new_env[env_count] = NULL;
	
	return (new_env);
}

/**
 * @brief Helper function to join three strings
 * 
 * @param s1 First string
 * @param s2 Second string
 * @param s3 Third string
 * @return char* Joined string, NULL on error
 */
char	*ft_strjoin_three(const char *s1, const char *s2, const char *s3)
{
	char	*temp;
	char	*result;

	if (!s1 || !s2 || !s3)
		return (NULL);
	
	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	
	result = ft_strjoin(temp, s3);
	free(temp);
	
	return (result);
}

/**
 * @brief Updates or adds an environment variable
 * 
 * @param env Pointer to environment array
 * @param key Variable key
 * @param value Variable value
 * @return int 0 on success, -1 on error
 */
int	update_env_var(char ***env, const char *key, const char *value)
{
	int		i;
	int		key_len;
	char	*new_var;
	char	**new_env;

	if (!env || !*env || !key)
		return (-1);
	
	key_len = ft_strlen(key);
	
	// Look for existing variable
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], key, key_len) == 0 && (*env)[i][key_len] == '=')
		{
			// Update existing variable
			new_var = ft_strjoin_three(key, "=", value ? value : "");
			if (!new_var)
				return (-1);
			free((*env)[i]);
			(*env)[i] = new_var;
			return (0);
		}
		i++;
	}
	
	// Add new variable
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (-1);
	
	// Copy existing variables
	int j = 0;
	while (j < i)
	{
		new_env[j] = (*env)[j];
		j++;
	}
	
	// Add new variable
	new_var = ft_strjoin_three(key, "=", value ? value : "");
	if (!new_var)
	{
		free(new_env);
		return (-1);
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	
	free(*env);
	*env = new_env;
	return (0);
}
