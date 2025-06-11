/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:25:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/29 18:39:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

/**
 * @brief Counts wildcard tokens in the token list
 * 
 * @param shell Shell structure
 * @return int Number of wildcard tokens found
 */
static int	ft_count_wildcard_tokens(t_shell *shell)
{
	t_list	*curr;
	int		wildcard_count;
	int		word_with_wildcard;

	ft_printf("=== ANALYSE DES WILDCARDS ===\n");
	curr = shell->token;
	wildcard_count = 0;
	word_with_wildcard = 0;
	while (curr)
	{
		if (curr->content.token->type == TOKEN_WILDCARD)
			wildcard_count++;
		else if (ft_needs_wildcard_expansion(curr->content.token))
			word_with_wildcard++;
		curr = curr->next;
	}
	ft_printf("Tokens wildcard explicites: %d\n", wildcard_count);
	ft_printf("Mots contenant des wildcards: %d\n", word_with_wildcard);
	ft_printf("Total a expanser: %d\n\n", wildcard_count + word_with_wildcard);
	return (wildcard_count + word_with_wildcard);
}

/**
 * @brief Shows current directory files for reference
 */
static void	ft_show_current_directory(void)
{
	DIR				*dir;
	struct dirent	*entry;
	int				file_count;

	ft_printf("=== FICHIERS DU REPERTOIRE COURANT ===\n");
	dir = opendir(".");
	if (!dir)
	{
		ft_printf("Erreur: Impossible d'ouvrir le repertoire\n\n");
		return ;
	}
	file_count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			ft_printf("  %s\n", entry->d_name);
			file_count++;
		}
	}
	closedir(dir);
	ft_printf("Total fichiers visibles: %d\n\n", file_count);
}

/**
 * @brief Tests pattern matching with examples
 * 
 * @param pattern Pattern to test
 */
static void	ft_test_pattern_matching(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	int				match_count;

	ft_printf("=== TEST DU PATTERN '%s' ===\n", pattern);
	dir = opendir(".");
	if (!dir)
	{
		ft_printf("Erreur: Impossible d'ouvrir le repertoire\n\n");
		return ;
	}
	match_count = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_should_show_hidden(entry->d_name, pattern))
		{
			if (ft_match_pattern(pattern, entry->d_name))
			{
				ft_printf("  ✓ %s\n", entry->d_name);
				match_count++;
			}
		}
	}
	closedir(dir);
	if (match_count == 0)
		ft_printf("  (aucune correspondance)\n");
	ft_printf("Correspondances trouvees: %d\n\n", match_count);
}

/**
 * @brief Prints token list before and after expansion
 * 
 * @param shell Shell structure
 * @param before True for before expansion, false for after
 */
static void	ft_print_token_comparison(t_shell *shell, bool before)
{
	t_list	*curr;
	int		token_count;

	if (before)
		ft_printf("=== TOKENS AVANT EXPANSION ===\n");
	else
		ft_printf("=== TOKENS APRES EXPANSION ===\n");
	curr = shell->token;
	token_count = 0;
	while (curr)
	{
		ft_printf("  [%d] %s: \"%s\"\n", 
			token_count,
			ft_get_token_type_name(curr->content.token->type),
			curr->content.token->value);
		curr = curr->next;
		token_count++;
	}
	ft_printf("Total tokens: %d\n\n", token_count);
}

/**
 * @brief Gets token type name for display
 * 
 * @param type Token type
 * @return char* String representation of token type
 */
static char	*ft_get_token_type_name(t_token_type type)
{
	if (type == TOKEN_WORD)
		return ("WORD");
	else if (type == TOKEN_WILDCARD)
		return ("WILDCARD");
	else if (type == TOKEN_PIPE)
		return ("PIPE");
	else if (type == TOKEN_AND)
		return ("AND");
	else if (type == TOKEN_OR)
		return ("OR");
	else
		return ("OTHER");
}

/**
 * @brief Tests wildcard expansion functionality
 * 
 * @param shell Shell structure
 * @return int 0 on success, 1 on error
 */
static int	ft_test_wildcard_expansion(t_shell *shell)
{
	int		original_count;
	int		expanded_count;
	t_list	*curr;

	ft_printf("=== TEST DE L'EXPANSION ===\n");
	original_count = ft_count_tokens(shell->token);
	ft_exp_wildcard(shell, &shell->token);
	expanded_count = ft_count_tokens(shell->token);
	ft_printf("Tokens avant expansion: %d\n", original_count);
	ft_printf("Tokens apres expansion: %d\n", expanded_count);
	if (expanded_count > original_count)
		ft_printf("✓ Expansion detectee (+%d tokens)\n", 
			expanded_count - original_count);
	else if (expanded_count == original_count)
		ft_printf("- Aucune expansion (pas de correspondance)\n");
	else
		ft_printf("✗ Erreur: Reduction du nombre de tokens\n");
	ft_printf("\n");
	return (0);
}

/**
 * @brief Counts tokens in the list
 * 
 * @param token_h Token list head
 * @return int Number of tokens
 */
static int	ft_count_tokens(t_list *token_h)
{
	t_list	*curr;
	int		count;

	curr = token_h;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

/**
 * @brief Demonstrates wildcard expansion with examples
 */
static void	ft_demonstrate_patterns(void)
{
	ft_printf("=== DEMONSTRATION DES PATTERNS ===\n");
	ft_printf("Patterns supportes:\n");
	ft_printf("  * : Correspond a n'importe quelle sequence\n");
	ft_printf("  *.c : Tous les fichiers .c\n");
	ft_printf("  test* : Fichiers commencant par 'test'\n");
	ft_printf("  *test* : Fichiers contenant 'test'\n\n");
	ft_test_pattern_matching("*");
	ft_test_pattern_matching("*.c");
	ft_test_pattern_matching("*.h");
	ft_test_pattern_matching("main*");
}

/**
 * @brief Main function for testing wildcard expansion
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @param env Environment variables
 * @return int Exit code
 */
int	main(int argc, char **argv, char **env)
{
	t_shell	shell;
	int		wildcard_count;

	if (argc != 2)
	{
		ft_printf("Usage: %s \"commande avec wildcards\"\n", argv[0]);
		ft_printf("Exemples:\n");
		ft_printf("  %s \"ls *\"\n", argv[0]);
		ft_printf("  %s \"cat *.c\"\n", argv[0]);
		ft_printf("  %s \"echo test* | grep main\"\n", argv[0]);
		return (1);
	}
	if (ft_setup(&shell, env) == -1)
	{
		ft_printerr("Erreur: Initialisation echouee\n");
		return (1);
	}
	shell.current_line = argv[1];
	ft_printf("=== TEST DE L'EXPANSION DES WILDCARDS ===\n");
	ft_printf("Commande: \"%s\"\n\n", shell.current_line);
	ft_show_current_directory();
	ft_demonstrate_patterns();
	shell.token = ft_lexing(&shell);
	if (!shell.token)
	{
		ft_printerr("Erreur: Echec du lexing\n");
		ft_cleanup(&shell, 1);
		return (1);
	}
	wildcard_count = ft_count_wildcard_tokens(&shell);
	if (wildcard_count > 0)
	{
		ft_print_token_comparison(&shell, true);
		ft_test_wildcard_expansion(&shell);
		ft_print_token_comparison(&shell, false);
	}
	else
		ft_printf("Aucun wildcard detecte dans la commande\n\n");
	ft_printf("=== TEST TERMINE AVEC SUCCES ===\n");
	ft_cleanup(&shell, 0);
	return (0);
}
