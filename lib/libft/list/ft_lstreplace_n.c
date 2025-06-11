/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:25:54 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/01 17:06:10 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool ft_lstreplace_n(t_list **del, t_list *rep, void *(*f)(t_list *), int n)
{
    t_list  *curr;
    t_list  *next;
    int     i;

    if (!del || !(*del) || !rep || n < 0 || !f)
        return (false);
	rep->prev = (*del)->prev;
    if ((*del)->prev)
        (*del)->prev->next = rep;
    curr = *del;
    i = 0;
    while (i < n && curr)
    {
		next = curr->next;
		// ft_printerr("before: %p\n", curr);
        f(curr);
        curr = next;
		// ft_printerr("after: %s\n", curr->content.token->value);
        i++;
    }
    rep->next = curr;
    if (curr)
        curr->prev = rep;
    *del = rep;
	// ft_printerr("bef: %s, curr: %s, next: %s\n", curr->prev->content.token->value, curr->content.token->value, curr->next->content.token->value);
	// ft_printerr("bef: %d, curr: %d, next: %d\n", curr->prev->content.token->type, curr->content.token->type, curr->next->content.token->type);
    return (true);
}
