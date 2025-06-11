/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vctr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:49:34 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/07 14:55:45 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_vctr(void **ptr)
{
	int	i;

	if (!ptr || !ptr[0])
		return ;
	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	ptr = NULL;
}
