/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:03:31 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 16:27:28 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printerr.h"

/*
* Outputs on the stderr the character ’c’.
*/
void	ft_pterr_putchar(char c, int *count)
{
	write(2, &c, 1);
	*count += 1;
}

/*
* Outputs the integer ’n’.
*/
void	ft_pterr_putnbr(long n, int *count)
{
	if (n == -2147483648)
	{
		ft_pterr_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_pterr_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_pterr_putnbr(n / 10, count);
	ft_pterr_putchar((n % 10) + '0', count);
}

/*
* Outputs the string ’s’.
*/
void	ft_pterr_putstr(char *s, int *count)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s)
	{
		ft_pterr_putstr("(null)", count);
		return ;
	}
	size = 0;
	while (s[size])
		size++;
	str = ft_strdup(s);
	if (!str)
		return ;
	i = 0;
	while (i < size)
	{
		ft_pterr_putchar(str[i], count);
		i++;
	}
	free(str);
}

/*
* Outputs the pointer of ’p’.
*/
void	ft_pterr_puthexdec(unsigned long num, char format, int *count, int ptr)
{
	char	*base;
	int		i;
	int		n[32];

	if (ptr == 0)
		num = (unsigned int) num;
	if (num == 0)
	{
		ft_pterr_putchar('0', count);
		return ;
	}
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	while (num)
	{
		n[i] = num % 16;
		num /= 16;
		i++;
	}
	while (--i >= 0)
		ft_pterr_putchar(base[n[i]], count);
}

void	ft_pterr_putptr(void *ptr, int *count)
{
	if (ptr == NULL)
	{
		ft_pterr_putstr("(nil)", count);
		return ;
	}
	ft_pterr_putstr("0x", count);
	ft_pterr_puthexdec((unsigned long) ptr, 'x', count, 1);
}
