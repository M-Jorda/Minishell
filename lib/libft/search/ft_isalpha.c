/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:57:58 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:27:22 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Checks if the given character is an uppercase letter.
 * 
 * @param c The character to check.
 * @return 1 if the character is uppercase, 0 otherwise.
 */
static int	ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

/**
 * Checks if the given character is a lowercase letter.
 * 
 * @param c The character to check.
 * @return 1 if the character is lowercase, 0 otherwise.
 */
static int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

/**
 * Checks if the given character is an alphabetic letter (either lowercase or
 * uppercase).
 * 
 * @param c The character to check.
 * @return 1024 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if (ft_islower(c) == 1 || ft_isupper(c) == 1)
		return (1024);
	return (0);
}
