/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:08:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:34:04 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Counts parentheses depth at a specific position
 * 
 * @param token_h Token list head
 * @param target Target token position
 * @return int Depth at target position
 */
int	ft_get_paren_depth(t_list *token_h, t_list *target)
{
	t_list	*curr;
	int		depth;

	if (!token_h || !target)
		return (0);
	curr = token_h;
	depth = 0;
	while (curr && curr != target)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
			depth--;
		curr = curr->next;
	}
	return (depth);
}

/**
 * @brief Finds the next token at the same parentheses level
 * 
 * @param start Starting token
 * @param target_type Type of token to find
 * @return t_list* Found token or NULL
 */
t_list	*ft_find_token_at_level(t_list *start, t_token_type target_type)
{
	t_list	*curr;
	int		depth;

	if (!start)
		return (NULL);
	curr = start;
	depth = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
			depth--;
		else if (depth == 0 && curr->content.token->type == target_type)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

/**
 * @brief Skips to the end of a parentheses group
 * 
 * @param start Opening parenthesis token
 * @return t_list* Token after closing parenthesis
 */
t_list	*ft_skip_paren_group(t_list *start)
{
	t_list	*closing;

	if (!start || start->content.token->type != TOKEN_PAREN_OPEN)
		return (start);
	closing = ft_find_matching_paren(start);
	if (!closing)
		return (start);
	return (closing->next);
}

/**
 * @brief Checks if a token is inside parentheses
 * 
 * @param token_h Token list head
 * @param target Target token
 * @return bool true if inside parentheses, false otherwise
 */
bool	ft_is_token_in_parens(t_list *token_h, t_list *target)
{
	int	depth;

	if (!token_h || !target)
		return (false);
	depth = ft_get_paren_depth(token_h, target);
	return (depth > 0);
}

/**
 * @brief Gets the outermost parentheses pair containing a token
 * 
 * @param token_h Token list head
 * @param target Target token
 * @param open_paren Pointer to store opening parenthesis
 * @param close_paren Pointer to store closing parenthesis
 * @return bool true if found, false otherwise
 */
bool	ft_get_outermost_parens(t_list *token_h, t_list *target,
		t_list **open_paren, t_list **close_paren)
{
	t_list	*curr;
	int		depth;
	int		target_depth;

	if (!token_h || !target || !open_paren || !close_paren)
		return (false);
	target_depth = ft_get_paren_depth(token_h, target);
	if (target_depth == 0)
		return (false);
	curr = token_h;
	depth = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
		{
			if (depth == 0)
				*open_paren = curr;
			depth++;
		}
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
		{
			depth--;
			if (depth == 0)
				*close_paren = curr;
		}
		if (curr == target && depth > 0)
			return (true);
		curr = curr->next;
	}
	return (false);
}
