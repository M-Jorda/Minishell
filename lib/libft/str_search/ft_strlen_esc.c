/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:24:34 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 13:18:14 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * This function is called within `ft_strlen_esc` to handle cases where an
 * escape sequence is encountered. It adjusts the length and index accordingly.
 *
 * @param s The input string.
 * @param i Pointer to the current index in the string.
 * @param length Pointer to the current calculated length of the string.
 */
static void	ft_loop(const char *s, size_t *i, size_t *length)
{
	if (s[*i + 1] == ' ' && ft_isesc(s[*i + 2]))
	{
		*length += 3;
		*i += 2;
	}
}

/**
 * This function calculates the length of the string pointed to by `s`,
 * excluding the terminating null byte ('\0'). It accounts for escape sequences
 * and adjusts the length accordingly.
 *
 * @param s The input string.
 * @return The length of the string excluding the terminating null byte.
 */
size_t	ft_strlen_esc(const char *s)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = 0;
	while (s[i])
	{
		if (!ft_isesc(s[i]))
			length++;
		else if (s[i] == '\'' || s[i] == '"')
			ft_loop(s, &i, &length);
		i++;
	}
	return (length);
}
