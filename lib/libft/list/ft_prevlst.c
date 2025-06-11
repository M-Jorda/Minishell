/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prevlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:05:21 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:42:15 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Returns the nth element of the linked list.
 * 
 * @param head The first element of the linked list.
 * @param i The index of the element to return.
 * @return The nth element of the list, or NULL if the index is out of bounds.
 */
t_list	*ft_prevlst(t_list *actual, int i)
{
	t_list	*current;
	int		j;

	if (!actual)
		return (NULL);
	current = actual;
	j = -1;
	while (++j < i && current)
	{
		if (!current)
			break ;
		current = current->prev;
	}
	if (j < i)
		return (NULL);
	return (current);
}