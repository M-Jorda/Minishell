/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:33:52 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/29 11:00:29 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/* ********************************** ERROR ********************************* */

// ENOMEM: Out of memory error code
// ENOENT: No such file or directory error code
// EACCES: Permission denied

# define INV_NUM_ARG	"Invalid number of arguments."
# define EMPTY_ARG		"The argument can't be empty."
# define INV_ARG_FORMAT	"Invalid format of argument. '*.ber' awaiting."
# define INV_MLX_INIT	"mlx_init failed."
# define ERR_MALL_M		"Cannot allocate memory."
# define PERMISSION		"Permission denied."
# define BAD_FD			"Bad file descriptor."
# define NOT_A_FILE		"No such file or directory."
# define EMPTY_FILE		"The file is empty."

# define STD_ERR		1

# define PIPE			'|'
# define R_OUT			'>'
# define R_IN			'<'
# define AND			'&'
# define DOLL			'$'
# define Q_MRK			'?'
# define S_QTE			'\''
# define D_QTE			'"'
# define P_OPN			'('
# define P_CLS			')'
# define ALL			'*'
# define EQUL			'='

#endif
