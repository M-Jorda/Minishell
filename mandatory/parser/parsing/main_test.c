/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:05:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Initializes shell structure for testing
 * 
 * @param shell Shell structure to initialize
 * @param env Environment variables
 * @return int 0 on success, -1 on error
 */
static int	ft_init_shell(t_shell *shell, char **env)
{
	if (!shell)
		return (-1);
	shell->env = malloc(sizeof(t_env));
	if (!shell->env)
		return (-1);
	shell->env->env_vars = env;
	shell->env->local_env = NULL;
	shell->env->last_exit_code = 0;
	shell->token = NULL;
	shell->ast = NULL;
	shell->current_line = NULL;
	shell->prompt = NULL;
	return (0);
}

/**
 * @brief Displays token list for debugging
 * 
 * @param tokens Head of token list
 */
static void	ft_print_tokens(t_list *tokens)
{
	t_list	*curr;
	int		index;

	ft_printf("=== TOKENS LIST ===\n");
	if (!tokens)
	{
		ft_printf("(empty)\n\n");
		return ;
	}
	curr = tokens;
	index = 0;
	while (curr)
	{
		ft_printf("[%d] Type: %d, Value: \"%s\"\n", 
			index, curr->content.token->type, curr->content.token->value);
		curr = curr->next;
		index++;
	}
	ft_printf("\n");
}

/**
 * @brief Tests parsing and displays results
 * 
 * @param shell Shell structure with tokens
 * @return int 0 on success, 1 on error
 */
static int	ft_test_parsing(t_shell *shell)
{
	int	result;

	ft_printf("=== PARSING TEST ===\n");
	result = ft_parsing(shell);
	if (result < 0)
	{
		ft_printf("✗ Parsing failed (code: %d)\n", result);
		return (1);
	}
	ft_printf("✓ Parsing successful\n\n");
	if (shell->ast)
	{
		ft_printf("=== AST STRUCTURE ===\n");
		ft_print_ast_tree(shell->ast, 0);
		ft_printf("\n");
	}
	else
		ft_printf("No AST generated\n\n");
	return (0);
}

/**
 * @brief Main function for testing parser
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @param env Environment variables
 * @return int Exit code
 */
int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	int		exit_code;

	if (argc != 2)
	{
		ft_printf("Usage: %s \"command to parse\"\n", argv[0]);
		ft_printf("Example: %s \"echo hello | grep h && ls\"\n", argv[0]);
		return (1);
	}
	if (ft_init_shell(&shell, env) < 0)
	{
		ft_printf("Error: Shell initialization failed\n");
		return (1);
	}
	shell.current_line = argv[1];
	ft_printf("=== PARSING TEST PROGRAM ===\n");
	ft_printf("Command: \"%s\"\n\n", shell.current_line);
	shell.token = ft_lexing(&shell);
	if (!shell.token)
	{
		ft_printf("Error: Lexing failed\n");
		free(shell.env);
		return (1);
	}
	ft_print_tokens(shell.token);
	exit_code = ft_test_parsing(&shell);
	if (shell.ast)
		ft_free_ast(shell.ast);
	if (shell.token)
		ft_lstfree_t(shell.token);
	free(shell.env);
	ft_printf("=== TEST COMPLETED ===\n");
	return (exit_code);
}
