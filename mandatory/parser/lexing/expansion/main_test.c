/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:40:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:32:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Test variable expansion using getenv
 * 
 * @param shell Shell structure
 */
static void	ft_test_variable_expansion(t_shell *shell)
{
	char	*result;
	
	ft_printf("\n=== VARIABLE EXPANSION TESTS ===\n");
	
	// Test HOME expansion using getenv
	result = ft_expand_variable(shell, "HOME");
	ft_printf("$HOME = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test USER expansion 
	result = ft_expand_variable(shell, "USER");
	ft_printf("$USER = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test PATH expansion
	result = ft_expand_variable(shell, "PATH");
	if (result && ft_strlen(result) > 50)
		ft_printf("$PATH = \"%.50s...\" (truncated)\n", result);
	else
		ft_printf("$PATH = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test non-existent variable
	result = ft_expand_variable(shell, "NONEXISTENT");
	ft_printf("$NONEXISTENT = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test exit code expansion
 * 
 * @param shell Shell structure
 */
static void	ft_test_exit_code_expansion(t_shell *shell)
{
	char	*result;
	
	ft_printf("\n=== EXIT CODE EXPANSION TESTS ===\n");
	
	// Test with exit code 0
	shell->env->last_exit_code = 0;
	result = ft_expand_exit_code(shell);
	ft_printf("$? (code 0) = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test with exit code 127
	shell->env->last_exit_code = 127;
	result = ft_expand_exit_code(shell);
	ft_printf("$? (code 127) = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test $? in string
	result = ft_process_exit_code_expansion(shell, "exit code is $?");
	ft_printf("\"exit code is $?\" = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test quote removal
 */
static void	ft_test_quote_removal(void)
{
	char	*result;
	
	ft_printf("\n=== QUOTE REMOVAL TESTS ===\n");
	
	// Test single quotes
	result = ft_remove_quotes("'hello world'");
	ft_printf("'hello world' -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test double quotes
	result = ft_remove_quotes("\"hello world\"");
	ft_printf("\"hello world\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test no quotes
	result = ft_remove_quotes("hello world");
	ft_printf("hello world -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test unmatched quotes
	result = ft_remove_quotes("'hello world");
	ft_printf("'hello world -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test complex expansion scenarios
 * 
 * @param shell Shell structure
 */
static void	ft_test_complex_expansion(t_shell *shell)
{
	char	*result;
	char	*user_value;
	
	ft_printf("\n=== COMPLEX EXPANSION TESTS ===\n");
	
	// Get USER value first for predictable test
	user_value = getenv("USER");
	if (!user_value)
		user_value = "unknown";
	
	// Test multiple variables
	result = ft_process_var_expansion(shell, "User $USER in directory");
	ft_printf("\"User $USER in directory\" = \"%s\"\n", 
		result ? result : "(null)");
	if (result)
		free(result);
	
	// Test mixed $VAR and $?
	shell->env->last_exit_code = 42;
	result = ft_process_exit_code_expansion(shell, "Status: $?");
	ft_printf("\"Status: $?\" = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test expansion utilities
 */
static void	ft_test_expansion_utils(void)
{
	ft_printf("\n=== EXPANSION UTILITIES TESTS ===\n");
	
	// Test variable name validation
	ft_printf("Valid var 'HOME': %s\n", 
		ft_is_valid_var_name("HOME") ? "true" : "false");
	ft_printf("Valid var '_VAR': %s\n", 
		ft_is_valid_var_name("_VAR") ? "true" : "false");
	ft_printf("Valid var '123VAR': %s\n", 
		ft_is_valid_var_name("123VAR") ? "true" : "false");
	ft_printf("Valid var 'VAR-NAME': %s\n", 
		ft_is_valid_var_name("VAR-NAME") ? "true" : "false");
	
	// Test contains variables
	ft_printf("Contains vars 'hello $HOME': %s\n", 
		ft_contains_variables("hello $HOME") ? "true" : "false");
	ft_printf("Contains vars 'hello world': %s\n", 
		ft_contains_variables("hello world") ? "true" : "false");
	ft_printf("Contains vars '$? status': %s\n", 
		ft_contains_variables("$? status") ? "true" : "false");
}

/**
 * @brief Test quotes validation
 */
static void	ft_test_quotes_validation(void)
{
	ft_printf("\n=== QUOTES VALIDATION TESTS ===\n");
	
	// Test balanced quotes
	ft_printf("Balanced 'hello world': %s\n",
		ft_quotes_are_balanced("'hello world'") ? "true" : "false");
	ft_printf("Balanced \"hello world\": %s\n",
		ft_quotes_are_balanced("\"hello world\"") ? "true" : "false");
	
	// Test unbalanced quotes
	ft_printf("Balanced 'hello world: %s\n",
		ft_quotes_are_balanced("'hello world") ? "true" : "false");
	ft_printf("Balanced \"hello world: %s\n",
		ft_quotes_are_balanced("\"hello world") ? "true" : "false");
	
	// Test mixed quotes
	ft_printf("Balanced 'hello \"world\"': %s\n",
		ft_quotes_are_balanced("'hello \"world\"'") ? "true" : "false");
}

/**
 * @brief Main test function
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
	
	// Initialize shell for testing
	shell.env = malloc(sizeof(t_env));
	if (!shell.env)
		return (1);
	shell.env->env_vars = envp;
	shell.env->local_env = NULL;
	shell.env->last_exit_code = 0;
	shell.current_line = NULL;
	shell.signal_received = 0;
	shell.prompt = NULL;
	shell.token = NULL;
	shell.ast = NULL;
	
	ft_printf("=== EXPANSION MODULE TESTS ===\n");
	
	// Run all tests
	ft_test_variable_expansion(&shell);
	ft_test_exit_code_expansion(&shell);
	ft_test_quote_removal();
	ft_test_complex_expansion(&shell);
	ft_test_expansion_utils();
	ft_test_quotes_validation();
	
	ft_printf("\n=== ALL EXPANSION TESTS COMPLETED ===\n");
	
	// Cleanup
	free(shell.env);
	
	return (0);
}
