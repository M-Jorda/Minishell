/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:49:49 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Compares the first n bytes of the strings s1 and s2.
 * 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tab_s1;
	unsigned char	*tab_s2;
	size_t			i;

	tab_s1 = (unsigned char *) s1;
	tab_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = -1;
	while (++i < n && ((*tab_s1 && *tab_s2)) && (*tab_s1 == *tab_s2))
	{
		tab_s1++;
		tab_s2++;
	}
	return (*tab_s1 - *tab_s2);
}
