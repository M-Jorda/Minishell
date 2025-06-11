/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:38:02 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/11 12:41:52 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

static bool	ft_setstatus(int *status)
{
	*status = -1;
	return (false);
}

/**
 * @brief Processes expansions within a double-quoted string
 * 
 * @param shell The shell structure
 * @param tok_c Current token node
 * @param status Pointer to status variable
 * @return bool true on success, false on error
 */
bool	ft_expand_dquote(t_shell *shell, t_list *tok_c, int *status)
{
	t_token	*token;
	int		i;

	if (!shell || !tok_c || !status)
		return (false);
	token = tok_c->content.token;
	i = -1;
	while (token->value[++i])
	{
		if (token->value[i] == DOLL && token->value[i + 1] == Q_MRK)
		{
			if (!ft_expand_status(shell, tok_c, token->value))
				ft_setstatus(status);
			i = 0;
		}
		else if (token->value[i] == DOLL && (ft_isalpha(token->value[i + 1])
				|| token->value[i + 1] == '_'))
		{
			if (!ft_expand_var(shell, tok_c, token->value, i + 1))
				ft_setstatus(status);
			i = 0;
		}
	}
	return (true);
}
