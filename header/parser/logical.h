/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/01 14:17:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICAL_H
# define LOGICAL_H

# include "../minishell.h"

/* ----------------------------- LOGICAL PARSING ----------------------------- */

int			ft_parse_logical_operators(t_shell *shell);
bool		ft_validate_logical_syntax(t_list *token_h);
bool		ft_is_logical_operator_token(t_token *token);
int			ft_get_operator_precedence(t_token_type type);

/* --------------------------- LOGICAL PARSING UTILS ------------------------- */

t_list		*ft_find_operator_by_precedence(t_list *start, t_list *end, int precedence);
node_type	ft_token_to_node_type(t_token_type token_type);
t_ast_node	*ft_parse_logical_expression(t_shell *shell, t_list *start, t_list *end);

/* --------------------------- LOGICAL PRINT UTILS --------------------------- */

void		ft_print_logical_ast(t_ast_node *node, int level);
char		*ft_get_logical_op_str(node_type type);

#endif