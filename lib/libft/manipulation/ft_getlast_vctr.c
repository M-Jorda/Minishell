/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlast_vctr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:44:04 by jjorda            #+#    #+#             */
/*   Updated: 2025/02/19 20:18:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getlast_vctr(char **vctr)
{
	char	*last;
	int		i;

	if (!vctr)
		return (NULL);
	i = -1;
	while (vctr[++i])
		last = vctr[i];
	return (last);
}
