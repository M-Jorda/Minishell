/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:44:27 by jjorda            #+#    #+#             */
/*   Updated: 2025/07/16 19:44:19 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include "../lib/libms/libms.h"
# include "struct.h"
# include "macro.h"
# include "deployment/setup.h"
# include "minishell_executor.h"
# include "signals.h"
# include "executor.h"
# include "deployment/cleanup.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

/* ----------------------------- CORE FUNCTIONS ----------------------------- */

/**
 * @brief Main execution function for AST
 * 
 * @param shell The shell structure
 * @return int Exit code
 */
int		ft_execute_ast(t_shell *shell);

/**
 * @brief Executes logical operators with short-circuit evaluation
 * 
 * @param node AST node
 * @param env Environment
 * @return int Exit code
 */
int		ft_execute_logical(t_ast_node *node, t_env *env);

/**
 * @brief Executes a subshell
 * 
 * @param content AST content to execute
 * @param parent_env Parent environment
 * @return int Exit code
 */
int		ft_execute_subshell(t_ast_node *content, t_env *parent_env);

/**
 * @brief Finds matching closing parenthesis
 * 
 * @param start Token with opening parenthesis
 * @return t_list* Matching closing parenthesis token
 */
t_list	*ft_find_matching_paren(t_list *start);

/**
 * @brief Validates parentheses syntax
 * 
 * @param token_h Token list head
 * @return bool true if valid, false otherwise
 */
// bool	ft_validate_parentheses(t_list *token_h);

/**
 * @brief Parses a group (parentheses)
 * 
 * @param shell Shell structure
 * @param start Opening parenthesis token
 * @param end Closing parenthesis token
 * @return t_ast_node* Group AST node
 */
// t_ast_node	*ft_parse_group(t_shell *shell, t_list *start, t_list *end);

/**
 * @brief Expands wildcards in token list
 * 
 * @param shell Shell structure
 * @param tok_h Token list head pointer
 */
void	ft_exp_wildcard(t_shell *shell, t_list **tok_h);

/* ----------------------------- AST UTILITIES ----------------------------- */

/**
 * @brief Creates a command node in the AST
 * 
 * @param args Array of command arguments
 * @param redirs List of redirections
 * @return t_ast_node* New command node, NULL on error
 */
t_ast_node	*ft_create_command_node(char **args, t_list *redirs);

/**
 * @brief Creates an operator node in the AST
 * 
 * @param type Type of operator (PIPE, AND, OR)
 * @param left Left child node
 * @param right Right child node
 * @return t_ast_node* New operator node, NULL on error
 */
t_ast_node	*ft_create_operator_node(node_type type, t_ast_node *left, t_ast_node *right);

/**
 * @brief Creates a group node in the AST
 * 
 * @param content Content of the group
 * @return t_ast_node* New group node, NULL on error
 */
t_ast_node	*ft_create_group_node(t_ast_node *content);

/**
 * @brief Parses redirections from tokens and adds them to a command
 * 
 * @param shell The shell structure
 * @param token_h Head of the token list
 * @param cmd Command structure to add redirections to
 * @return int 0 on success, -1 on error
 */
int			ft_parse_redirections(t_shell *shell, t_list *token_h, t_command *cmd);

#endif