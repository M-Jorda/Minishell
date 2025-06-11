/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:31:29 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:25:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Extracts a substring from the given string, starting at the specified index
 * and with a specified length.
 * 
 * @param s The string to extract the substring from.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return The substring, or NULL if malloc fails or invalid parameters are
 * provided.
 * 
 * Note: Memory for the substring is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	size;
	char	*substr;

	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	j = start;
	if (size >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return ((char *) ft_mallocfailed("ft_substr"));
	j = 0;
	while (s[start] && j < len)
		substr[j++] = s[start++];
	substr[j] = '\0';
	return (substr);
}
