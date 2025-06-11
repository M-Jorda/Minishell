/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:52:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:25:09 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"
#include <dirent.h>
#include <sys/stat.h>

/**
 * @brief Gets all files matching a pattern in current directory
 * 
 * @param pattern Pattern to match
 * @return char** Array of matching filenames, NULL on error
 */
char	**ft_get_matching_files(const char *pattern)
{
	DIR		*dir;
	char	**matches;
	int		count;
	int		capacity;

	dir = opendir(".");
	if (!dir)
		return (NULL);
	capacity = 16;
	matches = (char **)malloc(sizeof(char *) * capacity);
	if (!matches)
	{
		closedir(dir);
		return (NULL);
	}
	count = ft_collect_matches(dir, pattern, matches, &capacity);
	closedir(dir);
	if (count == 0)
	{
		free(matches);
		return (NULL);
	}
	matches[count] = NULL;
	return (matches);
}

/**
 * @brief Collects matching files from directory
 * 
 * @param dir Directory pointer
 * @param pattern Pattern to match
 * @param matches Array to store matches
 * @param capacity Pointer to array capacity
 * @return int Number of matches found
 */
int	ft_collect_matches(DIR *dir, const char *pattern, char **matches,
		int *capacity)
{
	struct dirent	*entry;
	int				count;

	count = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (!ft_should_show_hidden(entry->d_name, pattern))
			continue ;
		if (ft_match_pattern(pattern, entry->d_name))
		{
			if (!ft_add_match_to_array(matches, &count, capacity, entry->d_name))
				break ;
		}
		entry = readdir(dir);
	}
	return (count);
}

/**
 * @brief Adds a match to the matches array
 * 
 * @param matches Array of matches
 * @param count Pointer to current count
 * @param capacity Pointer to array capacity
 * @param filename Filename to add
 * @return bool true on success, false on error
 */
bool	ft_add_match_to_array(char **matches, int *count, int *capacity,
		char *filename)
{
	char	**new_matches;

	if (*count >= *capacity - 1)
	{
		*capacity *= 2;
		new_matches = ft_realloc(matches, sizeof(char *) * (*capacity),
				sizeof(char *) * (*capacity / 2));
		if (!new_matches)
			return (false);
		matches = new_matches;
	}
	matches[*count] = ft_strdup(filename);
	if (!matches[*count])
		return (false);
	(*count)++;
	return (true);
}

/**
 * @brief Connects new tokens to the existing token list
 * 
 * @param tok_h Pointer to token list head
 * @param tok_curr Current token to replace
 * @param new_tokens New tokens to insert
 * @return bool true on success, false on error
 */
bool	ft_connect_new_tokens(t_list **tok_h, t_list *tok_curr, t_list *new_tokens)
{
	t_list	*last_new;

	last_new = ft_lstlast(new_tokens);
	new_tokens->prev = tok_curr->prev;
	if (tok_curr->prev)
		tok_curr->prev->next = new_tokens;
	else
		*tok_h = new_tokens;
	last_new->next = tok_curr->next;
	if (tok_curr->next)
		tok_curr->next->prev = last_new;
	ft_clean_node_tok(tok_curr);
	return (true);
}

/**
 * @brief Creates new tokens from matched filenames
 * 
 * @param matches Array of matched filenames
 * @return t_list* List of new tokens, NULL on error
 */
t_list	*ft_create_match_tokens(char **matches)
{
	t_list	*token_list;
	int		count;

	if (!matches)
		return (NULL);
	count = ft_count_arr(matches);
	if (count == 0)
		return (NULL);
	ft_sort_matches(matches, count);
	token_list = NULL;
	if (!ft_build_token_list(matches, count, &token_list))
	{
		ft_lstfree_t(token_list);
		return (NULL);
	}
	return (token_list);
}
