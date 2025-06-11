/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:39 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:27:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Checks if the given character is alphanumeric (either a digit or a letter).
 * 
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (8);
	return (0);
}
