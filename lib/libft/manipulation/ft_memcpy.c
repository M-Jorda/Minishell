/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:54:29 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:29:03 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copies n bytes from the source memory area to the destination memory area.
 * 
 * @param dest The destination memory area.
 * @param src The source memory area to copy from.
 * @param n The number of bytes to copy.
 * @return The destination memory area.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tab;
	unsigned char	*src_tab;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_tab = (unsigned char *) dest;
	src_tab = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dest_tab[i] = src_tab[i];
		i++;
	}
	return (dest);
}
