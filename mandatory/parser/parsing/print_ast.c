/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:05:26 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Gets string representation of node type
 * 
 * @param type AST node type
 * @return char* String representation
 */
static char	*ft_get_node_type_str(node_type type)
{
	if (type == NODE_COMMAND)
		return ("COMMAND");
	else if (type == NODE_PIPE)
		return ("PIPE");
	else if (type == NODE_AND)
		return ("AND");
	else if (type == NODE_OR)
		return ("OR");
	else if (type == NODE_GROUP)
		return ("GROUP");
	return ("UNKNOWN");
}

/**
 * @brief Prints indentation for tree structure
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
 * @brief Prints command details
 * 
 * @param cmd Command structure
 * @param level Indentation level
 */
static void	ft_print_command_details(t_command *cmd, int level)
{
	int		i;
	t_list	*redir_curr;

	if (!cmd)
		return ;
	ft_print_indent(level);
	ft_printf("Args: ");
	if (cmd->args)
	{
		i = 0;
		while (cmd->args[i])
		{
			ft_printf("\"%s\"", cmd->args[i]);
			if (cmd->args[i + 1])
				ft_printf(" ");
			i++;
		}
	}
	ft_printf("\n");
	if (cmd->redirs)
	{
		ft_print_indent(level);
		ft_printf("Redirections:\n");
		redir_curr = cmd->redirs;
		while (redir_curr)
		{
			ft_print_indent(level + 1);
			ft_printf("- Type: %d, File: \"%s\"\n", 
				redir_curr->content.redir->type,
				redir_curr->content.redir->file);
			redir_curr = redir_curr->next;
		}
	}
}

/**
 * @brief Prints operator node information
 * 
 * @param ast Operator AST node
 * @param level Indentation level
 */
static void	ft_print_operator_info(t_ast_node *ast, int level)
{
	if (ast->type == NODE_PIPE)
		ft_printf(" (|)\n");
	else if (ast->type == NODE_AND)
		ft_printf(" (&&)\n");
	else if (ast->type == NODE_OR)
		ft_printf(" (||)\n");
	else
		ft_printf("\n");
	if (ast->left)
	{
		ft_print_indent(level + 1);
		ft_printf("LEFT:\n");
		ft_print_ast_tree(ast->left, level + 2);
	}
	if (ast->right)
	{
		ft_print_indent(level + 1);
		ft_printf("RIGHT:\n");
		ft_print_ast_tree(ast->right, level + 2);
	}
}

/**
 * @brief Recursively prints AST structure
 * 
 * @param ast AST node to print
 * @param level Current indentation level
 */
void	ft_print_ast_tree(t_ast_node *ast, int level)
{
	if (!ast)
	{
		ft_print_indent(level);
		ft_printf("(null)\n");
		return ;
	}
	ft_print_indent(level);
	ft_printf("%s", ft_get_node_type_str(ast->type));
	if (ast->type == NODE_COMMAND)
	{
		ft_printf("\n");
		ft_print_command_details((t_command *)ast->data, level + 1);
	}
	else if (ast->type == NODE_GROUP)
	{
		ft_printf(" (subshell)\n");
		if (ast->left)
			ft_print_ast_tree(ast->left, level + 1);
	}
	else
		ft_print_operator_info(ast, level);
}
