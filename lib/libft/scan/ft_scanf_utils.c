/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:18:31 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/16 18:49:43 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

void	ft_readchar(char *c, t_scan *scan)
{
	int	i;

	i = scan->word;
	*c = scan->split[i++][0];
	scan->count++;
}

void	ft_readstr(char **str, t_scan *scan)
{
	int	i;

	i = scan->word;
	*str = scan->split[i++];
	scan->count += ft_strlen(*str);
}

void	ft_readnbr(int *nbr, t_scan *scan)
{
	int	i;

	i = scan->word;
	*nbr = ft_atoi(scan->split[i++]);
	scan->count += ft_countdigit((long long)*nbr);
}

void	ft_readhexdec(unsigned int *num, char format, t_scan *scan)
{
	char	*base;
	int		i;
	int		j;
	int		n[32];

	i = scan->word;
	j = 0;
	if (scan->split[i][j] == '0')
		n[0] = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
}
