/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:56:00 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/08 18:21:31 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(char **args)
{
	int	code;

	ft_putstr_fd("exit\n", 1);
	if (!args[1])
		exit(0);
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		exit(2);
	}
	if (args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	code = ft_atoi(args[1]) % 256;
	if (code < 0)
		code += 256;
	exit(code);
}