/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:54:29 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:29:10 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_memmoveloop(
	unsigned char *dest,
	unsigned char *src,
	size_t n,
	int boolean)
{
	size_t	i;

	if (boolean)
	{
		i = n;
		while (i > 0)
		{
			dest[i - 1] = src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
}

/**
 * Moves n bytes from the source memory area to the destination memory area,
 * handling overlapping regions safely.
 * 
 * @param dest The destination memory area.
 * @param src The source memory area to move from.
 * @param n The number of bytes to move.
 * @return The destination memory area.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tab;
	unsigned char	*src_tab;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_tab = (unsigned char *) dest;
	src_tab = (unsigned char *) src;
	if (dest_tab > src_tab && dest_tab < src_tab + n)
		ft_memmoveloop(dest_tab, src_tab, n, 1);
	else
		ft_memmoveloop(dest_tab, src_tab, n, 0);
	return (dest);
}
