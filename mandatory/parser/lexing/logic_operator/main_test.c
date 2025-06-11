/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/01 14:15:59 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Tests logical operator parsing functionality
 * 
 * @param shell Shell structure
 * @return int 0 on success, 1 on error
 */
static int	ft_test_logical_parsing(t_shell *shell)
{
	int	result;

	ft_printf("=== TESTING LOGICAL PARSING ===\n");
	
	result = ft_parse_logical_operators(shell);
	if (result < 0)
	{
		ft_printf("✗ Logical parsing failed (code: %d)\n", result);
		return (1);
	}
	
	ft_printf("✓ Logical parsing successful\n\n");
	return (0);
}

/**
 * @brief Prints example usage patterns
 */
static void	ft_print_examples(void)
{
	ft_printf("=== EXAMPLE COMMANDS ===\n");
	ft_printf("Simple AND:     \"echo hello && pwd\"\n");
	ft_printf("Simple OR:      \"false || echo backup\"\n");
	ft_printf("Pipe + Logic:   \"ls | grep test && echo found\"\n");
	ft_printf("Complex:        \"cmd1 | cmd2 && cmd3 || cmd4\"\n");
	ft_printf("With parens:    \"(cmd1 || cmd2) && cmd3\"\n");
	ft_printf("========================\n\n");
}

/**
 * @brief Main function for testing logical operators parsing
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @param env Environment variables
 * @return int Exit code
 */
int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (argc != 2)
	{
		ft_printf("Usage: %s \"command with logical operators\"\n", argv[0]);
		ft_print_examples();
		return (1);
	}
	
	// Initialize shell
	if (ft_setup(&shell, env) == -1)
	{
		ft_printerr("Error: Shell initialization failed\n");
		return (1);
	}
	
	shell.current_line = argv[1];
	
	ft_printf("=== LOGICAL OPERATOR PARSING TEST ===\n");
	ft_printf("Command: \"%s\"\n\n", shell.current_line);
	
	// Explain precedence
	ft_explain_operator_precedence();
	
	// Step 1: Lexical analysis
	ft_printf("=== STEP 1: LEXICAL ANALYSIS ===\n");
	shell.token = ft_lexing(&shell);
	if (!shell.token)
	{
		ft_printerr("Error: Lexical analysis failed\n");
		ft_cleanup(&shell, 1);
		return (1);
	}
	ft_printf("✓ Lexical analysis successful\n\n");
	
	// Step 2: Logical operator parsing
	ft_printf("=== STEP 2: LOGICAL PARSING ===\n");
	if (ft_test_logical_parsing(&shell) != 0)
	{
		ft_cleanup(&shell, 1);
		return (1);
	}
	
	// Step 3: Analysis and debugging output
	ft_printf("=== STEP 3: ANALYSIS ===\n");
	ft_print_logical_analysis(&shell);
	
	ft_printf("=== TEST COMPLETED SUCCESSFULLY ===\n");
	ft_cleanup(&shell, 0);
	return (0);
}
