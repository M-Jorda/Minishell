/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:34:20 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:19:54 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Deletes a single element of the linked list and frees its memory.
 * 
 * @param node The element to delete.
 * @param del The function to delete the content of the element.
 * 
 * Note: The function uses free() to release the memory allocated for the node.
 */
void	ft_lstdel_node(t_list *node, void (*del)(t_content))
{
	if (node == NULL)
		return ;
	del(node->content);
	free(node);
}
