/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_to_command_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:15:34 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/16 18:46:06 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	add_command_node(t_list **cmds, t_command *cmd)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_lstnew_cmd(cmd);
	if (!node)
		return ;
	if (!*cmds)
	{
		*cmds = node;
		return ;
	}
	tmp = *cmds;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

t_list	*ast_to_command_list(t_ast_node *ast)
{
	t_list	*cmds;
	t_list	*left;
	t_list	*right;
	t_list	*tmp;

	cmds = NULL;
	if (!ast)
		return (NULL);
	if (ast->type == NODE_PIPE)
	{
		left = ast_to_command_list(ast->left);
		right = ast_to_command_list(ast->right);
		if (!left || !right)
			return (left ? left : right);
		tmp = left;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = right;
		right->prev = tmp;
		return (left);
	}
	if (ast->type == NODE_COMMAND)
		add_command_node(&cmds, (t_command *)ast->data);
	return (cmds);
}
