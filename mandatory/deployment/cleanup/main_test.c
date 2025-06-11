/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:42:58 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 13:56:50 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void) argv;
	if (argc != 2)
	{
		ft_printerr("PLEASE ENTER THE STATUS\n");
		return (1);
	}
	if (ft_setup(&shell, env) == -1)
	{
		free (shell.env);
		shell.env = NULL;
		ft_printerr("ERROR\n");
		return (1);
	}
	// ft_printerr("env[0] = %s", shell.env[0]);
	ft_cleanup(&shell, ft_atoi(argv[1]));
	return (0);
}
