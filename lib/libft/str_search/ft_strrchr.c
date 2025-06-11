/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:20:44 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Searches for the last occurrence of the character c in the string s.
 * 
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the last occurrence of c in s, or NULL if c is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	if (c > 255)
		c %= 256;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *) &s[j]);
	if (c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
