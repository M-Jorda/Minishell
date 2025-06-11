/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:42:20 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/14 16:18:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Expands a variable token into its value
 * 
 * @param shell The shell structure
 * @param tok_h The token list head
 * @param tok_c Current token node
 * @param tok_n Next token node
 * @return t_list* Updated current token
 */
t_list	*ft_expand_token(t_shell *shell, t_list **tok_h,
		t_list **tok_c)
{
	t_token	*token;
	char	*var;
	// t_token	*new_token;
	// t_list	*new_node;

	if (!shell || !(*tok_h) || !(*tok_c) || !(*tok_c)->content.token)
		return (NULL);
	token = (*tok_c)->content.token;
	var = token->value;
	var = ft_getenv_value(shell, var, 0, ft_strlen(var));
	free(token->value);
	token->value = var;
	token->type = TOKEN_WORD;
	return (*tok_c);
}
