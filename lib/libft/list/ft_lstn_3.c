/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstn_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:34:55 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:41:52 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Returns the element n-3 of the linked list.
 * 
 * @param lst The first element of the linked list.
 * @return The element n-3 of the list, or NULL if the list is empty.
 */
t_list	*ft_lstn_3(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next->next)
		lst = lst->next;
	return (lst);
}
