/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:45:35 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/11 10:57:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

static inline void	ft_freelst(t_list *lst, int type)
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr)
	{
		lst = curr->next;
		if (type == 1)
			free(curr->content.token);
		else if (type == 2)
		{
			free(curr->content.redir->file);
			free(curr->content.redir);
		}
		else if (type == 3)
		{
			ft_free_vctr((void **) curr->content.cmd->args);
			free(curr->content.cmd);
		}
		else
			free(curr->content.generic);
		curr = lst;
	}
}

static inline void	ft_freeast(t_ast_node *ast)
{
	t_command	*cmd;
	// t_redir		*red;

	if (!ast)
		return ;
	if (ast->type == NODE_REDIR)
		ft_freelst(ast->data, 2);
	else if (ast->type == NODE_COMMAND)
	{
		cmd = (t_command *) ast->data;
		ft_free_vctr((void **) cmd->args);
		if (cmd->redirs)
			ft_freelst(cmd->redirs, 3);
		free(ast->data);
	}
	ft_freeast(ast->left);
	ft_freeast(ast->right);
}

static inline void	ft_freetoken(t_list *tok_h)
{
	t_list	*tok_c;

	if (!tok_h)
		return ;
	tok_c = tok_h;
	while (tok_c)
	{
		tok_h = tok_c->next;
		free(tok_c->content.token->value);
		free(tok_c->content.token);
		tok_c->content.token = NULL;
		tok_c = tok_h;
	}
}

void	ft_freeenv(t_env *env)
{
	if (!env)
		return ;
	if (env->local_env)
		ft_free_vctr((void **) env->local_env);
	free(env);
	env = NULL;
}

// TODO: clean of the 't_list **cmd'
void	ft_cleanup(t_shell *shell, int status)
{
	if (!shell)
		return ;
	ft_freeenv(shell->env);
	ft_freetoken(shell->token);
	ft_freeast(shell->ast);
	if (status)
		exit(status);
}
