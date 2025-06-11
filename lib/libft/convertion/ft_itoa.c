/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:53:34 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/06 11:33:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_countnbr(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_itoa_recursive(char *num, long n, int len)
{
	while (n > 0)
	{
		num[--len] = (n % 10) + '0';
		n /= 10;
	}
}

/**
 * Converts an integer to its string representation.
 *
 * @param n The integer to convert.
 * @return A string representing the integer, or NULL if malloc fails.
 *
 * Note: Memory for the string is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	long_n;

	long_n = (long)n;
	len = ft_countnbr(long_n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (long_n < 0)
	{
		num[0] = '-';
		long_n *= -1;
	}
	else if (n == 0)
		num[0] = '0';
	ft_itoa_recursive(&num[0], long_n, len);
	return (num);
}
