/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:37:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/04 16:50:26 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Opens a file with the specified name and action.
 *
 * This function attempts to open a file with the given name and action (mode).
 * If the file cannot be accessed with the specified action, it returns -2.
 * Otherwise, it returns the file descriptor obtained from the open() system
 * call.
 *
 * @param name The name of the file to be opened.
 * @param flag The action (mode) to open the file with (e.g., O_RDONLY,
 * O_WRONLY).
 * @return The file descriptor on success, -1 if doesn't exist or -2 if the file
 * cannot be accessed.
 */

// int	ft_openfile(char *name, int flag)
// {
// 	int	fd;

// 	if (access(name, F_OK) == -1)
// 		ft_err(NULL, NOT_A_FILE, ENOENT);
// 	if (access(name, flag) == -1)
// 		ft_err(NULL, PERMISSION, EACCES);
// 	fd = open(name, flag);
// 	return (fd);
// }
