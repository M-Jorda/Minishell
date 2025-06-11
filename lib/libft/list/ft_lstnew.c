/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:33:46 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:21:47 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Creates a new linked list node with the given content.
 * 
 * @param content The content to store in the new node.
 * @return A pointer to the new node, or NULL if malloc fails.
 * 
 * Note: Memory for the new node is allocated using malloc(). 
 *       If malloc fails, the function returns NULL.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content.generic = content;
	new_node->type = TYPE_GENERIC;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
