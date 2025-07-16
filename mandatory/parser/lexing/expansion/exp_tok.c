/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:30:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:22:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Expand a single token
 * 
 * @param shell Shell structure
 * @param token Token to expand
 * @return int 0 on success, -1 on error
 */
static int	ft_expand_single_token(t_shell *shell, t_token *token)
{
	char	*expanded_value;

	if (!token || !token->value || token->type != TOKEN_WORD)
		return (0);
	
	// Check if expansion is needed
	if (!ft_contains_variables(token->value))
		return (0);
	
	expanded_value = ft_expand_token_value(shell, token->value);
	if (!expanded_value)
		return (-1);
	
	free(token->value);
	token->value = expanded_value;
	return (0);
}

/**
 * @brief Split token if it contains spaces after expansion
 * 
 * @param shell Shell structure
 * @param token_node Token node to potentially split
 * @return t_list* New list of tokens, NULL on error
 */
static t_list	*ft_split_expanded_token(t_shell *shell, t_list *token_node)
{
	char		**split_values;
	t_list		*new_tokens;
	t_token		*new_token;
	t_content	content;
	int			i;

	(void)shell; // TODO: May be used for context later
	
	if (!token_node || !token_node->content.token || 
		!token_node->content.token->value)
		return (NULL);
	
	split_values = ft_split(token_node->content.token->value, ' ');
	if (!split_values)
		return (NULL);
	
	new_tokens = NULL;
	i = 0;
	while (split_values[i])
	{
		new_token = malloc(sizeof(t_token));
		if (!new_token)
		{
			ft_free_arr(split_values);
			ft_free_token_list(new_tokens);
			return (NULL);
		}
		new_token->type = TOKEN_WORD;
		new_token->value = ft_strdup(split_values[i]);
		content.token = new_token;
		if (!ft_lstadd_back(&new_tokens, content, TYPE_TOKEN))
		{
			ft_free_token(new_token);
			ft_free_arr(split_values);
			ft_free_token_list(new_tokens);
			return (NULL);
		}
		i++;
	}
	ft_free_arr(split_values);
	return (new_tokens);
}

/**
 * @brief Expand token and handle splitting if necessary
 * 
 * @param shell Shell structure
 * @param token_node Token node to expand
 * @return t_list* List of resulting tokens (may be multiple)
 */
t_list	*ft_expand_token_node(t_shell *shell, t_list *token_node)
{
	t_list	*result;

	if (!shell || !token_node)
		return (NULL);
	
	// First expand the token
	if (ft_expand_single_token(shell, token_node->content.token) == -1)
		return (NULL);
	
	// Check if the expanded value contains spaces (field splitting)
	if (token_node->content.token->value && 
		ft_strchr(token_node->content.token->value, ' '))
	{
		result = ft_split_expanded_token(shell, token_node);
		return (result);
	}
	
	// No splitting needed, return the original token
	result = ft_lstnew_tok(token_node->content.token);
	return (result);
}
