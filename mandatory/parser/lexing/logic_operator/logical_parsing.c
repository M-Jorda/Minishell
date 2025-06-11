/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/01 14:14:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Main function to parse logical operators in token list
 * 
 * @param shell The shell structure containing tokens
 * @return int 0 on success, -1 on error
 */
int	ft_parse_logical_operators(t_shell *shell)
{
	if (!shell || !shell->token)
		return (-1);
	
	// Validate logical operator syntax
	if (!ft_validate_logical_syntax(shell->token))
	{
		ft_printerr("minishell: syntax error near logical operators\n");
		return (-1);
	}
	
	// Parse the expression with logical operators
	shell->ast = ft_parse_logical_expression(shell, shell->token, NULL);
	if (!shell->ast)
	{
		ft_printerr("minishell: failed to parse logical expression\n");
		return (-1);
	}
	
	return (0);
}

/**
 * @brief Validates logical operator syntax in token list
 * 
 * @param token_h Head of token list
 * @return bool true if syntax is valid, false otherwise
 */
bool	ft_validate_logical_syntax(t_list *token_h)
{
	t_list	*curr;
	bool	prev_was_operator;
	bool	has_command;

	if (!token_h)
		return (false);
	
	curr = token_h;
	prev_was_operator = true; // Start as if previous was operator to catch leading operators
	has_command = false;
	
	while (curr)
	{
		if (ft_is_logical_operator_token(curr->content.token))
		{
			// Two consecutive operators or operator at start/end
			if (prev_was_operator || !curr->next)
				return (false);
			prev_was_operator = true;
		}
		else if (curr->content.token->type == TOKEN_WORD ||
				 curr->content.token->type == TOKEN_PAREN_OPEN)
		{
			prev_was_operator = false;
			has_command = true;
		}
		// Skip other tokens (redirections, etc.)
		
		curr = curr->next;
	}
	
	// Must have at least one command and not end with operator
	return (has_command && !prev_was_operator);
}

/**
 * @brief Checks if a token is a logical operator
 * 
 * @param token Token to check
 * @return bool true if logical operator, false otherwise
 */
bool	ft_is_logical_operator_token(t_token *token)
{
	if (!token)
		return (false);
	
	return (token->type == TOKEN_AND || 
			token->type == TOKEN_OR || 
			token->type == TOKEN_PIPE);
}

/**
 * @brief Gets operator precedence level
 * 
 * @param type Token type
 * @return int Precedence level (higher = more precedent)
 */
int	ft_get_operator_precedence(t_token_type type)
{
	if (type == TOKEN_PIPE)
		return (3); // Highest precedence
	else if (type == TOKEN_AND)
		return (2); // Medium precedence
	else if (type == TOKEN_OR)
		return (1); // Lowest precedence
	else
		return (0); // Not an operator
}

/**
 * @brief Converts token type to AST node type
 * 
 * @param token_type Token type
 * @return node_type Corresponding AST node type
 */
node_type	ft_token_to_node_type(t_token_type token_type)
{
	if (token_type == TOKEN_PIPE)
		return (NODE_PIPE);
	else if (token_type == TOKEN_AND)
		return (NODE_AND);
	else if (token_type == TOKEN_OR)
		return (NODE_OR);
	else
		return (NODE_COMMAND); // Default fallback
}
