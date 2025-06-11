/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_print_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/01 14:15:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Prints indentation for debug output
 * 
 * @param level Indentation level
 */
static void	ft_print_indent(int level)
{
	int	i;

	i = 0;
	while (i < level)
	{
		ft_printf("  ");
		i++;
	}
}

/**
 * @brief Gets string representation of logical operator
 * 
 * @param type Node type
 * @return char* String representation
 */
char	*ft_get_logical_op_str(node_type type)
{
	if (type == NODE_AND)
		return ("&&");
	else if (type == NODE_OR)
		return ("||");
	else if (type == NODE_PIPE)
		return ("|");
	else
		return ("UNKNOWN");
}

/**
 * @brief Prints operator node for debugging
 * 
 * @param node Operator node
 * @param level Indentation level
 */
static void	ft_print_operator_node(t_ast_node *node, int level)
{
	ft_printf("OPERATOR: %s\n", ft_get_logical_op_str(node->type));
	
	if (node->left)
	{
		ft_print_indent(level + 1);
		ft_printf("LEFT:\n");
		ft_print_logical_ast(node->left, level + 2);
	}
	
	if (node->right)
	{
		ft_print_indent(level + 1);
		ft_printf("RIGHT:\n");
		ft_print_logical_ast(node->right, level + 2);
	}
}

/**
 * @brief Prints command node for debugging
 * 
 * @param node Command node
 */
static void	ft_print_command_node(t_ast_node *node)
{
	t_command	*cmd;
	int			i;

	cmd = (t_command *)node->data;
	ft_printf("COMMAND: ");
	
	if (cmd && cmd->args && cmd->args[0])
	{
		i = 0;
		while (cmd->args[i])
		{
			ft_printf("'%s'", cmd->args[i]);
			if (cmd->args[i + 1])
				ft_printf(" ");
			i++;
		}
	}
	else
		ft_printf("(empty)");
	
	ft_printf("\n");
}

/**
 * @brief Prints group node for debugging
 * 
 * @param node Group node
 * @param level Indentation level
 */
static void	ft_print_group_node(t_ast_node *node, int level)
{
	ft_printf("GROUP (subshell):\n");
	if (node->left)
		ft_print_logical_ast(node->left, level + 1);
}

/**
 * @brief Prints logical AST for debugging
 * 
 * @param node AST node to print
 * @param level Indentation level
 */
void	ft_print_logical_ast(t_ast_node *node, int level)
{
	if (!node)
		return;
	
	ft_print_indent(level);
	
	if (node->type == NODE_AND || node->type == NODE_OR || node->type == NODE_PIPE)
		ft_print_operator_node(node, level);
	else if (node->type == NODE_COMMAND)
		ft_print_command_node(node);
	else if (node->type == NODE_GROUP)
		ft_print_group_node(node, level);
	else
		ft_printf("NODE_TYPE: %d\n", node->type);
}

/**
 * @brief Prints detailed analysis of logical expression
 * 
 * @param shell Shell structure
 */
void	ft_print_logical_analysis(t_shell *shell)
{
	if (!shell)
		return;
	
	ft_printf("=== LOGICAL EXPRESSION ANALYSIS ===\n");
	
	if (!shell->token)
	{
		ft_printf("No tokens to analyze\n");
		return;
	}
	
	// Print operator counts and validation
	ft_debug_logical_operators(shell);
	
	// Print AST structure
	if (shell->ast)
	{
		ft_printf("=== AST STRUCTURE ===\n");
		ft_print_logical_ast(shell->ast, 0);
		ft_printf("\n");
	}
	else
		ft_printf("No AST generated\n\n");
	
	ft_printf("=====================================\n");
}

/**
 * @brief Explains operator precedence for debugging
 */
void	ft_explain_operator_precedence(void)
{
	ft_printf("=== OPERATOR PRECEDENCE ===\n");
	ft_printf("1. | (PIPE)     - Highest precedence\n");
	ft_printf("2. && (AND)     - Medium precedence\n");
	ft_printf("3. || (OR)      - Lowest precedence\n");
	ft_printf("\nEvaluation: left to right at same precedence level\n");
	ft_printf("===========================\n\n");
}
