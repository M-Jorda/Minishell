/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:59:27 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/16 18:58:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_reverse(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	ft_printf("%d, %d\n", j, i / 2);
	while (j < (i / 2))
	{
		ft_printf("%c, %d\n", temp[++j], j);
		ft_printf("%c, %d\n", temp[i], i);
		temp[j] = str[j];
		str[i--] = str[j];
	}
	i = ft_strlen(str);
	j = -1;
	ft_printf("%d, %d\n", j, i / 2);
	while (j < (i / 2))
	{
		str[++j] = temp[j];
	}
	return (str);
}
