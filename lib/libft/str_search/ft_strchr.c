/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:49:09 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:12 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Searches for the first occurrence of the character c in the string s.
 *
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the first occurrence of c in s, or NULL if c is not
 * found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c > 255)
		c %= 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
