/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:22:02 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/06 11:42:37 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copies up to n characters from the source string to the destination string.
 * 
 * @param dest The destination string.
 * @param src The source string.
 * @param n The maximum number of characters to copy.
 * @return The destination string with the copied characters.
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (!src || n == 0)
		return (NULL);
	i = 0;
	while (src[i++] || i < n)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
