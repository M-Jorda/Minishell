/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:15:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:33:03 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Test function for basic lexer functionality
 * 
 * @param test_name Name of the test
 * @param input Input string to test
 * @param shell Shell structure
 */
static void	ft_test_lexer_case(char *test_name, char *input, t_shell *shell)
{
	t_list	*tokens;

	ft_printf("\n=== TEST: %s ===\n", test_name);
	ft_printf("Input: \"%s\"\n", input);
	
	tokens = ft_lexer(input, shell);
	if (!tokens)
	{
		ft_printf("ERROR: Lexer returned NULL\n");
		return ;
	}
	
	ft_print_token_list(tokens);
	ft_free_token_list(tokens);
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
	
	// Initialize minimal shell structure for testing
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
	
	// Run tests
	ft_test_lexer_case("Simple word", "echo", &shell);
	ft_test_lexer_case("Multiple words", "echo hello", &shell);
	ft_test_lexer_case("Three words", "echo hello world", &shell);
	ft_test_lexer_case("Simple pipe", "ls | grep", &shell);
	ft_test_lexer_case("Pipe with words", "ls | grep test", &shell);
	ft_test_lexer_case("Output redirection", "echo hello > file", &shell);
	ft_test_lexer_case("Input redirection", "cat < file", &shell);
	ft_test_lexer_case("Multiple operators", "echo test > output | cat", &shell);
	ft_test_lexer_case("Extra spaces", "  echo    hello   world  ", &shell);
	ft_test_lexer_case("Empty string", "", &shell);
	
	// Cleanup
	free(shell.env);
	
	ft_printf("\n=== ALL TESTS COMPLETED ===\n");
	return (0);
}
