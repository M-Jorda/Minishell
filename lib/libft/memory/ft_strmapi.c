/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:55:02 by jjorda            #+#    #+#             */
/*   Updated: 2024/09/27 16:47:52 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Applies the function f to each character of the string s, and returns a new
 * string with the results.
 * 
 * @param s The string to iterate over.
 * @param f The function to apply to each character, taking the index and
 * character.
 * @return A new string with the transformed characters, or NULL if malloc fails.
 * 
 * Note: Memory for the new string is allocated using malloc().
 *       If malloc fails, the function returns NULL.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
