/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:58:22 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/08 09:06:25 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* -------------------------------- INCLUDE --------------------------------- */

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../../libft.h"

/* --------------------------------- PRINTF --------------------------------- */

int		ft_printf(const char *arg, ...);

/* ------------------------------ PRINTF_UTILS ------------------------------ */

void	ft_pt_putchar(char c, int *count);
void	ft_pt_putnbr(long n, int *count);
void	ft_pt_putstr(char *s, int *count);
void	ft_puthexadecimal(unsigned long num, char format, int *count, int ptr);
void	ft_pt_putptr(void *ptr, int *count);

#endif