/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:02:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/11 11:20:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Finds matching closing parenthesis
 * 
 * @param start Token with opening parenthesis
 * @return t_list* Matching closing parenthesis token
 */
t_list	*ft_find_matching_paren(t_list *start)
{
	t_list	*curr;
	int		depth;

	if (!start || start->content.token->type != TOKEN_PAREN_OPEN)
		return (NULL);
	curr = start->next;
	depth = 1;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
		{
			depth--;
			if (depth == 0)
				return (curr);
		}
		curr = curr->next;
	}
	return (NULL);
}

/**
 * @brief Validates parentheses syntax
 * 
 * @param token_h Token list head
 * @return bool true if valid, false otherwise
 */
bool	ft_validate_parentheses(t_list *token_h)
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
	return (depth == 0);
}

/**
 * @brief Parses a group (parentheses)
 * 
 * @param shell Shell structure
 * @param start Opening parenthesis token
 * @param end Closing parenthesis token
 * @return t_ast_node* Group AST node
 */
t_ast_node	*ft_parse_group(t_shell *shell, t_list *start, t_list *end)
{
	t_ast_node	*content;

	if (!shell || !start || !end)
		return (NULL);
	if (start->next == end)
		return (NULL);
	content = ft_parse_expression(shell, shell->token, start->next, end);
	if (!content)
		return (NULL);
	return (ft_create_group_node(content));
}

/**
 * @brief Checks if expression is wrapped in parentheses
 * 
 * @param start Start token
 * @param end End token
 * @return bool true if wrapped, false otherwise
 */
bool	ft_is_wrapped_in_parens(t_list *start, t_list *end)
{
	t_list	*closing;

	if (!start || start->content.token->type != TOKEN_PAREN_OPEN)
		return (false);
	closing = ft_find_matching_paren(start);
	if (!closing)
		return (false);
	if (end && closing->next != end)
		return (false);
	if (!end && closing->next != NULL)
		return (false);
	return (true);
}

/**
 * @brief Parses expressions with parentheses support
 * 
 * @param shell The shell structure
 * @param token_h Head of the token list
 * @param start Start of the expression
 * @param end End of the expression
 * @return t_ast_node* AST node representing the expression
 */
t_ast_node	*ft_parse_expression(t_shell *shell, t_list *token_h,
		t_list *start, t_list *end)
{
	t_list	*closing;

	if (!shell || !start)
		return (NULL);
	if (ft_is_wrapped_in_parens(start, end))
	{
		closing = ft_find_matching_paren(start);
		return (ft_parse_group(shell, start, closing));
	}
	return (ft_parse_expression(shell, token_h, start, end));
}
