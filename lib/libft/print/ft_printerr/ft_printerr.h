/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:58:22 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 16:00:50 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERR_H
# define FT_PRINTERR_H

/* -------------------------------- INCLUDE --------------------------------- */

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../../libft.h"

/* --------------------------------- PRINTF --------------------------------- */

int		ft_printerr(const char *arg, ...);

/* ------------------------------ PRINTF_UTILS ------------------------------ */

void	ft_pterr_putchar(char c, int *count);
void	ft_pterr_putnbr(long n, int *count);
void	ft_pterr_putstr(char *s, int *count);
void	ft_pterr_puthexdec(unsigned long num, char format, int *count, int ptr);
void	ft_pterr_putptr(void *ptr, int *count);

#endif