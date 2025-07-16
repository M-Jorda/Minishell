/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:20:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:30:51 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Check if expansion should occur in current context
 * 
 * @param token Token to check
 * @param in_single_quotes Whether we're in single quotes
 * @return bool true if should expand, false otherwise
 */
bool	ft_should_expand(t_token *token, bool in_single_quotes)
{
	if (!token || !token->value)
		return (false);
	
	// No expansion in single quotes
	if (in_single_quotes)
		return (false);
	
	// Only expand TOKEN_WORD tokens
	if (token->type != TOKEN_WORD)
		return (false);
	
	return (true);
}

/**
 * @brief Check if string contains expandable variables
 * 
 * @param str String to check
 * @return bool true if contains variables, false otherwise
 */
bool	ft_contains_variables(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (str[i + 1] == '?' || ft_isalpha(str[i + 1]) || str[i + 1] == '_')
				return (true);
		}
		i++;
	}
	return (false);
}

/**
 * @brief Safe string join that handles memory properly
 * 
 * @param s1 First string (will be freed if not NULL)
 * @param s2 Second string (will NOT be freed)
 * @return char* Joined string, NULL on error
 */
char	*ft_safe_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

/**
 * @brief Validate variable name
 * 
 * @param var_name Variable name to validate
 * @return bool true if valid, false otherwise
 */
bool	ft_is_valid_var_name(char *var_name)
{
	int	i;

	if (!var_name || !var_name[0])
		return (false);
	
	// First character must be letter or underscore
	if (!ft_isalpha(var_name[0]) && var_name[0] != '_')
		return (false);
	
	// Rest must be alphanumeric or underscore
	i = 1;
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Find substring in string (helper function)
 * 
 * @param haystack String to search in
 * @param needle String to search for
 * @return char* Pointer to first occurrence, NULL if not found
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;
	size_t	i;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	
	needle_len = ft_strlen(needle);
	i = 0;
	while (haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
