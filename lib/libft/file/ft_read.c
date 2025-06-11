/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:56:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/02/19 20:17:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read(int fd, int size)
{
	char	*str;

	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (read(fd, &str, size))
	{
		free(str);
		return (NULL);
	}
	str[size] = '\0';
	return (str);
}
