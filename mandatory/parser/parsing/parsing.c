/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 15:16:31 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Validates basic syntax of token sequence
 * 
 * @param tokens Token list to validate
 * @return int 0 if valid, -1 if invalid
 */
static int	ft_validate_syntax(t_list *tokens)
{
	t_list	*curr;
	bool	expect_operand;

	if (!tokens)
		return (-1);
	curr = tokens;
	expect_operand = true;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PIPE ||
			curr->content.token->type == TOKEN_AND ||
			curr->content.token->type == TOKEN_OR)
		{
			if (expect_operand || !curr->next)
				return (-1);
			expect_operand = true;
		}
		else if (curr->content.token->type == TOKEN_WORD)
			expect_operand = false;
		curr = curr->next;
	}
	return (0);
}

/**
 * @brief Validates parentheses syntax in token list
 * 
 * @param tokens Token list to validate
 * @return int 0 if valid, -1 if invalid
 */
static int	ft_validate_parentheses(t_list *tokens)
{
	t_list	*curr;
	int		depth;

	curr = tokens;
	depth = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_PAREN_OPEN)
			depth++;
		else if (curr->content.token->type == TOKEN_PAREN_CLOSE)
		{
			depth--;
			if (depth < 0)
				return (-1);
		}
		curr = curr->next;
	}
	if (depth != 0)
		return (-1);
	return (0);
}

/**
 * @brief Preprocesses tokens before parsing
 * 
 * @param shell Shell structure containing tokens
 * @return int 0 on success, -1 on error
 */
static int	ft_preprocess_tokens(t_shell *shell)
{
	if (ft_validate_syntax(shell->token) < 0)
	{
		ft_printf("minishell: syntax error\n");
		return (-1);
	}
	if (ft_validate_parentheses(shell->token) < 0)
	{
		ft_printf("minishell: unmatched parentheses\n");
		return (-1);
	}
	// ft_exp_wildcard(shell, &shell->token);
	return (0);
}

/**
 * @brief Main parsing function - entry point
 * 
 * @param shell Shell structure containing tokenized input
 * @return int 0 on success, -1 on error
 */
int	ft_parsing(t_shell *shell)
{
	if (!shell || !shell->token)
		return (-1);
	shell->token = ft_lexing(shell);
	if (!(shell)->token)
		return (-1);
	if (ft_preprocess_tokens(shell) < 0)
		return (-1);
	shell->ast = ft_parse_expression(shell, shell->token, shell->token, NULL);
	if (!shell->ast)
		return (-1);
	return (0);
}
