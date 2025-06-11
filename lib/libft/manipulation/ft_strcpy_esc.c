/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:19:32 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 12:13:49 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Handles the escaping of spaces enclosed in single or double quotes.
 *
 * This function checks if the current character in src is a single or double
 * quote
 * followed by a space. If so, it copies the quoted string to dest, including
 * the quotes.
 * If the character is not an escape character, it is copied directly to dest.
 *
 * @param dest Pointer to the destination array where the content is to be
 * copied.
 * @param src C string to be copied.
 * @param i Pointer to the current index in src.
 * @param j Pointer to the current index in dest.
 * @return A pointer to the destination string dest.
 */
static char	*ft_space_esc(char *dest, const char *src, int *i, int *j)
{
	if ((src[*i] == '\'' || src[*i] == '"') && src[*i + 1] == ' ')
	{
		dest[(*j)++] = src[(*i)++];
		while (src[*i] && src[*i] != '\'' && src[*i] != '"')
			dest[(*j)++] = src[(*i)++];
		dest[(*j)++] = src[(*i)++];
	}
	else if (!ft_isesc(src[*i]))
		dest[(*j)++] = src[(*i)++];
	else
		(*i)++;
	return (dest);
}

/**
 * @brief Copies the string pointed to by src to dest, escaping certain
 * characters.
 *
 * This function copies the string pointed to by src to dest, while escaping
 * newline characters and handling spaces enclosed in single or double quotes.
 *
 * @param dest Pointer to the destination array where the content is to be
 * copied.
 * @param src C string to be copied.
 * @return A pointer to the destination string dest.
 *
 * @note The destination array dest must be large enough to hold the resulting
 * string.
 */
char	*ft_strcpy_esc(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			dest[j++] = '\\';
			dest[j++] = 'n';
			i++;
		}
		ft_space_esc(dest, src, &i, &j);
	}
	dest[j] = '\0';
	return (dest);
}
