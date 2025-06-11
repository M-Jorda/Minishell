/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:48:03 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/08 09:04:08 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = len_s1 + len_s2;
	result = (char *) malloc(sizeof(char) * (i + 1));
	if (!result)
		return (ft_free((char **) &s1));
	i = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		result[i + len_s1] = s2[i];
	result[i + len_s1] = '\0';
	ft_free((char **) &s1);
	return (result);
}

int	ft_gnl_strchr(char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == (char) c)
			return (i + 1);
	return (0);
}
