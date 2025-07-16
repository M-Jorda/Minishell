/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:10:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:15:59 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "struct.h"
# include "../lib/libft/libft.h"

/* --------------------------------- LEXER ---------------------------------- */

/**
 * @brief Main lexer function - entry point
 * 
 * @param input Input string to tokenize
 * @param shell Shell structure
 * @return t_list* Token list, NULL on error
 */
t_list	*ft_lexer(char *input, t_shell *shell);

/* ----------------------------- TOKENIZER --------------------------------- */

/**
 * @brief Tokenize next element from input
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token_list Token list to add to
 * @param shell Shell structure
 * @return int 0 on success, -1 on error
 */
int		ft_tokenize_next(char *input, int *pos, t_list **token_list, t_shell *shell);

/* --------------------------- TOKEN CLASSIFIER ----------------------------- */

/**
 * @brief Check if character is an operator
 * 
 * @param c Character to check
 * @return bool true if operator, false otherwise
 */
bool	ft_is_operator_char(char c);

/**
 * @brief Check if character is a redirection operator
 * 
 * @param c Character to check
 * @return bool true if redirection, false otherwise
 */
bool	ft_is_redirection_char(char c);

/**
 * @brief Check if character is a logical operator
 * 
 * @param c Character to check
 * @return bool true if logical operator, false otherwise
 */
bool	ft_is_logical_operator_char(char c);

/**
 * @brief Get token type from character(s)
 * 
 * @param input Input string
 * @param pos Current position
 * @return t_token_type Token type identified
 */
t_token_type	ft_get_token_type(char *input, int pos);

/* --------------------------- QUOTES HANDLER ------------------------------- */

/**
 * @brief Find closing quote in input
 * 
 * @param input Input string
 * @param start_pos Starting position
 * @param quote_char Quote character to match
 * @return int Position of closing quote, -1 if not found
 */
int		ft_find_closing_quote(char *input, int start_pos, char quote_char);

/**
 * @brief Handle single quotes
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @param shell Shell structure
 * @return int 0 on success, -1 on error
 */
int		ft_handle_single_quotes(char *input, int *pos, t_token *token, t_shell *shell);

/**
 * @brief Handle double quotes
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @param shell Shell structure
 * @return int 0 on success, -1 on error
 */
int		ft_handle_double_quotes(char *input, int *pos, t_token *token, t_shell *shell);

/**
 * @brief Check if quotes are balanced
 * 
 * @param input Input string
 * @return bool true if balanced, false otherwise
 */
bool	ft_quotes_are_balanced(char *input);

/* ----------------------------- EXPANSION ---------------------------------- */

/**
 * @brief Main expansion function
 * 
 * @param shell Shell structure
 * @param token_list Token list to expand
 * @return int 0 on success, -1 on error
 */
int		ft_expansion(t_shell *shell, t_list *token_list);

/**
 * @brief Expand variables in double quotes
 * 
 * @param shell Shell structure
 * @param input Content inside double quotes
 * @return char* Expanded string
 */
char	*ft_expand_in_double_quotes(t_shell *shell, char *input);

/**
 * @brief Process variable expansion
 * 
 * @param shell Shell structure
 * @param input Input string
 * @return char* String with variables expanded
 */
char	*ft_process_var_expansion(t_shell *shell, char *input);

/**
 * @brief Process exit code expansion
 * 
 * @param shell Shell structure
 * @param input Input string
 * @return char* String with $? expanded
 */
char	*ft_process_exit_code_expansion(t_shell *shell, char *input);

/**
 * @brief Check if string contains variables
 * 
 * @param str String to check
 * @return bool true if contains variables
 */
bool	ft_contains_variables(char *str);

/* ----------------------------- LEXER UTILS -------------------------------- */

/**
 * @brief Free a token
 * 
 * @param token Token to free
 */
void	ft_free_token(t_token *token);

/**
 * @brief Free entire token list
 * 
 * @param token_list Token list to free
 */
void	ft_free_token_list(t_list *token_list);

/**
 * @brief Print token for debugging
 * 
 * @param token Token to print
 */
void	ft_print_token(t_token *token);

/**
 * @brief Print token list for debugging
 * 
 * @param token_list Token list to print
 */
void	ft_print_token_list(t_list *token_list);

/**
 * @brief Get string representation of token type
 * 
 * @param type Token type
 * @return char* String representation
 */
char	*ft_get_token_type_string(t_token_type type);

#endif
