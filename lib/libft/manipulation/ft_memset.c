/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:20:21 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:29:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Fills the first n bytes of the memory area pointed to by s with the byte
 * value c.
 * 
 * @param s The memory area to fill.
 * @param c The byte value to set.
 * @param n The number of bytes to set.
 * @return The pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	tab = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		tab[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
