/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:18:17 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:41:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static inline bool	ft_free_new(t_list **new)
{
	if (*new)
		free(*new);
	*new = NULL;
	return (false);
}

static inline bool	ft_insert_after(t_list **curr, t_list **new)
{
	if (!curr || !(*curr))
		return (ft_free_new(new));
	(*new)->next = (*curr)->next;
	(*new)->prev = *curr;
	if ((*curr)->next)
		(*curr)->next->prev = *new;
	(*curr)->next = *new;
	return (true);
}

bool ft_lstinsert(t_list **lst, void *data, int index)
{
	t_list	*curr;
	t_list	*new;
	int		i;

	if (!lst || !(*lst) || !data || index < 0)
		return (false);
	new = ft_lstnew(data);
	if (!new)
		return (false);
	if (index == 0)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
		return (true);
	}
	if (!(*lst))
		return (ft_free_new(&new));
	curr = *lst;
	i = -1;
	while (++i < index && curr)
		curr = curr->next;
	return (ft_insert_after(&curr, &new));
}
