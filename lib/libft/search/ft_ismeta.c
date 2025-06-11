/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:26:46 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/11 18:28:55 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_ismeta(char *meta, char c)
{
	if (!meta)
		return (false);
	while (*meta)
	{
		if (c == *meta)
			return (true);
		meta++;
	}
	return (false);
}