/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:03:17 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:31:20 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Searches for the first occurrence of the substring little in the string big,
 * within the first len bytes.
 * 
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum number of bytes to search within.
 * @return A pointer to the first occurrence of little in big, or NULL if little
 * is not found within the limit.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (little[i] == '\0')
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while ((little[j]) && (little[j] == big[i + j]) && i + j < len)
		{
			if (!little[j + 1])
				return ((char *) &big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
