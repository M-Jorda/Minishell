/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:03:17 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/07 15:44:57 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_posneg(const char *nptr, int i)
{
	if (nptr[i] == 43)
		return (0);
	return (1);
}

/**
 * Converts a string to an integer, handling optional whitespace and signs.
 * 
 * @param str The string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	neg = 0;
	if (str[i] == 92)
		return (result);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		neg = ft_posneg(str, i);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (neg == 1)
		result *= -1;
	return (result);
}
