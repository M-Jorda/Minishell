/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:16:39 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:47:38 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a lowercase letter to its uppercase equivalent.
 *
 * @param c The character to be converted.
 * @return The uppercase equivalent of the character if it is a lowercase letter;
 * otherwise, the character itself.
 */
int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
