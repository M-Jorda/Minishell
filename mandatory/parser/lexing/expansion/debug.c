/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:58:26 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Debug function to print environment variables
 * 
 * @param shell Shell structure
 */
void	ft_debug_print_env(t_shell *shell)
{
	int	i;

	if (!shell || !shell->env || !shell->env->env_vars)
	{
		ft_printf("DEBUG: No environment variables found\n");
		return ;
	}
	
	ft_printf("DEBUG: Environment variables:\n");
	i = 0;
	while (shell->env->env_vars[i] && i < 10) // Print first 10
	{
		ft_printf("  [%d] %s\n", i, shell->env->env_vars[i]);
		i++;
	}
	if (shell->env->env_vars[i])
		ft_printf("  ... and more\n");
}

/**
 * @brief Debug specific variable expansion
 * 
 * @param shell Shell structure
 * @param var_name Variable name to test
 */
void	ft_debug_variable_expansion(t_shell *shell, char *var_name)
{
	char	*result;

	ft_printf("DEBUG: Testing variable '%s'\n", var_name);
	result = ft_expand_variable(shell, var_name);
	ft_printf("DEBUG: Result: '%s'\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Main debug function
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @param envp Environment variables
 * @return int Exit code
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	
	(void)argc;
	(void)argv;
	
	// Initialize shell
	if (ft_setup(&shell, envp) == -1)
	{
		ft_printf("Error: Failed to setup shell\n");
		return (1);
	}
	
	// Debug environment
	ft_debug_print_env(&shell);
	
	// Test specific variables
	ft_debug_variable_expansion(&shell, "HOME");
	ft_debug_variable_expansion(&shell, "USER");
	ft_debug_variable_expansion(&shell, "PATH");
	ft_debug_variable_expansion(&shell, "SHELL");
	
	// Cleanup
	ft_cleanup(&shell, 0);
	return (0);
}
