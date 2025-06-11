/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:43:30 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/14 13:56:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

/* ---------------------------------- ERR ----------------------------------- */

/**
 * @brief Sets a status code and returns NULL
 * 
 * @param p_status Pointer to status variable
 * @param status Status code to set
 * @return void* Always NULL
 */
void			*ft_tok_err(int *p_status, int status);

/**
 * @brief Frees an entire token list
 * 
 * @param tok_h Head of the token list
 * @return void* Always NULL
 */
void			*ft_lstfree_t(t_list *tok_h);

/**
 * @brief Frees a token node and its content
 * 
 * @param node The token node to free
 * @return void* Always NULL
 */
void			*ft_clean_node_tok(t_list *node);

int				ft_new_token_err(t_token *token, int ret);
// int	ft_getend(char *s, int *i, bool *quote, bool word);
// t_token_type	ft_getiteration(t_token_type type, int *i, int add);
// char	*ft_expand_exit_code(char *str, int exit_code);
/* --------------------------------- UTILS ---------------------------------- */

/**
 * @brief Identifies the token type at the current position
 * 
 * @param s The input string
 * @param i Pointer to the current position
 * @param quote Flag to track quote status
 * @return t_token_type The identified token type
 */
t_token_type	ft_get_type(char *s, int *i, bool *quote);

/**
 * @brief Performs basic syntax validation on the token list
 * 
 * @param shell The shell structure
 * @return int 0 on success, negative value on error
 */
int				ft_lexer_checker(t_shell *shell);

/* --------------------------------- LEXING --------------------------------- */

/**
 * @brief Main lexing function to tokenize a string
 * 
 * @param shell The shell structure
 * @return t_list* Head of the token list, NULL on error
 */
t_list			*ft_lexing(t_shell *shell);
char	*ft_gettype_name(t_token_type type);

/* -------------------------------- EXPANSION ------------------------------- */

/**
 * @brief Main expansion function to process all token expansions
 * 
 * @param shell The shell structure
 * @param tok_h The token list head
 * @param status Pointer to status variable
 * @return int 0 on success, -1 on error
 */
int				ft_expansion(t_shell *shell, t_list **tok_h, int *status);

/**
 * @brief Expands the $? status variable to its value
 * 
 * @param shell The shell structure
 * @param tok_c Current token node
 * @param str The string containing the status variable
 * @return bool true on success, false on error
 */
bool			ft_expand_status(t_shell *shell, t_list *tok_c, char *str);

/**
 * @brief Expands a variable in a string to its value
 * 
 * @param shell The shell structure
 * @param tok_c Current token node
 * @param str The string containing the variable
 * @param var_pos Position of the variable in the string
 * @return bool true on success, false on error
 */
bool			ft_expand_var(t_shell *shell, t_list *tok_c, char *str, int var_pos);

/**
 * @brief Creates a new token with expanded variable value
 * 
 * @param value The variable value
 * @return t_token* New token structure, NULL on error
 */
t_token			*ft_create_var_token(char *value);

/**
 * @brief Checks if a key is valid for environment variables
 * 
 * @param key The key to check
 * @return bool true if valid, false otherwise
 */
bool			ft_is_valid_env_key(const char *key);

/**
 * @brief Replaces a variable name with its value in a string
 * 
 * @param original Original string
 * @param var_pos Position of the variable in the string
 * @param var_len Length of the variable name
 * @param replacement Value to replace the variable with
 * @return char* New string with the variable replaced, NULL on error
 */
char			*ft_replace_var(char *original, int var_pos, int var_len, char *replacement);

/**
 * @brief Extracts a variable name from a string
 *
 * @param str The string containing the variable
 * @param pos Position of the variable in the string
 * @return char* The variable name, NULL on error
 */
char			*ft_extract_var_name(char *str, int pos);

/**
 * @brief Searches for a variable in the environment
 *
 * @param env_vars Array of environment variables
 * @param key The variable key to search for
 * @return char* The variable value, NULL if not found
 */
char			*ft_find_env_var(char **env_vars, const char *key);

/**
 * @brief Handles $? expansion
 *
 * @param str The string to process
 * @param exit_code The last exit code
 * @return char* New string with exit code expanded, NULL on error
 */
char			*ft_expand_exit_code(char *str, int exit_code);

bool	ft_expand_dquote(t_shell *shell, t_list *tok_c, int *status);
t_list	*ft_expand_token(t_shell *shell, t_list **tok_h, 
	t_list **tok_c);

#endif