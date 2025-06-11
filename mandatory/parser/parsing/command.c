/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:11:13 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Counts word tokens in command sequence
 * 
 * @param start Start of command tokens
 * @param end End of command tokens
 * @return int Number of word tokens
 */
static int	ft_count_args(t_list *start, t_list *end)
{
	t_list	*curr;
	int		count;

	curr = start;
	count = 0;
	while (curr && curr != end)
	{
		if (curr->content.token->type == TOKEN_WORD ||
			curr->content.token->type == TOKEN_VAR ||
			curr->content.token->type == TOKEN_WILDCARD)
			count++;
		else if (ft_is_redirect_token(curr->content.token->type))
			curr = curr->next;
		if (curr)
			curr = curr->next;
	}
	return (count);
}

/**
 * @brief Allocates and fills command arguments array
 * 
 * @param start Start of command tokens
 * @param end End of command tokens
 * @param arg_count Number of arguments
 * @return char** Array of argument strings
 */
static char	**ft_build_args(t_list *start, t_list *end, int arg_count)
{
	char	**args;
	t_list	*curr;
	int		i;

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	curr = start;
	i = 0;
	while (curr && curr != end && i < arg_count)
	{
		if (curr->content.token->type == TOKEN_WORD ||
			curr->content.token->type == TOKEN_VAR ||
			curr->content.token->type == TOKEN_WILDCARD)
		{
			args[i] = ft_strdup(curr->content.token->value);
			if (!args[i])
			{
				while (--i >= 0)
					free(args[i]);
				free(args);
				return (NULL);
			}
			i++;
		}
		else if (ft_is_redirect_token(curr->content.token->type))
			curr = curr->next;
		if (curr)
			curr = curr->next;
	}
	args[arg_count] = NULL;
	return (args);
}

/**
 * @brief Creates command structure from tokens
 * 
 * @param start Start of command tokens
 * @param end End of command tokens
 * @return t_command* New command structure
 */
// static t_command	*ft_create_command_struct(t_list *start, t_list *end)
// {
// 	t_command	*cmd;
// 	int			arg_count;

// 	arg_count = ft_count_args(start, end);
// 	cmd = malloc(sizeof(t_command));
// 	if (!cmd)
// 		return (NULL);
// 	cmd->args = ft_build_args(start, end, arg_count);
// 	if (!cmd->args)
// 	{
// 		free(cmd);
// 		return (NULL);
// 	}
// 	cmd->redirs = NULL;
// 	return (cmd);
// }

/**
 * @brief Parses a command sequence into AST node
 * 
 * @param start Start of command tokens
 * @param end End of command tokens
 * @return t_ast_node* Command AST node
 */
t_ast_node	*ft_parse_command(t_list *start, t_list *end)
{
	// t_command	*cmd;
	char		**args;
	int			arg_count;

	if (!start || start == end)
		return (NULL);
	arg_count = ft_count_args(start, end);
	args = ft_build_args(start, end, arg_count);
	if (!args)
		return (NULL);
	return (ft_create_command_node(args, NULL));
}
