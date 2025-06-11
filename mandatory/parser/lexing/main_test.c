/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:14:55 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/12 15:45:32 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

static char	*ft_gettype_name_bis(t_token_type type)
{
	if (type == 11)
		return (ft_strdup("QUOTE"));
	if (type == 12)
		return (ft_strdup("DQUOTE"));
	if (type == 13)
		return (ft_strdup("PAREN_OPEN"));
	if (type == 14)
		return (ft_strdup("PAREN_CLOSE"));
	if (type == 15)
		return (ft_strdup("WILDCARD"));
	if (type == 16)
		return (ft_strdup("ASSIGN"));
	if (type == 17)
		return (ft_strdup("EOF"));
	if (type == 18)
		return (ft_strdup("BSLASH"));
	return (ft_strdup("SPACE"));
}

char	*ft_gettype_name(t_token_type type)
{
	if (type == 0)
		return (ft_strdup("WORD"));
	if (type == 1)
		return (ft_strdup("OR"));
	if (type == 2)
		return (ft_strdup("APPEND"));
	if (type == 3)
		return (ft_strdup("HEREDOC"));
	if (type == 4)
		return (ft_strdup("AND"));
	if (type == 5)
		return (ft_strdup("STATUS"));
	if (type == 6)
		return (ft_strdup("ERROR"));
	if (type == 7)
		return (ft_strdup("PIPE"));
	if (type == 8)
		return (ft_strdup("REDIR_OUT"));
	if (type == 9)
		return (ft_strdup("REDIR_IN"));
	if (type == 10)
		return (ft_strdup("VAR"));
	return (ft_gettype_name_bis(type));
}

static void	ft_print_prompt(t_list *tok_h)
{
	t_list	*tok_curr;
	t_token	*tok;

	tok_curr = tok_h;
	ft_printerr("\n\ncmd: '");
	while (tok_curr)
	{
		tok = tok_curr->content.token;
		if (!tok)
			break ;
		ft_printerr("%s", tok->value);
		tok_curr = tok_curr->next;
	}
	ft_printerr("'\n\n");
}

/**
 * @brief Prints the token list for debugging purposes
 * 
 * @param tok_h Head of the token list
 */
void	ft_print_list(t_list *tok_h)
{
	t_list	*tok_curr;
	t_token	*tok;
	char	*name;

	if (!tok_h)
		return ;
	tok_curr = tok_h;
	ft_printerr("\n");
	while (tok_curr)
	{
		tok = tok_curr->content.token;
		if (!tok)
			break ;
		name = ft_gettype_name(tok->type);
		if (!name)
			return ;
		ft_printerr("%s: %s\n", tok->value, name);
		free(name);
		tok_curr = tok_curr->next;
	}
	ft_print_prompt(tok_h);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	t_list	*head;

	if (argc != 2)
	{
		ft_printerr("Please enter an argument to lexe...\n");
		return (0);
	}
	ft_setup(&shell, env);
	shell.current_line = argv[1];
	head = ft_lexing(&shell);
	if (!head)
		return (1);
	ft_print_list(shell.token);
	ft_lstfree_t(shell.token);
	if (shell.env)
	{
		if (shell.env->local_env)
			free(shell.env->local_env);
		free(shell.env);
	}
	return (0);
}
