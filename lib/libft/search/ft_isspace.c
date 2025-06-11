/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:42:04 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/07 18:47:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is a whitespace character (space or any of the
 * control characters: tab, newline, etc.).
 * 
 * @param c The character to check.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
