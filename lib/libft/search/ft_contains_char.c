/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:06:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/02/19 20:18:20 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Checks if a given character is present in a string.
 *
 * This function iterates through the given string to check if the specified
 * character is present. If the character is found, the function returns 1.
 * Otherwise, it returns 0.
 *
 * @param str The string to be searched.
 * @param c The character to search for.
 * @return int Returns 1 if the character is found, otherwise returns 0.
 */
int	ft_contains_char(char *str, char c)
{
	if (!(*str))
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
