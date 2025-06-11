/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:15:08 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:24:52 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Trims the characters from the start and end of the string s1 that are in the
 * set of characters specified by set.
 * 
 * @param s1 The string to trim.
 * @param set The set of characters to remove from the start and end of s1.
 * @return A new string with the trimmed content, or NULL if malloc fails.
 * 
 * Note: Memory for the new string is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_substr(s1, start, end - start);
	if (!str)
		return ((char *) ft_mallocfailed("ft_strtrim"));
	return (str);
}
