/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:35:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 22:23:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "struct.h"
# include "../lib/libft/libft.h"

/* ----------------------------- MAIN EXPANSION ----------------------------- */

/**
 * @brief Main expansion function
 * 
 * @param shell Shell structure
 * @param token_list Token list to expand
 * @return int 0 on success, -1 on error
 */
int		ft_expansion(t_shell *shell, t_list *token_list);

/* --------------------------- VARIABLE EXPANSION --------------------------- */

/**
 * @brief Expand a variable name to its value
 * 
 * @param shell Shell structure
 * @param var_name Variable name
 * @return char* Variable value, empty string if not found
 */
char	*ft_expand_variable(t_shell *shell, char *var_name);

/**
 * @brief Process variable expansion in string
 * 
 * @param shell Shell structure
 * @param input Input string
 * @return char* String with variables expanded
 */
char	*ft_process_var_expansion(t_shell *shell, char *input);

/* --------------------------- EXIT CODE EXPANSION -------------------------- */

/**
 * @brief Expand $? to exit code
 * 
 * @param shell Shell structure
 * @return char* Exit code as string
 */
char	*ft_expand_exit_code(t_shell *shell);

/**
 * @brief Process $? expansion in string
 * 
 * @param shell Shell structure
 * @param input Input string
 * @return char* String with $? expanded
 */
char	*ft_process_exit_code_expansion(t_shell *shell, char *input);

/* --------------------------- DOUBLE QUOTE EXPANSION ----------------------- */

/**
 * @brief Expand variables inside double quotes
 * 
 * @param shell Shell structure
 * @param input Content inside double quotes
 * @return char* Expanded string
 */
char	*ft_expand_in_double_quotes(t_shell *shell, char *input);

/**
 * @brief Handle double quotes with expansion
 * 
 * @param input Input string
 * @param pos Position pointer
 * @param token Token to fill
 * @param shell Shell structure
 * @return int 0 on success, -1 on error
 */
int		ft_handle_double_quotes_with_expansion(char *input, int *pos, 
			t_token *token, t_shell *shell);

/* ----------------------------- QUOTE REMOVAL ------------------------------ */

/**
 * @brief Remove outer quotes from string
 * 
 * @param input Input string
 * @return char* String without outer quotes
 */
char	*ft_remove_quotes(char *input);

/**
 * @brief Process quote removal for token list
 * 
 * @param token_list Token list
 * @return int 0 on success, -1 on error
 */
int		ft_process_quote_removal(t_list *token_list);

/* ---------------------------- EXPANSION UTILS ----------------------------- */

/**
 * @brief Check if expansion should occur
 * 
 * @param token Token to check
 * @param in_single_quotes Whether in single quotes
 * @return bool true if should expand
 */
bool	ft_should_expand(t_token *token, bool in_single_quotes);

/**
 * @brief Check if string contains variables
 * 
 * @param str String to check
 * @return bool true if contains variables
 */
bool	ft_contains_variables(char *str);

/**
 * @brief Safe string join that frees first parameter
 * 
 * @param s1 First string (freed)
 * @param s2 Second string
 * @return char* Joined string
 */
char	*ft_safe_strjoin(char *s1, char *s2);

/**
 * @brief Validate variable name
 * 
 * @param var_name Variable name
 * @return bool true if valid
 */
bool	ft_is_valid_var_name(char *var_name);

/* ----------------------------- TOKEN EXPANSION ---------------------------- */

/**
 * @brief Expand token and handle splitting
 * 
 * @param shell Shell structure
 * @param token_node Token node to expand
 * @return t_list* List of resulting tokens
 */
t_list	*ft_expand_token_node(t_shell *shell, t_list *token_node);

/**
 * @brief Expand variables in a token value
 * 
 * @param shell Shell structure
 * @param value Original token value
 * @return char* Expanded value, NULL on error
 */
char	*ft_expand_token_value(t_shell *shell, char *value);

#endif
