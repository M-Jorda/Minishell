/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:04:01 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/11 12:07:37 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Creates a new token with expanded variable value
 * 
 * @param value The variable value
 * @return t_token* New token structure, NULL on error
 */
t_token	*ft_create_var_token(char *value)
{
	t_token	*token;

	if (!value)
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	token->type = TOKEN_WORD;
	return (token);
}

/**
 * @brief Checks if a key is valid for environment variables
 * 
 * @param key The key to check
 * @return bool true if valid, false otherwise
 */
bool	ft_is_valid_env_key(const char *key)
{
	int	i;

	if (!key || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (false);
	i = 0;
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (false);
	}
	return (true);
}

/**
 * @brief Replaces a variable name with its value in a string
 * 
 * @param original Original string
 * @param var_pos Position of the variable in the string
 * @param var_len Length of the variable name
 * @param replacement Value to replace the variable with
 * @return char* New string with the variable replaced, NULL on error
 */
char	*ft_replace_var(char *original, int var_pos, int var_len,
			char *replacement)
{
	char	*new_str;
	int		orig_len;
	int		repl_len;
	int		i;
	int		j;

	if (!original || var_pos < 0 || var_len < 0 || !replacement)
		return (NULL);
	orig_len = ft_strlen(original);
	repl_len = ft_strlen(replacement);
	new_str = (char *)malloc(sizeof(char)
			* (orig_len - var_len - 1 + repl_len + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < var_pos)
		new_str[i] = original[i];
	j = -1;
	while (++j < repl_len)
		new_str[i + j] = replacement[j];
	j = -1;
	while (var_pos + var_len + 1 + ++j < orig_len)
		new_str[i + repl_len + j] = original[var_pos + var_len + 1 + j];
	new_str[i + repl_len + j] = '\0';
	return (new_str);
}

/**
 * @brief Extracts a variable name from a string
 *
 * @param str The string containing the variable
 * @param pos Position of the variable in the string
 * @return char* The variable name, NULL on error
 */
char	*ft_extract_var_name(char *str, int pos)
{
	int		len;
	char	*name;

	if (!str || pos < 0)
		return (NULL);
	len = 0;
	while (str[pos + len]
		&& (ft_isalnum(str[pos + len]) || str[pos + len] == '_'))
		len++;
	name = ft_substr(str, pos, len);
	return (name);
}

/**
 * @brief Searches for a variable in the environment
 *
 * @param env_vars Array of environment variables
 * @param key The variable key to search for
 * @return char* The variable value, NULL if not found
 */
char	*ft_find_env_var(char **env_vars, const char *key)
{
	int		i;
	int		key_len;

	if (!env_vars || !key)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (env_vars[i])
	{
		if (ft_strncmp(env_vars[i], key, key_len) == 0
			&& env_vars[i][key_len] == '=')
			return (env_vars[i] + key_len + 1);
		i++;
	}
	return (NULL);
}
