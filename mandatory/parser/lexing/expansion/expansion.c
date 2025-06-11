/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:05:32 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/14 13:56:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

static char	*ft_setstr(char *str, char *var_value, int var_name_len,
		int var_pos)
{
	char	*new_str;
	int		i[3];

	if (!str || !var_value || var_pos < 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(str) - var_name_len - 1 + ft_strlen(var_value) + 1));
	if (!new_str)
	{
		free(var_value);
		return (NULL);
	}
	i[0] = 0;
	i[1] = 0;
	while (i[0] < var_pos - 1)
		new_str[i[1]++] = str[i[0]++];
	i[0] = var_pos + var_name_len;
	i[2] = 0;
	while (var_value[i[2]])
		new_str[i[1]++] = var_value[i[2]++];
	while (str[i[0]])
		new_str[i[1]++] = str[i[0]++];
	new_str[i[1]] = '\0';
	return (new_str);
}

/**
 * @brief Expands a variable in a string to its value
 * 
 * @param shell The shell structure
 * @param tok_c Current token node
 * @param str The string containing the variable
 * @param var_pos Position of the variable in the string
 * @return bool true on success, false on error
 */
bool	ft_expand_var(t_shell *shell, t_list *tok_c, char *str, int var_pos)
{
	char	*new_str;
	char	*var_value;
	int		var_name_len;

	if (!shell || !tok_c || !str || var_pos < 0)
		return (false);
	var_name_len = ft_eov(&str[var_pos]);
	if (var_name_len <= 0)
		return (false);
	var_value = ft_getenv_value(shell, str, var_pos, var_name_len);
	if (!var_value)
		return (false);
	new_str = ft_setstr(str, var_value, var_name_len, var_pos);
	if (!new_str)
		return (false);
	free(var_value);
	free(str);
	tok_c->content.token->value = new_str;
	return (true);
}

static int	ft_get_exp(t_shell *shell, t_list **tok_h,
		t_list **tok_c, t_list **tok_n)
{
	t_token	*token;
	char	c;

	if (!shell || !(*tok_h) || !(*tok_c) || !(*tok_n))
		return (-1);
	token = (*tok_c)->content.token;
	c = token->value[0];
	if (token->type == TOKEN_STATUS)
	{
		free(token->value);
		token->value = ft_itoa(shell->env->last_exit_code);
		if (!token->value)
			return (-1);
		token->type = TOKEN_WORD;
	}
	else if (token->type == TOKEN_VAR && (c && (ft_isalnum(c) || c == '_')))
	{
		ft_printerr("GETEXP: %s: %d\n", token->value, token->type);
		c = token->value[0];
		if (c && (ft_isalnum(c) || c == '_'))
			*tok_c = ft_expand_token(shell, tok_h, tok_c);
		if (!(*tok_c))
			return (-1);
	}
	return (0);
}

/**
 * @brief Main expansion function to process all token expansions
 * 
 * @param shell The shell structure
 * @param tok_h The token list head
 * @param status Pointer to status variable
 * @return int 0 on success, -1 on error
 */
int	ft_expansion(t_shell *shell, t_list **tok_h, int *status)
{
	t_list	*tok_c;
	t_list	*tok_n;
	t_token	*token;

	if (!shell || !(*tok_h) || !status)
		return (-1);
	tok_c = *tok_h;
	while (tok_c)
	{
		token = tok_c->content.token;
		tok_n = tok_c->next;
		if (token->type == TOKEN_STATUS || token->type == TOKEN_VAR)
		{
			if (ft_get_exp(shell, tok_h, &tok_c, &tok_n) == -1)
				return (-1);
		}
		else if (token->type == TOKEN_DQUOTE)
		{
			if (!ft_expand_dquote(shell, tok_c, status))
				return (-1);
		}
		tok_c = tok_n;
	}
	return (0);
}
