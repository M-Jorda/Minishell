/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstleaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:18:11 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 17:41:48 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_lstleak(t_list *list, int i)
{
	t_list	*current;

	while (i)
	{
		current = list->next;
		ft_lstiter(list, free);
		free(list);
		list = current;
		i--;
	}
}