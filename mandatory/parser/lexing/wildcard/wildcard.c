/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:18:03 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:19:40 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"
#include <dirent.h>
#include <sys/stat.h>

/**
 * @brief Main wildcard expansion function
 * 
 * @param shell The shell structure
 * @param tok_h Pointer to token list head
 * @return int 0 on success, -1 on error
 */
int	ft_expand_wildcard(t_shell *shell, t_list **tok_h)
{
	t_list	*tok_curr;
	t_list	*tok_next;
	t_token	*token;

	if (!shell || !tok_h || !*tok_h)
		return (0);
	tok_curr = *tok_h;
	while (tok_curr)
	{
		tok_next = tok_curr->next;
		token = tok_curr->content.token;
		if (ft_needs_wildcard_expansion(token))
		{
			if (token->type == TOKEN_WORD)
				token->type = TOKEN_WILDCARD;
			if (!ft_replace_wildcard_token(tok_h, tok_curr))
				return (-1);
		}
		tok_curr = tok_next;
	}
	return (0);
}

/**
 * @brief Expands wildcards in the token list (public interface)
 * 
 * @param shell The shell structure
 * @param tok_h Pointer to token list head
 */
void	ft_exp_wildcard(t_shell *shell, t_list **tok_h)
{
	if (ft_expand_wildcard(shell, tok_h) < 0)
	{
		ft_printerr("minishell: wildcard expansion failed\n");
		shell->env->last_exit_code = 1;
	}
}

/**
 * @brief Checks if a token contains wildcards that need expansion
 * 
 * @param token Token to check
 * @return bool true if needs expansion, false otherwise
 */
bool	ft_needs_wildcard_expansion(t_token *token)
{
	int	i;

	if (!token || !token->value)
		return (false);
	if (token->type == TOKEN_WILDCARD)
		return (true);
	if (token->type == TOKEN_WORD)
	{
		i = 0;
		while (token->value[i])
		{
			if (ft_is_wildcard_char(token->value[i]))
				return (true);
			i++;
		}
	}
	return (false);
}

/**
 * @brief Checks if a character is a wildcard character
 * 
 * @param c Character to check
 * @return bool true if wildcard, false otherwise
 */
bool	ft_is_wildcard_char(char c)
{
	return (c == '*');
}

/**
 * @brief Replaces a wildcard token with matched filenames
 * 
 * @param tok_h Pointer to token list head
 * @param tok_curr Current wildcard token
 * @return bool true on success, false on error
 */
bool	ft_replace_wildcard_token(t_list **tok_h, t_list *tok_curr)
{
	char	**matches;
	t_list	*new_tokens;
	t_token	*token;

	if (!tok_h || !tok_curr || !tok_curr->content.token)
		return (false);
	token = tok_curr->content.token;
	if (token->type != TOKEN_WILDCARD)
		return (true);
	if (ft_strcmp(token->value, "*") == 0)
		matches = ft_get_matching_files("*");
	else
		matches = ft_get_matching_files(token->value);
	if (!matches)
		return (true);
	new_tokens = ft_create_match_tokens(matches);
	ft_free_arr(matches);
	if (!new_tokens)
		return (false);
	return (ft_connect_new_tokens(tok_h, tok_curr, new_tokens));
}
