/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:08:07 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 21:56:40 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static inline t_list	*ft_getfunc(t_content data, t_content_type type)
{
	t_list	*lst;

	if (type == TYPE_REDIR)
		lst = ft_lstnew_redir(data.redir);
	else if (type == TYPE_TOKEN)
		lst = ft_lstnew_tok(data.token);
	else
		lst = ft_lstnew(data.generic);
	return (lst);
}

/**
 * Adds a new element at the end of the linked list.
 * 
 * @param lst The pointer to the first element of the linked list.
 * @param new The new element to add at the end of the list.
 */
bool	ft_lstadd_back(t_list **lst, t_content data, t_content_type type)
{
	t_list	*new;
	t_list	*last;

	if (!type)
		return (NULL);
	new = ft_getfunc(data, type);
	if (!new)
		return (false);
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	return (true);
}
