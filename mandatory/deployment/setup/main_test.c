/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:19:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 13:56:54 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

void	ft_printenv(t_shell shell)
{
	char	**env;
	int		i;

	i = -1;
	env = shell.env->env_vars;
	while (env[++i])
		ft_printerr("env[%d] = %s\n", i, env[i]);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void) argv;
	if (argc != 1)
	{
		ft_printerr("PLEASE DO NOT ENTER ANY ARGUMENTS\n");
		return (1);
	}
	if (ft_setup(&shell, env) == -1)
	{
		free (shell.env);
		shell.env = NULL;
		ft_printerr("ERROR\n");
		return (1);
	}
	ft_printenv(shell);
	free (shell.env);
	shell.env = NULL;
	return (0);
}
