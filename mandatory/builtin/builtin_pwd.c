/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:59:41 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/08 18:21:37 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	builtin_pwd(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_printerr("minishell: pwd");
		return (1);
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}

