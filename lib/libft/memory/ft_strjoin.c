/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:37:30 by jjorda            #+#    #+#             */
/*   Updated: 2024/10/08 13:16:27 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strmalloc(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!len_s1 && !len_s2)
		return (malloc(1));
	str = (char *) malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return ((char *) ft_mallocfailed("ft_strjoin"));
	return (str);
}

/**
 * Joins two strings into a new string by allocating memory and concatenating
 * them.
 * 
 * @param s1 The first string to join.
 * @param s2 The second string to join.
 * @return A new string containing the concatenation of s1 and s2, or NULL if
 * malloc fails.
 * 
 * Note: Memory for the new string is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = ft_strmalloc(s1, s2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
