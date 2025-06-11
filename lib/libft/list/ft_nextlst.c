/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:38:11 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:42:12 by jjorda           ###   ########.fr       */
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
t_list	*ft_nextlst(t_list *head, int i)
{
	t_list	*current;
	int		j;

	if (!head)
		return (NULL);
	current = head;
	j = -1;
	while (++j < i && current)
	{
		if (!current->content)
			break ;
		current = current->next;
	}
	if (j < i)
		return (NULL);
	return (current);
}
