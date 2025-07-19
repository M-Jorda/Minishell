/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:24:16 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/11 11:40:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Frees an entire token list
 * 
 * @param tok_h Head of the token list
 * @return void* Always NULL
 */
void	*ft_lstfree_t(t_list *tok_h)
{
	t_list	*current;
	t_list	*next;

	if (!tok_h)
		return (NULL);
	current = tok_h;
	while (current)
	{
		next = current->next;
		ft_clean_node_tok(current);
		current = next;
	}
	return (NULL);
}

/**
 * @brief Sets a status code and returns NULL
 * 
 * @param p_status Pointer to status variable
 * @param status Status code to set
 * @return void* Always NULL
 */
void	*ft_tok_err(int *p_status, int status)
{
	if (p_status)
		*p_status = status;
	return (NULL);
}

int	ft_new_token_err(t_token *token, int ret)
{
	if (token)
		free(token);
	return (ret);
}

/**
 * @brief Performs basic syntax validation on the token list
 * 
 * @param shell The shell structure
 * @return int 0 on success, negative value on error
 */
int	ft_lexer_checker(t_shell *shell)
{
	t_list	*curr;
	t_token	*token;

	if (!shell || !shell->token)
		return (-1);
	curr = shell->token;
	while (curr)
	{
		token = curr->content.token;
		if (!token)
			return (-1);
		if (token->type == TOKEN_ERROR)
			return (-2);
		curr = curr->next;
	}
	return (0);
}
