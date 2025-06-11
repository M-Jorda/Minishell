/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:52:49 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:22:04 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Iterates over each element of the linked list and applies the function f to
 * its content.
 * 
 * @param lst The linked list to iterate over.
 * @param f The function to apply to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(t_content))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
