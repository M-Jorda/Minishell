/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:03:31 by jjorda            #+#    #+#             */
/*   Updated: 2024/10/27 11:03:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Outputs the character ’c’.
*/
void	ft_pt_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

/*
* Outputs the integer ’n’.
*/
void	ft_pt_putnbr(long n, int *count)
{
	if (n == -2147483648)
	{
		ft_pt_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_pt_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_pt_putnbr(n / 10, count);
	ft_pt_putchar((n % 10) + '0', count);
}

/*
* Outputs the string ’s’.
*/
void	ft_pt_putstr(char *s, int *count)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s)
	{
		ft_pt_putstr("(null)", count);
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
		ft_pt_putchar(str[i], count);
		i++;
	}
	free(str);
}

/*
* Outputs the pointer of ’p’.
*/
void	ft_puthexadecimal(unsigned long num, char format, int *count, int ptr)
{
	char	*base;
	int		i;
	int		n[32];

	if (ptr == 0)
		num = (unsigned int) num;
	if (num == 0)
	{
		ft_pt_putchar('0', count);
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
		ft_pt_putchar(base[n[i]], count);
}

void	ft_pt_putptr(void *ptr, int *count)
{
	if (ptr == NULL)
	{
		ft_pt_putstr("(nil)", count);
		return ;
	}
	ft_pt_putstr("0x", count);
	ft_puthexadecimal((unsigned long) ptr, 'x', count, 1);
}
