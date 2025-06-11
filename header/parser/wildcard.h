/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:30:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:21:50 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# include "../minishell.h"
# include <dirent.h>
# include <sys/stat.h>

/* ----------------------------- WILDCARD MAIN ----------------------------- */

int		ft_expand_wildcard(t_shell *shell, t_list **tok_h);
void	ft_exp_wildcard(t_shell *shell, t_list **tok_h);
bool	ft_needs_wildcard_expansion(t_token *token);
bool	ft_is_wildcard_char(char c);
bool	ft_replace_wildcard_token(t_list **tok_h, t_list *tok_curr);

/* ---------------------------- WILDCARD MATCH ----------------------------- */

bool	ft_match_pattern(const char *pattern, const char *string);
void	ft_reset_pattern_match(const char **p, const char **s,
			const char *star_p, const char **star_s);
bool	ft_check_remaining_pattern(const char *p);
bool	ft_should_show_hidden(const char *filename, const char *pattern);
void	ft_sort_matches(char **arr, int size);

/* ---------------------------- WILDCARD FILES ----------------------------- */

char	**ft_get_matching_files(const char *pattern);
int		ft_collect_matches(DIR *dir, const char *pattern, char **matches,
			int *capacity);
bool	ft_add_match_to_array(char **matches, int *count, int *capacity,
			const char *filename);
bool	ft_connect_new_tokens(t_list **tok_h, t_list *tok_curr, t_list *new_tokens);
t_list	*ft_create_match_tokens(char **matches);

/* --------------------------- WILDCARD TOKENS ----------------------------- */

bool	ft_build_token_list(char **matches, int count, t_list **token_list);
t_token	*ft_create_filename_token(const char *filename);
bool	ft_validate_token(t_token *token);
bool	ft_is_valid_filename(const char *filename);
void	ft_cleanup_failed_token(t_token *token, char **matches);

#endif
