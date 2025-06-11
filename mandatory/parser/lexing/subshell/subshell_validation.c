/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:06:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:31:32 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Checks if parentheses are balanced
 * 
 * @param token_h Token list head
 * @return int 0 if balanced, negative if error
 */
int	ft_check_paren_balance(t_list *token_h)
{
	t_list	*curr;
	int		open_count;
	int		close_count;

	if (!token_h)
		return (0);
	curr = token_h;
	open_count = 0;
	close_count = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			open_count++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
			close_count++;
		curr = curr->next;
	}
	if (open_count != close_count)
		return (-1);
	return (0);
}

/**
 * @brief Validates parentheses order and structure
 * 
 * @param token_h Token list head
 * @return bool true if valid order, false otherwise
 */
bool	ft_validate_paren_order(t_list *token_h)
{
	t_list	*curr;
	int		depth;

	if (!token_h)
		return (true);
	curr = token_h;
	depth = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
		{
			depth--;
			if (depth < 0)
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}

/**
 * @brief Checks if parentheses contain valid content
 * 
 * @param start Opening parenthesis
 * @param end Closing parenthesis
 * @return bool true if valid content, false otherwise
 */
bool	ft_validate_paren_content(t_list *start, t_list *end)
{
	t_list	*curr;

	if (!start || !end)
		return (false);
	if (start->next == end)
		return (false);
	curr = start->next;
	while (curr && curr != end)
	{
		if (curr->content.token->type != TOKEN_SPACE)
			return (true);
		curr = curr->next;
	}
	return (false);
}

/**
 * @brief Validates complete parentheses syntax
 * 
 * @param token_h Token list head
 * @return bool true if all validations pass, false otherwise
 */
bool	ft_validate_parentheses_complete(t_list *token_h)
{
	if (!token_h)
		return (true);
	if (ft_check_paren_balance(token_h) < 0)
		return (false);
	if (!ft_validate_paren_order(token_h))
		return (false);
	return (ft_validate_all_paren_pairs(token_h));
}

/**
 * @brief Validates all parentheses pairs in the token list
 * 
 * @param token_h Token list head
 * @return bool true if all pairs are valid, false otherwise
 */
bool	ft_validate_all_paren_pairs(t_list *token_h)
{
	t_list	*curr;
	t_list	*closing;

	if (!token_h)
		return (true);
	curr = token_h;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
		{
			closing = ft_find_matching_paren(curr);
			if (!closing)
				return (false);
			if (!ft_validate_paren_content(curr, closing))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
