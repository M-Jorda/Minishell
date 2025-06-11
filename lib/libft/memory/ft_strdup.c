/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:44:44 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:39:42 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Creates a duplicate of the given string by allocating memory and copying the
 * content.
 * 
 * @param src The string to duplicate.
 * @return A pointer to the new string, or NULL if malloc fails.
 * 
 * Note: Memory for the new string is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (!dest)
		return ((char *) ft_mallocfailed("ft_strdup"));
	ft_strcpy(dest, src);
	return (dest);
}
