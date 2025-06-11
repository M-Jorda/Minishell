/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:06:09 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Checks if token type is a redirection operator
 * 
 * @param type Token type to check
 * @return bool true if redirection, false otherwise
 */
bool	ft_is_redirect_token(t_token_type type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT ||
		type == TOKEN_HEREDOC || type == TOKEN_APPEND)
		return (true);
	return (false);
}

/**
 * @brief Converts token type to redirection type
 * 
 * @param token_type Token type
 * @return redir_type Corresponding redirection type
 */
static redir_type	ft_token_to_redir_type(t_token_type token_type)
{
	if (token_type == TOKEN_REDIR_IN)
		return (REDIR_IN);
	else if (token_type == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	else if (token_type == TOKEN_HEREDOC)
		return (REDIR_HEREDOC);
	else if (token_type == TOKEN_APPEND)
		return (REDIR_APPEND);
	return (REDIR_IN);
}

/**
 * @brief Creates redirection structure
 * 
 * @param type Redirection type
 * @param filename Target filename
 * @return t_redir* New redirection structure
 */
static t_redir	*ft_create_redirection(redir_type type, char *filename)
{
	t_redir	*redir;

	if (!filename)
		return (NULL);
	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = ft_strdup(filename);
	if (!redir->file)
	{
		free(redir);
		return (NULL);
	}
	redir->fd = -1;
	return (redir);
}

/**
 * @brief Adds redirection to command's redirection list
 * 
 * @param cmd Command to add redirection to
 * @param redir Redirection to add
 * @return int 0 on success, -1 on error
 */
static int	ft_add_redirection(t_command *cmd, t_redir *redir)
{
	t_content	content;

	if (!cmd || !redir)
		return (-1);
	content.redir = redir;
	if (!ft_lstadd_back(&cmd->redirs, content, TYPE_REDIR))
		return (-1);
	return (0);
}

/**
 * @brief Parses redirections from token sequence
 * 
 * @param shell Shell structure
 * @param token_h Token list head
 * @param cmd Command to add redirections to
 * @return int 0 on success, -1 on error
 */
int	ft_parse_redirections(t_shell *shell, t_list *token_h, t_command *cmd)
{
	t_list		*curr;
	t_redir		*redir;
	redir_type	type;

	if (!shell || !token_h || !cmd)
		return (-1);
	curr = token_h;
	while (curr)
	{
		if (ft_is_redirect_token(curr->content.token->type))
		{
			if (!curr->next || !curr->next)
				return (-1);
			type = ft_token_to_redir_type(curr->content.token->type);
			redir = ft_create_redirection(type, 
				curr->next->content.token->value);
			if (!redir || ft_add_redirection(cmd, redir) < 0)
			{
				if (redir)
				{
					free(redir->file);
					free(redir);
				}
				return (-1);
			}
			curr = curr->next;
		}
		curr = curr->next;
	}
	return (0);
}
