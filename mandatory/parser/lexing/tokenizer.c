/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:15:24 by jjorda           ###   ########.fr       */
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
 * @brief Read a word token from input with expansion
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param shell Shell structure for expansion
 * @return char* Word value, NULL on error
 */
static char	*ft_read_word_with_expansion(char *input, int *pos, t_shell *shell)
{
	int		start;
	int		len;
	char	*word;
	char	*expanded_word;

	start = *pos;
	while (input[*pos] && !ft_isspace(input[*pos]) && 
		   !ft_is_operator_char(input[*pos]))
		(*pos)++;
	len = *pos - start;
	if (len == 0)
		return (NULL);
	word = ft_substr(input, start, len);
	if (!word)
		return (NULL);
	
	// Expand variables if needed
	if (ft_contains_variables(word))
	{
		expanded_word = ft_process_var_expansion(shell, word);
		expanded_word = ft_process_exit_code_expansion(shell, expanded_word);
		free(word);
		return (expanded_word);
	}
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
 * @brief Handle redirection operators (>, >>, <, <<)
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token_list Token list to add to
 * @return int 0 on success, -1 on error
 */
static int	ft_handle_redirection(char *input, int *pos, t_list **token_list)
{
	if (input[*pos] == '>' && input[*pos + 1] == '>')
	{
		*pos += 2;
		return (ft_create_and_add_token(TOKEN_APPEND, ft_strdup(">>"), token_list));
	}
	else if (input[*pos] == '>')
	{
		(*pos)++;
		return (ft_create_and_add_token(TOKEN_REDIR_OUT, ft_strdup(">"), token_list));
	}
	else if (input[*pos] == '<' && input[*pos + 1] == '<')
	{
		*pos += 2;
		return (ft_create_and_add_token(TOKEN_HEREDOC, ft_strdup("<<"), token_list));
	}
	else if (input[*pos] == '<')
	{
		(*pos)++;
		return (ft_create_and_add_token(TOKEN_REDIR_IN, ft_strdup("<"), token_list));
	}
	return (-1);
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
	t_token	token;
	char	*word;

	// Handle quotes
	if (input[*pos] == '\'')
		return (ft_handle_single_quotes(input, pos, &token, shell) == 0 ? 
			ft_create_and_add_token(token.type, token.value, token_list) : -1);
	else if (input[*pos] == '"')
		return (ft_handle_double_quotes(input, pos, &token, shell) == 0 ? 
			ft_create_and_add_token(token.type, token.value, token_list) : -1);
	// Handle operators
	else if (input[*pos] == '|')
		return (ft_handle_pipe(input, pos, token_list));
	else if (input[*pos] == '>' || input[*pos] == '<')
		return (ft_handle_redirection(input, pos, token_list));
	else if (input[*pos] == '&' && input[*pos + 1] == '&')
	{
		*pos += 2;
		return (ft_create_and_add_token(TOKEN_AND, ft_strdup("&&"), token_list));
	}
	// Handle words (with expansion)
	else
	{
		word = ft_read_word_with_expansion(input, pos, shell);
		if (!word)
			return (-1);
		return (ft_create_and_add_token(TOKEN_WORD, word, token_list));
	}
}
