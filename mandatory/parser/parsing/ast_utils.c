/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:05:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Creates command AST node
 * 
 * @param args Command arguments array
 * @param redirs Redirections list
 * @return t_ast_node* New command node
 */
t_ast_node	*ft_create_command_node(char **args, t_list *redirs)
{
	t_command	*cmd;
	t_ast_node	*node;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = args;
	cmd->redirs = redirs;
	node = malloc(sizeof(t_ast_node));
	if (!node)
	{
		free(cmd);
		return (NULL);
	}
	node->type = NODE_COMMAND;
	node->data = cmd;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * @brief Creates operator AST node
 * 
 * @param type Node type (PIPE, AND, OR)
 * @param left Left child node
 * @param right Right child node
 * @return t_ast_node* New operator node
 */
t_ast_node	*ft_create_operator_node(node_type type, t_ast_node *left, 
									t_ast_node *right)
{
	t_ast_node	*node;

	if (type != NODE_PIPE && type != NODE_AND && type != NODE_OR)
		return (NULL);
	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->data = NULL;
	node->left = left;
	node->right = right;
	return (node);
}

/**
 * @brief Creates group AST node
 * 
 * @param content Content of the group
 * @return t_ast_node* New group node
 */
t_ast_node	*ft_create_group_node(t_ast_node *content)
{
	t_ast_node	*node;

	if (!content)
		return (NULL);
	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->type = NODE_GROUP;
	node->data = NULL;
	node->left = content;
	node->right = NULL;
	return (node);
}

/**
 * @brief Frees command structure
 * 
 * @param cmd Command to free
 */
void	ft_free_command(t_command *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->args)
	{
		i = 0;
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
	}
	if (cmd->redirs)
		ft_lstfree_t(cmd->redirs);
	free(cmd);
}

/**
 * @brief Recursively frees AST
 * 
 * @param ast AST node to free
 */
void	ft_free_ast(t_ast_node *ast)
{
	if (!ast)
		return ;
	ft_free_ast(ast->left);
	ft_free_ast(ast->right);
	if (ast->type == NODE_COMMAND)
		ft_free_command((t_command *)ast->data);
	free(ast);
}
