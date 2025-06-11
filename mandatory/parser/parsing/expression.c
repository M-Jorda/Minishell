/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:09:58 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Finds operator at current parentheses level
 * 
 * @param start Start of token sequence
 * @param end End of token sequence
 * @param target Target token type to find
 * @return t_list* Found operator token or NULL
 */
static t_list	*ft_find_operator(t_list *start, t_list *end, 
									t_token_type target)
{
	t_list	*curr;
	int		depth;

	curr = start;
	depth = 0;
	while (curr && curr != end)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
			depth--;
		else if (depth == 0 && curr->content.token->type == target)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

/**
 * @brief Finds matching closing parenthesis
 * 
 * @param open Opening parenthesis token
 * @return t_list* Matching closing parenthesis or NULL
 */
static t_list	*ft_find_closing_paren(t_list *open)
{
	t_list	*curr;
	int		depth;

	if (!open || open->content.token->type != TOKEN_PAREN_OPEN)
		return (NULL);
	curr = open->next;
	depth = 1;
	while (curr && depth > 0)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
			depth--;
		if (depth == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

/**
 * @brief Parses parenthesized group
 * 
 * @param start Opening parenthesis
 * @param end Closing parenthesis
 * @return t_ast_node* Group AST node
 */
t_ast_node	*ft_parse_group(t_shell *shell, t_list *token_h, t_list *start, t_list *end)
{
	t_ast_node	*content;

	if (!start || !end || start->next == end)
		return (NULL);
	content = ft_parse_expression(shell, token_h, start->next, end);
	if (!content)
		return (NULL);
	return (ft_create_group_node(content));
}

/**
 * @brief Main expression parser with operator precedence
 * 
 * @param shell Shell structure
 * @param token_h Token list head
 * @param start Start of expression
 * @param end End of expression (exclusive)
 * @return t_ast_node* AST representing the expression
 */
t_ast_node	*ft_parse_expression(t_shell *shell, t_list *token_h,
									t_list *start, t_list *end)
{
	t_list		*op;
	t_list		*close_paren;
	t_ast_node	*left;
	t_ast_node	*right;

	if (!start || start == end)
		return (NULL);
	if (start->content.token->type == TOKEN_PAREN_OPEN)
	{
		close_paren = ft_find_closing_paren(start);
		if (close_paren && (!end || close_paren->next == end))
			return (ft_parse_group(shell, token_h, start, close_paren));
	}
	op = ft_find_operator(start, end, TOKEN_OR);
	if (!op)
		op = ft_find_operator(start, end, TOKEN_AND);
	if (!op)
		op = ft_find_operator(start, end, TOKEN_PIPE);
	if (op)
	{
		left = ft_parse_expression(shell, token_h, start, op);
		right = ft_parse_expression(shell, token_h, op->next, end);
		if (!left || !right)
		{
			ft_free_ast(left);
			ft_free_ast(right);
			return (NULL);
		}
		if (op->content.token->type == TOKEN_PIPE)
			return (ft_create_operator_node(NODE_PIPE, left, right));
		else if (op->content.token->type == TOKEN_AND)
			return (ft_create_operator_node(NODE_AND, left, right));
		else if (op->content.token->type == TOKEN_OR)
			return (ft_create_operator_node(NODE_OR, left, right));
	}
	return (ft_parse_command(start, end));
}
