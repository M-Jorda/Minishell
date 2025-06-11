/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:41:51 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:23:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Allocates memory for an array of nmemb elements, each of size bytes, and
 * initializes all bytes to zero.
 * 
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if malloc fails or invalid
 * parameters are provided.
 * 
 * Note: Memory for the array is allocated using malloc(), and the memory is
 * initialized to zero using ft_memset().
 *       If malloc fails, the function returns NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0)
		return (malloc(0));
	if ((nmemb == 0 && size == 0) || nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (ft_mallocfailed("ft_calloc"));
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}
