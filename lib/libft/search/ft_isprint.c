/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:21:48 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:27:37 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is a printable character (from space to ~).
 * 
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	return (0);
}
