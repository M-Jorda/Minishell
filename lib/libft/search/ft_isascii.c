/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:13:31 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:27:26 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is an ASCII character.
 * 
 * @param c The character to check.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}
