/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:43:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:41:27 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstfirst(t_list *actual)
{
	t_list	*prev;

	if (!actual)
		return (NULL);
	prev = actual;
	while (prev->prev)
		prev = prev->prev;
	return (prev);
}
