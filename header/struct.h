/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:45:58 by jjorda            #+#    #+#             */
/*   Updated: 2025/04/21 12:15:01 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list	t_list;

/* --------------------------------- LEXING --------------------------------- */

typedef enum e_token_type {
	TOKEN_WORD,					// 0 Cmd, args, files ...
	TOKEN_OR,					// 1 ||
	TOKEN_APPEND,				// 2 >>
	TOKEN_HEREDOC,				// 3 <<
	TOKEN_AND,					// 4 &&
	TOKEN_STATUS,				// 5 $?
	TOKEN_ERROR,				// 6 In case or error
	TOKEN_PIPE,					// 7 |
	TOKEN_REDIR_OUT,			// 8 >
	TOKEN_REDIR_IN,				// 9 <
	TOKEN_VAR,					// 10 $
	TOKEN_QUOTE,				// 11 '
	TOKEN_DQUOTE,				// 12 "
	TOKEN_PAREN_OPEN,			// 13 (.
	TOKEN_PAREN_CLOSE,			// 14 )
	TOKEN_WILDCARD,				// 15 *
	TOKEN_ASSIGN,				// 16 =
	TOKEN_EOF,					// 17 End of Line
	TOKEN_BSLASH,				// 18 \.
	TOKEN_SPACE					// 19 ' '
}	t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
}	t_token;

/* -------------------------------- PARSING --------------------------------- */

typedef enum {
	NODE_COMMAND,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_REDIR,
	NODE_GROUP					// Pour les parenthèses
}	node_type;

typedef struct s_ast_node {
	node_type			type;
	void				*data;	// Données spécifiques au type de nœud
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

/* --------------------------------- REDIR ---------------------------------- */

typedef enum {
	REDIR_IN,					// <
	REDIR_OUT,					// >
	REDIR_HEREDOC,				// <<
	REDIR_APPEND				// >>
}	redir_type;

typedef struct s_redir {
	redir_type	type;
	char		*file;			// Nom du fichier ou délimiteur pour heredoc
	int			fd;				// File descriptor
}	t_redir;

/* -------------------------------- COMMAND --------------------------------- */

typedef struct s_command {
	char	**args;				// Tableau d'arguments (args[0] est la commande)
	t_list	*redirs;				// Liste des redirections
}	t_command;

/* ---------------------------------- ENV ----------------------------------- */

typedef struct s_env {
	char	**env_vars;			// Variables d'environnement actuelles
	char	**local_env;		// Variables locales utilisables uniquement par le process parent
	int		last_exit_code;		// Stocke la valeur de $?
}	t_env;

/* --------------------------------- SHELL ---------------------------------- */

typedef struct s_shell {
	t_env		*env;
	char		*current_line;
	int			signal_received;
	char		*prompt;
	t_list		*token;			// Résultat du lexer
	t_ast_node	*ast;			// Arbre syntaxique après parsing
}	t_shell;

/* ---------------------------------- LIST ---------------------------------- */

typedef enum e_content_type
{
	TYPE_REDIR,
	TYPE_TOKEN,
	TYPE_COMMAND,
	TYPE_GENERIC
}	t_content_type;

typedef union u_content
{
	t_redir		*redir;
	t_token		*token;
	t_command	*cmd;
	void		*generic;
}	t_content;

typedef struct s_list
{
	t_content_type	type;
	t_content		content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

#endif