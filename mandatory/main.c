/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:56:49 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/16 15:57:30 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**env;
	(void)argc;

	setup_interactive_signals();
	while (1)
	{
		input = readline("\001\033[1;35m\002minishell$ \001\033[0m\002");
		if (!input)
		{
			write(1, "exit\n", 5);
			break;
		}
		if (*input)
		add_history(input);
		run_builtin(argv, &env);
		env = ft_envdup(envp);
		free(input);
	}
	return (0);
}