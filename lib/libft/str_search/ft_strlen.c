/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:24:34 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:15 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
* The strlen() function calculates the length of the string pointed to by s,
* excluding the terminating null byte ('\0').
*/
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

/* int	main(int argc, char **argv)
{
	ft_printerr("size: %d", ft_strlen(argv[1]));
	return (0);
} */