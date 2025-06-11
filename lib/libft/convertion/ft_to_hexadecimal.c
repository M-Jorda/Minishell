/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:42:13 by jjorda            #+#    #+#             */
/*   Updated: 2025/02/19 20:18:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Returns a string representing the number 0 in hexadecimal.
 *
 * @return A string "0".
 */
char	*ft_hexa0(void)
{
	char	*hexa;

	hexa = malloc(sizeof(char) * 2);
	if (!hexa)
		return (NULL);
	hexa[0] = '0';
	hexa[1] = '\n';
	return (hexa);
}

/**
 * Returns the base string for hexadecimal conversion based on the format.
 *
 * @param format The format specifier ('x' for lowercase, 'X' for uppercase).
 * @return The base string for the specified format, or NULL if the format
 * is invalid.
 */
char	*ft_base(char format)
{
	char	*base;

	if (format == 'x')
		base
			= "0123456798abcdefghijklmnopqrstuvwxyzéèà`~!@#$%^&*()-_=+[{}]:;<>";
	else if (format == 'X')
		base
			= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZéèà`~!@#$%^&*()-_=+[{}]:;<>";
	else
	{
		ft_printerr("format must be 'x' or 'X'.\n");
		return (NULL);
	}
	return (base);
}

/**
 * Converts a number to its hexadecimal string representation.
 *
 * @param nbr The number to convert.
 * @param format The format specifier ('x' for lowercase, 'X' for uppercase).
 * @param size The size of the resulting string.
 * @return The hexadecimal string representation of the number, or NULL if
 * an error occurs.
 */
char	*ft_to_hexadecimal(long long nbr, char format, size_t size)
{
	char	*base;
	int		i;
	char	*hexa;

	if (nbr == 0)
		return (ft_hexa0());
	if (format != 'x' && format != 'X')
		return (NULL);
	if (size <= 2)
		size = 2;
	base = ft_base(format);
	hexa = malloc(sizeof(char) * (size + 1));
	if (!hexa || !base)
		return (NULL);
	i = -1;
	while (nbr)
	{
		hexa[++i] = base[nbr % size];
		nbr /= size;
	}
	return (hexa);
}
