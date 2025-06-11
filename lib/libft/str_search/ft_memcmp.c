/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:29 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:09 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Compares the first n bytes of the memory areas s1 and s2.
 *
 * @param s1 The first memory area to compare.
 * @param s2 The second memory area to compare.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first n
 * bytes of s1 are found, respectively, to be less than, to match, or be greater
 * than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tab_s1;
	unsigned char	*tab_s2;

	if (n == 0)
		return (0);
	tab_s1 = (unsigned char *)s1;
	tab_s2 = (unsigned char *)s2;
	while (--n && ((*tab_s1 && *tab_s2) || *tab_s2 + 1) && (*tab_s1 == *tab_s2))
	{
		tab_s1++;
		tab_s2++;
	}
	return ((unsigned char)*tab_s1 - *tab_s2);
}
