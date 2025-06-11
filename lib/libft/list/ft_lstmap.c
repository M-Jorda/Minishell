/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:18:57 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:20:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Creates a new linked list by applying the function f to each element of the
 * original list.
 * 
 * @param lst The original linked list to map over.
 * @param f The function to apply to each element's content.
 * @param del The function to delete the content of a node in case of an
 * allocation failure.
 * @return A new linked list with the transformed content, or NULL if malloc
 * fails.
 * 
 * Note: Memory for each new node is allocated using malloc(). 
 *       If malloc fails, the function clears the new list using del and returns
 * NULL.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*head;

	head = NULL;
	while (lst)
	{
		current = ft_lstnew(lst->content);
		if (!current)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		current->content = f(lst->content);
		ft_lstadd_back(&head, current);
		lst = lst->next;
	}
	return (head);
}
