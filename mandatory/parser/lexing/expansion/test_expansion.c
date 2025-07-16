/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:15:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:50:32 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Test variable expansion functionality
 * 
 * @param shell Shell structure
 */
static void	ft_test_variable_expansion(t_shell *shell)
{
	char	*result;

	ft_printf("\n=== TESTING VARIABLE EXPANSION ===\n");
	
	// Test basic variable expansion
	result = ft_expand_variable(shell, "HOME");
	ft_printf("$HOME = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	result = ft_expand_variable(shell, "PATH");
	ft_printf("$PATH = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	result = ft_expand_variable(shell, "USER");
	ft_printf("$USER = \"%s\"\n", result ? result : "(null)");
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

	ft_printf("\n=== TESTING EXIT CODE EXPANSION ===\n");
	
	// Set different exit codes and test
	ft_update_exit_code(shell, 0);
	result = ft_expand_exit_code(shell);
	ft_printf("$? (exit 0) = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	ft_update_exit_code(shell, 127);
	result = ft_expand_exit_code(shell);
	ft_printf("$? (exit 127) = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	ft_update_exit_code(shell, 1);
	result = ft_expand_exit_code(shell);
	ft_printf("$? (exit 1) = \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test quote removal functionality
 */
static void	ft_test_quote_removal(void)
{
	char	*result;

	ft_printf("\n=== TESTING QUOTE REMOVAL ===\n");
	
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
	
	// Test mixed quotes
	result = ft_remove_quotes("'hello' \"world\"");
	ft_printf("'hello' \"world\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test no quotes
	result = ft_remove_quotes("hello world");
	ft_printf("hello world -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Test full expansion process
 * 
 * @param shell Shell structure
 */
static void	ft_test_full_expansion(t_shell *shell)
{
	char	*result;

	ft_printf("\n=== TESTING FULL EXPANSION PROCESS ===\n");
	
	// Test variable in double quotes
	result = ft_process_expansions(shell, "Hello $USER", true);
	ft_printf("\"Hello $USER\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test exit code expansion
	ft_update_exit_code(shell, 42);
	result = ft_process_expansions(shell, "Exit code: $?", false);
	ft_printf("\"Exit code: $?\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test multiple variables
	result = ft_process_expansions(shell, "$USER is in $HOME", false);
	ft_printf("\"$USER is in $HOME\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
	
	// Test bare dollar
	result = ft_process_expansions(shell, "Price: $10", false);
	ft_printf("\"Price: $10\" -> \"%s\"\n", result ? result : "(null)");
	if (result)
		free(result);
}

/**
 * @brief Create test token for expansion testing
 * 
 * @param type Token type
 * @param value Token value
 * @return t_token* Created token
 */
static t_token	*ft_create_test_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(value);
	return (token);
}

/**
 * @brief Test token expansion
 * 
 * @param shell Shell structure
 */
static void	ft_test_token_expansion(t_shell *shell)
{
	t_token	*token;

	ft_printf("\n=== TESTING TOKEN EXPANSION ===\n");
	
	// Test word token with variable
	token = ft_create_test_token(TOKEN_WORD, "$HOME/documents");
	ft_printf("Before: type=%d, value=\"%s\"\n", token->type, token->value);
	ft_expand_token(shell, token);
	ft_printf("After:  type=%d, value=\"%s\"\n", token->type, token->value);
	ft_free_token(token);
	
	// Test double quoted token
	token = ft_create_test_token(TOKEN_DQUOTE, "Hello $USER");
	ft_printf("Before: type=%d, value=\"%s\"\n", token->type, token->value);
	ft_expand_token(shell, token);
	ft_printf("After:  type=%d, value=\"%s\"\n", token->type, token->value);
	ft_free_token(token);
	
	// Test single quoted token (no expansion)
	token = ft_create_test_token(TOKEN_QUOTE, "$HOME should not expand");
	ft_printf("Before: type=%d, value=\"%s\"\n", token->type, token->value);
	ft_expand_token(shell, token);
	ft_printf("After:  type=%d, value=\"%s\"\n", token->type, token->value);
	ft_free_token(token);
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
	
	// Initialize shell structure
	if (ft_setup(&shell, envp) == -1)
	{
		ft_printf("Error: Failed to setup shell\n");
		return (1);
	}
	
	// Run all expansion tests
	ft_test_variable_expansion(&shell);
	ft_test_exit_code_expansion(&shell);
	ft_test_quote_removal();
	ft_test_full_expansion(&shell);
	ft_test_token_expansion(&shell);
	
	ft_printf("\n=== ALL EXPANSION TESTS COMPLETED ===\n");
	
	// Cleanup
	ft_cleanup(&shell, 0);
	return (0);
}
