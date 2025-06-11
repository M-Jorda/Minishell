/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/06/11 13:03:25 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

/* ************************************************************************** */
/*                              PARSING.C                                    */
/* ************************************************************************** */

/**
 * @brief Main parsing function - entry point
 * 
 * @param shell Shell structure containing tokenized input
 * @return int 0 on success, -1 on error
 */
int				ft_parsing(t_shell *shell);

/* ************************************************************************** */
/*                          PARSE_EXPRESSION.C                               */
/* ************************************************************************** */

/**
 * @brief Main expression parser with operator precedence
 * 
 * @param shell Shell structure
 * @param token_h Token list head  
 * @param start Start of expression
 * @param end End of expression (exclusive)
 * @return t_ast_node* AST representing the expression
 */
t_ast_node		*ft_parse_expression(t_shell *shell, t_list *token_h, 
					t_list *start, t_list *end);

/* ************************************************************************** */
/*                          PARSE_COMMAND.C                                  */
/* ************************************************************************** */

/**
 * @brief Parses a command sequence into AST node
 * 
 * @param start Start of command tokens
 * @param end End of command tokens
 * @return t_ast_node* Command AST node
 */
t_ast_node		*ft_parse_command(t_list *start, t_list *end);

/* ************************************************************************** */
/*                        PARSE_REDIRECTIONS.C                               */
/* ************************************************************************** */

/**
 * @brief Checks if token type is a redirection operator
 * 
 * @param type Token type to check
 * @return bool true if redirection, false otherwise
 */
bool			ft_is_redirect_token(t_token_type type);

/**
 * @brief Parses redirections from token sequence
 * 
 * @param shell Shell structure
 * @param token_h Token list head
 * @param cmd Command to add redirections to
 * @return int 0 on success, -1 on error
 */
int				ft_parse_redirections(t_shell *shell, t_list *token_h, 
					t_command *cmd);

/* ************************************************************************** */
/*                             AST_UTILS.C                                   */
/* ************************************************************************** */

/**
 * @brief Creates command AST node
 * 
 * @param args Command arguments array
 * @param redirs Redirections list
 * @return t_ast_node* New command node
 */
t_ast_node		*ft_create_command_node(char **args, t_list *redirs);

/**
 * @brief Creates operator AST node
 * 
 * @param type Node type (PIPE, AND, OR)
 * @param left Left child node
 * @param right Right child node
 * @return t_ast_node* New operator node
 */
t_ast_node		*ft_create_operator_node(node_type type, t_ast_node *left, 
					t_ast_node *right);

/**
 * @brief Creates group AST node
 * 
 * @param content Content of the group
 * @return t_ast_node* New group node
 */
t_ast_node		*ft_create_group_node(t_ast_node *content);

/**
 * @brief Frees command structure
 * 
 * @param cmd Command to free
 */
void			ft_free_command(t_command *cmd);

/**
 * @brief Recursively frees AST
 * 
 * @param ast AST node to free
 */
void			ft_free_ast(t_ast_node *ast);

/* ************************************************************************** */
/*                             PRINT_AST.C                                   */
/* ************************************************************************** */

/**
 * @brief Recursively prints AST structure
 * 
 * @param ast AST node to print
 * @param level Current indentation level
 */
void			ft_print_ast_tree(t_ast_node *ast, int level);

#endif