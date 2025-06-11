/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:24:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"
#include <dirent.h>
#include <sys/stat.h>

/**
 * @brief Matches a string against a pattern with wildcards
 * 
 * @param pattern Pattern with potential wildcards
 * @param string String to match
 * @return bool true if matches, false otherwise
 */
bool	ft_match_pattern(const char *pattern, const char *string)
{
	char	*p;
	char	*s;
	char	*star_p;
	char	*star_s;

	p = (char *) pattern;
	s = (char *) string;
	star_p = NULL;
	star_s = NULL;
	while (*s)
	{
		if (*p == '*')
		{
			star_p = p++;
			star_s = s;
		}
		else if (*p == *s)
		{
			p++;
			s++;
		}
		else if (star_p)
			ft_reset_pattern_match(&p, &s, star_p, &star_s);
		else
			return (false);
	}
	return (ft_check_remaining_pattern(p));
}

/**
 * @brief Resets pattern matching after failed match
 * 
 * @param p Pointer to current pattern position
 * @param s Pointer to current string position
 * @param star_p Pattern position after last star
 * @param star_s Pointer to string position after last star
 */
void	ft_reset_pattern_match(const char **p, const char **s,
			const char *star_p, const char **star_s)
{
	*p = star_p + 1;
	*s = ++(*star_s);
}

/**
 * @brief Checks remaining pattern after string is consumed
 * 
 * @param p Pattern position
 * @return bool true if pattern is valid, false otherwise
 */
bool	ft_check_remaining_pattern(const char *p)
{
	while (*p == '*')
		p++;
	return (*p == '\0');
}

/**
 * @brief Checks if filename should be hidden (starts with .)
 * 
 * @param filename The filename to check
 * @param pattern The pattern being matched
 * @return bool true if should show hidden files, false otherwise
 */
bool	ft_should_show_hidden(const char *filename, const char *pattern)
{
	if (filename[0] != '.')
		return (true);
	if (pattern[0] == '.')
		return (true);
	return (false);
}

/**
 * @brief Sorts an array of strings alphabetically
 * 
 * @param arr Array to sort
 * @param size Size of the array
 */
void	ft_sort_matches(char **arr, int size)
{
	int		i;
	int		j;
	char	*temp;

	if (!arr || size <= 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
