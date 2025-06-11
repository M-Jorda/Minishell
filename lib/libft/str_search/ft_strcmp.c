/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:49:49 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:34:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compares the strings s1 and s2 lexicographically.
 * 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*tab_s1;
	unsigned char	*tab_s2;

	tab_s1 = (unsigned char *) s1;
	tab_s2 = (unsigned char *) s2;
	while ((*tab_s1 && *tab_s2) && (*tab_s1 == *tab_s2))
	{
		tab_s1++;
		tab_s2++;
	}
	return ((char) *tab_s1 - (char) *tab_s2);
}
