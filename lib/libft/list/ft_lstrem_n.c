/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:12:07 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:42:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Removes a node at a specified index from a doubly linked list.
 * 
 * @param head A pointer to the pointer of the head of the list.
 * @param index The index of the node to be removed (0-based).
 * @param f A function pointer to a function that processes the node to be removed.
 *          This function is expected to handle any cleanup or deallocation for the node.
 * 
 * @return true if the node was successfully removed, false otherwise.
 * 
 * @note The function assumes the list is doubly linked, with each node having
 *       both `next` and `prev` pointers. The `f` function is expected to handle
 *       the cleanup of the node being removed. The function will return false
 *       if the `head` pointer is NULL, the `index` is negative, or the `f` function
 *       pointer is not NULL (indicating an invalid function pointer).
 */
bool	ft_lstrem_n(t_list **head, int index, void *(*f)(t_list *))
{
	t_list	*prev;
	t_list	*next;
	t_list	*del;
	int		i;

	if (!head || !(*head) || i < 0 || f)
		return (false);
	prev = *head;
	i = -1;
	while (i < index - 1 && prev)
		prev = prev->next;
	if (!prev)
		return (false);
	del = prev->next;
	next = del->next;
	f(del);
	prev->next = next;
	next->prev = prev;
	return (true);
}