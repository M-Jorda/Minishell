/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:40:21 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Searches for the first occurrence of the character c in the first n bytes of
 * the memory area pointed to by s.
 * 
 * @param s The memory area to search.
 * @param c The character to find.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of c in s, or NULL if c is not
 * found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	tab = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (tab[i] == (unsigned char) c)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
