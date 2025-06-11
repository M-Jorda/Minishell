/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocfailed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:52:53 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/29 12:06:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s);

/**
 * Handles malloc failure by printing an error message with the function name
 * where malloc failed.
 * 
 * @param funcname The name of the function where malloc failed.
 * @return NULL, indicating failure.
 * 
 * Note: Memory for the error message is allocated using malloc(). 
 *       If malloc fails during error handling, the function returns NULL.
 *       And Frre it
 */

void	*ft_mallocfailed(char *funcname)
{
	char	*errmess;
	char	*prefix;

	prefix = "Error with malloc in the function: ";
	errmess = malloc(sizeof(char)
			* (ft_strlen(prefix) + ft_strlen(funcname) + 1));
	if (!errmess)
		return (NULL);
	ft_strcpy(errmess, prefix);
	ft_strcat(errmess, funcname);
	write(2, errmess, ft_strlen(errmess));
	write(2, "\n", 1);
	free(errmess);
	return (NULL);
}
