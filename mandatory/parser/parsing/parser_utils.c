#include "parser.h"

t_token	*peek_token(t_token *current)
{
	// Peek at next token without consuming
	return (current);
}

t_token	*consume_token(t_token **current)
{
	// Consume and return current token
	return (NULL);
}

void	free_ast(t_ast_node *root)
{
	// Free AST memory
}
