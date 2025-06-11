/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:37:38 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/16 18:50:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

int	ft_free(char *str1, void *str2)
{
	free(str1);
	if (str2)
		free(str2);
	return (-1);
}

static char	*ft_readstdin(void)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (100 + 1));
	if (!buff)
		return (NULL);
	bytes_read = read(STDIN_FILENO, buff, 100);
	if (bytes_read == -1)
		return (NULL);
	buff[bytes_read] = '\0';
	return (buff);
}

static int	ft_scan_arg(char str, va_list args, t_scan *scan)
{
	char	*split;

	split = ft_readstdin();
	if (!split)
		return (-1);
	scan->split = ft_split(split, ' ');
	free(split);
	if (!scan->split)
		return (ft_free(split, NULL));
	if (str == 'c')
		ft_readchar((char)va_arg(args, int *), scan);
	if (str == 's')
		ft_readstr(va_arg(args, char **), scan);
	if (str == 'p')
		ft_readptr(va_arg(args, void **), scan);
	if (str == 'x' || str == 'X')
		ft_readhexdec((unsigned long)va_arg(args, void **), str, scan, 0);
	if (str == 'd' || str == 'i')
		ft_readnbr(va_arg(args, int *), scan);
	if (str == 'u')
		ft_readnbr(va_arg(args, unsigned int *), scan);
	if (str == '%')
		ft_readchar('%', scan);
	return (0);
}

int	scanf(const char *str, ...)
{
	va_list	args;
	t_scan	*scan;
	char	*mall;
	int		i;

	va_start(args, str);
	scan = malloc(sizeof(t_scan));
	if (!scan)
		return (-1);
	mall = ft_strdup((char *)str);
	if (!mall)
		return (ft_free(scan, NULL));
	i = 0;
	scan->count = 0;
	scan->word = 0;
	while (str[i])
	{
		if (str[i] == '%')
			if (ft_scan_arg(str[++i], args, scan) != 0)
				return (ft_free(mall, (void *)scan));
	}
	i = scan->count;
	ft_free(mall, (void *)scan);
	va_end(args);
	return (i);
}
