/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/06/11 13:10:28 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSHELL_H
# define SUBSHELL_H

# include "../minishell.h"

/* ---------------------------- PARENTHESES PARSING ---------------------------- */

t_list		*ft_find_matching_paren(t_list *start);
// bool		ft_validate_parentheses(t_list *token_h);
// t_ast_node	*ft_parse_group(t_shell *shell, t_list *start, t_list *end);
bool		ft_is_wrapped_in_parens(t_list *start, t_list *end);
t_ast_node	*ft_parse_expression(t_shell *shell, t_list *token_h,
                                             t_list *start, t_list *end);

/* --------------------------- PARENTHESES VALIDATION --------------------------- */

int			ft_check_paren_balance(t_list *token_h);
bool		ft_validate_paren_order(t_list *token_h);
bool		ft_validate_paren_content(t_list *start, t_list *end);
bool		ft_validate_parentheses_complete(t_list *token_h);
bool		ft_validate_all_paren_pairs(t_list *token_h);

/* ---------------------------- PARENTHESES UTILS ---------------------------- */

int			ft_get_paren_depth(t_list *token_h, t_list *target);
t_list		*ft_find_token_at_level(t_list *start, t_token_type target_type);
t_list		*ft_skip_paren_group(t_list *start);
bool		ft_is_token_in_parens(t_list *token_h, t_list *target);
bool		ft_get_outermost_parens(t_list *token_h, t_list *target,
				t_list **open_paren, t_list **close_paren);

#endif
