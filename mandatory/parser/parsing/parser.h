#ifndef PARSER_H
# define PARSER_H

# include "../lexing/lexer.h"

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_REDIR,
	NODE_GROUP
}	t_node_type;

typedef struct s_ast_node
{
	t_node_type			type;
	char				**args;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	struct s_ast_node	*next;
}	t_ast_node;

// Main function
t_ast_node	*ft_parser(t_token_list *tokens);

#endif
