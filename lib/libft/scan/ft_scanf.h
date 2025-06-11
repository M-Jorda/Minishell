/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:34:27 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/16 18:50:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H

# include "../libft.h"

// enum e_type
// {
// 	INTEGER,
// 	CHAR,
// 	STRING

// } t_type;

// union u_data
// {
// 	int num;
// 	char c;
// 	char *str;
// 	char *ptr;
// 	char *hexadecimal;
// } t_data;

typedef struct s_scan
{
	// enum e_type type;
	// union u_data data;
	char	**split;
	int		count;
	int		word;
}	t_scan;

#endif