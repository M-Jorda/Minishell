/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:19:37 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/18 13:56:59 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

int	ft_setenv(t_shell *shell, char **env)
{
	if (!shell || !env)
		return (-1);
	shell->env = malloc(sizeof(t_env));
	if (!shell->env)
		return (-1);
	shell->env->env_vars = env;
	shell->env->local_env = NULL;
	shell->env->last_exit_code = 0;
	return (0);
}

int	ft_setup(t_shell *shell, char **env)
{
	if (!shell || !env)
		return (-1);
	if (ft_setenv(shell, env) == -1)
		return (-1);
	shell->current_line = NULL;
	shell->signal_received = 0;
	shell->prompt = NULL;
	shell->ast = NULL;
	shell->token = NULL;
	return (0);
}
