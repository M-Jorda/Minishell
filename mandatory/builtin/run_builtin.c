/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:38:09 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/11 19:50:44 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	run_builtin(char **args, char ***env)
{
	if (!ft_strcmp(args[0], "echo"))
		return (builtin_echo(args));
	if (!ft_strcmp(args[0], "pwd"))
		return (builtin_pwd());
	if (!ft_strcmp(args[0], "cd"))
		return (builtin_cd(args, env));
	if (!ft_strcmp(args[0], "env"))
		return (builtin_env(*env));
	if (!ft_strcmp(args[0], "unset"))
		return (builtin_unset(args, env));
	if (!ft_strcmp(args[0], "exit"))
		return (builtin_exit(args));
	if (!ft_strcmp(args[0], "export"))
		return (builtin_export(args, env));
	return (1);
}

char	**ft_envdup(char **envp)
{
	int		i;
	char	**copy;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (envp[++i])
		copy[i] = ft_strdup(envp[i]);
	copy[i] = NULL;
	return (copy);
}

/* int	main(int argc, char **argv, char **envp)
{
	char	**env;
	(void)argc;

	env = ft_envdup(envp);
	run_builtin(argv, &env);
	return (0);
} */