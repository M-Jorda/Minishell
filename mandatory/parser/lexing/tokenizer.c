/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 21:31:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/minishell.h"

/**
 * @brief Create and add token to list
 * 
 * @param type Token type
 * @param value Token value
 * @param token_list Token list to add to
 * @return int 0 on success, -1 on error
 */
static int	ft_create_and_add_token(t_token_type type, char *value, t_list **token_list)
{
	t_token		*token;
	t_content	content;

	token = malloc(sizeof(t_token));
	if (!token)
		return (-1);
	token->type = type;
	token->value = value;
	content.token = token;
	if (!ft_lstadd_back(token_list, content, TYPE_TOKEN))
	{
		free(token);
		if (value)
			free(value);
		return (-1);
	}
	return (0);
}

/**
 * @brief Read a word token from input
 * 
 * @param input Input string
 * @param pos Position pointer
 * @return char* Word value, NULL on error
 */
static char	*ft_read_word(char *input, int *pos)
{
	int		start;
	int		len;
	char	*word;

	start = *pos;
	while (input[*pos] && !ft_isspace(input[*pos]) && 
		   !ft_is_operator_char(input[*pos]))
		(*pos)++;
	len = *pos - start;
	if (len == 0)
		return (NULL);
	word = ft_substr(input, start, len);
	return (word);
}

/**
 * @brief Handle pipe operators (| and ||)
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token_list Token list to add to
 * @return int 0 on success, -1 on error
 */
static int	ft_handle_pipe(char *input, int *pos, t_list **token_list)
{
	if (input[*pos + 1] == '|')
	{
		*pos += 2;
		return (ft_create_and_add_token(TOKEN_OR, ft_strdup("||"), token_list));
	}
	else
	{
		(*pos)++;
		return (ft_create_and_add_token(TOKEN_PIPE, ft_strdup("|"), token_list));
	}
}

/**
 * @brief Tokenize next element from input
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token_list Token list to add to
 * @param shell Shell structure
 * @return int 0 on success, -1 on error
 */
int	ft_tokenize_next(char *input, int *pos, t_list **token_list, t_shell *shell)
{
	char	*word;

	(void)shell; // TODO: Will be used for expansion later
	
	if (input[*pos] == '|')
		return (ft_handle_pipe(input, pos, token_list));
	else if (input[*pos] == '>')
	{
		(*pos)++;
		return (ft_create_and_add_token(TOKEN_REDIR_OUT, ft_strdup(">"), token_list));
	}
	else if (input[*pos] == '<')
	{
		(*pos)++;
		return (ft_create_and_add_token(TOKEN_REDIR_IN, ft_strdup("<"), token_list));
	}
	else
	{
		word = ft_read_word(input, pos);
		if (!word)
			return (-1);
		return (ft_create_and_add_token(TOKEN_WORD, word, token_list));
	}
}
