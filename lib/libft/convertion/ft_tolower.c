/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:45:07 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/06 11:32:48 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an uppercase letter to its lowercase equivalent.
 * 
 * @param c The character to be converted.
 * @return The lowercase equivalent of the character if it is an uppercase
 * letter;
 * otherwise, the character itself.
 */
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}
