/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:40:33 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/12 10:19:13 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../struct_lib.h"
# include "print/ft_printf/ft_printf.h"
# include "print/ft_printerr/ft_printerr.h"
# include "file/gnl/get_next_line.h"
# include "file/gnl/get_next_line_fd.h"

/* ------------------------------- SEARCH_FOR ------------------------------- */

int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_count_word(char const *s);
int		ft_countdigit(long long n);
int		ft_isesc(char c);
int		ft_contains_char(char *str, char c);
int		ft_poschar(char *str, char c);
int		ft_count_arr(char **arr);
bool	ft_ismeta(char *meta, char c);
int		ft_eov(char *str);

/* ------------------------------- CONVERTION ------------------------------- */

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

/* --------------------------------- MEMORY --------------------------------- */

void	*ft_mallocfailed(char *funcname);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_f(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_leak(char **str, size_t i);
char	**ft_split_arg(char const *s);
void	ft_free_vctr(void **ptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_free_arr(char **arr);
void	*ft_realloc(void *ptr, size_t size, size_t old_size);

/* ---------------------------- STR_MANIPULATION ---------------------------- */

void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcpy_esc(char *dest, const char *src);
char	*ft_getlast_vctr(char **vctr);

/* ------------------------------- STR_SEARCH ------------------------------- */

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_esc(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(char c);
int		ft_find_quotes(char const *s);

/* --------------------------------- PRINT ---------------------------------- */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ---------------------------------- LIST ---------------------------------- */

t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
bool	ft_lstadd_back(t_list **lst, t_content data, t_content_type type);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// void	*ft_lstfree(t_list *list);
// void	ft_lst_freemall(t_mall *head, void *mall);
t_list	*ft_lstn_2(t_list *lst);
t_list	*ft_lstn_3(t_list *lst);
// t_list	*ft_nextlst(t_list *head, int i);
t_list	*ft_lstfirst(t_list *actual);
bool	ft_lstrem_front(t_list **actual, void (*f)(void *));
void	*ft_lstleak(t_list **lst, void *(*f)(t_list *));
bool	ft_lstrem_n(t_list **head, int index, void *(*f)(t_list *));
bool	ft_lstreplace_n(t_list **del, t_list *rep, void *(*f) (t_list *), int n);

void	*ft_clean_node_tok(t_list *tok_curr);
t_list	*ft_lstnew_tok(t_token *token);
t_list	*ft_lstnew_redir(t_redir *redir);
t_list	*ft_lstnew_ast(t_ast_node *ast);
t_list	*ft_lstnew_cmd(t_command *cmd);
bool	ft_lstinsert(t_list **lst, void *data, int index);

/* ---------------------------------- FILE ---------------------------------- */

void	ft_closefd(int *p_fd, int size);
int		ft_openfile(char *name, int flag);

/* --------------------------------- ERROR ---------------------------------- */

// void	ft_err(t_all **all, char *mess, int ext);

/* ---------------------------------- MATH ---------------------------------- */

long	ft_ran(int min, int max);

#endif