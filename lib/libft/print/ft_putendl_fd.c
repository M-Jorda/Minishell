/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:57:43 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:26:30 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Writes a string followed by a newline to the specified file descriptor.
 * 
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd)
{
	char	n;

	n = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &n, 1);
}
