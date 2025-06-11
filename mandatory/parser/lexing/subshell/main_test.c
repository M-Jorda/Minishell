/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:15:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/01 14:36:48 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Prints parentheses validation results
 * 
 * @param shell Shell structure
 */
static void	ft_print_validation_results(t_shell *shell)
{
	bool	is_balanced;
	bool	is_valid_order;
	bool	is_complete;

	ft_printf("=== VALIDATION DES PARENTHESES ===\n");
	is_balanced = (ft_check_paren_balance(shell->token) == 0);
	is_valid_order = ft_validate_paren_order(shell->token);
	is_complete = ft_validate_parentheses_complete(shell->token);
	ft_printf("Equilibrage: %s\n", is_balanced ? "✓ OK" : "✗ ERREUR");
	ft_printf("Ordre: %s\n", is_valid_order ? "✓ OK" : "✗ ERREUR");
	ft_printf("Validation complete: %s\n", is_complete ? "✓ OK" : "✗ ERREUR");
	ft_printf("\n");
}

/**
 * @brief Analyzes parentheses structure in token list
 * 
 * @param shell Shell structure
 */
static void	ft_analyze_parentheses_structure(t_shell *shell)
{
	t_list	*curr;
	t_list	*matching;
	int		paren_count;

	ft_printf("=== ANALYSE DE LA STRUCTURE ===\n");
	curr = shell->token;
	paren_count = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
		{
			paren_count++;
			matching = ft_find_matching_paren(curr);
			ft_printf("Parenthese ouvrante #%d: ", paren_count);
			if (matching)
				ft_printf("✓ Fermante trouvee\n");
			else
				ft_printf("✗ Pas de fermante\n");
		}
		curr = curr->next;
	}
	if (paren_count == 0)
		ft_printf("Aucune parenthese trouvee\n");
	ft_printf("\n");
}

/**
 * @brief Prints other AST node types
 * 
 * @param ast AST node
 * @param level Indentation level
 */
static void	ft_print_ast_other_nodes(t_ast_node *ast, int level)
{
	if (ast->type == NODE_PIPE)
		ft_printf("PIPE\n");
	else if (ast->type == NODE_AND)
		ft_printf("AND (&&)\n");
	else if (ast->type == NODE_OR)
		ft_printf("OR (||)\n");
	else
		ft_printf("NODE_TYPE: %d\n", ast->type);
	if (ast->left)
		ft_print_ast_structure(ast->left, level + 1);
	if (ast->right)
		ft_print_ast_structure(ast->right, level + 1);
}

/**
 * @brief Prints AST structure with indentation
 * 
 * @param ast AST node to print
 * @param level Indentation level
 */
static void	ft_print_ast_structure(t_ast_node *ast, int level)
{
	t_command	*cmd;
	int			i;
	int			j;

	if (!ast)
		return ;
	i = 0;
	while (i < level)
	{
		ft_printf("  ");
		i++;
	}
	if (ast->type == NODE_GROUP)
	{
		ft_printf("GROUP (subshell)\n");
		if (ast->left)
			ft_print_ast_structure(ast->left, level + 1);
	}
	else if (ast->type == NODE_COMMAND)
	{
		cmd = (t_command *)ast->data;
		ft_printf("COMMAND: ");
		if (cmd && cmd->args)
		{
			j = 0;
			while (cmd->args[j])
			{
				ft_printf("%s", cmd->args[j]);
				if (cmd->args[j + 1])
					ft_printf(" ");
				j++;
			}
		}
		ft_printf("\n");
	}
	else
		ft_print_ast_other_nodes(ast, level);
}

/**
 * @brief Tests parentheses parsing and prints results
 * 
 * @param shell Shell structure
 * @return int 0 on success, 1 on error
 */
static int	ft_test_parentheses_parsing(t_shell *shell)
{
	int	parse_result;

	ft_printf("=== TEST DU PARSING ===\n");
	parse_result = ft_parsing_with_parentheses(shell);
	if (parse_result < 0)
	{
		ft_printf("✗ Echec du parsing (code: %d)\n", parse_result);
		return (1);
	}
	ft_printf("✓ Parsing reussi\n\n");
	if (shell->ast)
	{
		ft_printf("=== ARBRE SYNTAXIQUE ABSTRAIT ===\n");
		ft_print_ast_structure(shell->ast, 0);
		ft_printf("\n");
	}
	else
		ft_printf("Aucun AST genere\n\n");
	return (0);
}

/**
 * @brief Main function for testing subshell parsing
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
		ft_printf("Usage: %s \"commande avec parentheses\"\n", argv[0]);
		ft_printf("Exemple: %s \"echo hello && (pwd || ls)\"\n", argv[0]);
		return (1);
	}
	if (ft_setup(&shell, env) == -1)
	{
		ft_printerr("Erreur: Initialisation echouee\n");
		return (1);
	}
	shell.current_line = argv[1];
	ft_printf("=== TEST DU PARSING DES PARENTHESES ===\n");
	ft_printf("Commande: \"%s\"\n\n", shell.current_line);
	shell.token = ft_lexing(&shell);
	if (!shell.token)
	{
		ft_printerr("Erreur: Echec du lexing\n");
		ft_cleanup(&shell, 1);
		return (1);
	}
	ft_print_validation_results(&shell);
	ft_analyze_parentheses_structure(&shell);
	if (ft_test_parentheses_parsing(&shell) != 0)
	{
		ft_cleanup(&shell, 1);
		return (1);
	}
	ft_printf("=== TEST TERMINE AVEC SUCCES ===\n");
	ft_cleanup(&shell, 0);
	return (0);
}
