/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:54:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:22:22 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Builds token list from array of matches
 * 
 * @param matches Array of matched filenames
 * @param count Number of matches
 * @param token_list Pointer to token list
 * @return bool true on success, false on error
 */
bool	ft_build_token_list(char **matches, int count, t_list **token_list)
{
	t_token	*token;
	int		i;

	i = 0;
	while (i < count)
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			return (false);
		token->type = TOKEN_WORD;
		token->value = ft_strdup(matches[i]);
		if (!token->value)
		{
			free(token);
			return (false);
		}
		if (!ft_lstadd_back(token_list, (t_content){.token = token}, TYPE_TOKEN))
		{
			free(token->value);
			free(token);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Creates a single token from a filename
 * 
 * @param filename Filename to create token from
 * @return t_token* New token, NULL on error
 */
t_token	*ft_create_filename_token(char *filename)
{
	t_token	*token;

	if (!filename)
		return (NULL);
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = TOKEN_WORD;
	token->value = ft_strdup(filename);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

/**
 * @brief Validates a token for wildcard processing
 * 
 * @param token Token to validate
 * @return bool true if valid, false otherwise
 */
bool	ft_validate_token(t_token *token)
{
	if (!token)
		return (false);
	if (!token->value)
		return (false);
	if (token->type != TOKEN_WORD && token->type != TOKEN_WILDCARD)
		return (false);
	return (true);
}

/**
 * @brief Checks if a filename is valid for expansion
 * 
 * @param filename Filename to check
 * @return bool true if valid, false otherwise
 */
bool	ft_is_valid_filename(const char *filename)
{
	if (!filename)
		return (false);
	if (filename[0] == '\0')
		return (false);
	if (ft_strcmp(filename, ".") == 0)
		return (false);
	if (ft_strcmp(filename, "..") == 0)
		return (false);
	return (true);
}

/**
 * @brief Cleans up after failed token creation
 * 
 * @param token Token to clean up
 * @param matches Array of matches to free
 */
void	ft_cleanup_failed_token(t_token *token, char **matches)
{
	if (token)
	{
		if (token->value)
			free(token->value);
		free(token);
	}
	if (matches)
		ft_free_arr(matches);
}
