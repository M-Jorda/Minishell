/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:18 by jjorda            #+#    #+#             */
/*   Updated: 2024/11/11 15:58:20 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Skips whitespace characters in the given string and updates the index.
 *
 * This function advances the index `i` to skip over any whitespace characters
 * in the string `str`. If the end of the string is reached after skipping
 * whitespace, the function returns -1. Otherwise, it returns 0.
 *
 * @param str The input string to be processed.
 * @param i A pointer to the index that will be updated to skip whitespace.
 * @return int Returns -1 if the end of the string is reached, otherwise 0.
 */
static inline int	ft_space(const char *str, int *i)
{
	while (ft_isspace(str[*i + 1]) && ft_isspace(str[*i]))
		(*i)++;
	if (!str[*i])
		return (-1);
	return (0);
}

/**
 * @brief Iterates through a string until a specified character is found or the
 * end of the string is reached.
 *
 * This function takes a string `s`, a character `c`, and a pointer to an
 * integer `i`. It starts iterating
 * from the position pointed to by `i` and continues until it finds the
 * character `c` or reaches the end of the string.
 * If the character `c` is found, the position of `i` is updated to the
 * index of `c`. If `c` is not found,
 * the position of `i` is reset to its original value.
 *
 * @param s The input string to be searched.
 * @param c The character to search for in the string.
 * @param i A pointer to an integer representing the current position in the
 * string. This value will be updated
 *          to the position of the character `c` if found, or reset to its
 * original value if `c` is not found.
 */
static void	ft_ite(const char *s, const char c, int *i, int *count)
{
	int	j;

	j = *i;
	while (s[++(*i)])
	{
		if (s[*i] == c)
		{
			(*count)++;
			break ;
		}
	}
	if (!(s[*i] == c))
		*i = j;
}

static void	ft_firstword(int *booly, int *count)
{
	if (*booly == 0)
	{
		*booly = 1;
		(*count)++;
	}
}

/**
 * Counts the number of words in a string separated by the delimiter character c.
 * 
 * @param s The string to count words in.
 * @return The number of words in the string.
 */
int	ft_count_word(const char *str)
{
	int	count;
	int	booly;
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	booly = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && str[i] != '\'' && str[i] != '"')
			ft_firstword(&booly, &count);
		else
			booly = 0;
		if (ft_space(str, &i) == -1)
			break ;
		if (str[i] == '\'')
			ft_ite(str, '\'', &i, &count);
		else if (str[i] == '"')
			ft_ite(str, '"', &i, &count);
		i++;
	}
	return (count);
}

/* int main() {
	char *test1 = "Hello world";
	char *test2 = "   a a a ";
	char *test3 = "Trailing spaces   ";
	char *test4 = "Multiple   spaces   between   words";
	char *test5 = "SingleWord";
	char *test6 = "";
	char *test7 = "Words 'with quotes' inside";
	char *test8 = "Words \"with double quotes\" inside";
	char *test9 = "Mixed 'single' and \"double\" quotes";

	printf("Test 1: %d\n", ft_count_word(test1)); // Expected: 2
	printf("Test 2: %d\n", ft_count_word(test2)); // Expected: 3
	printf("Test 3: %d\n", ft_count_word(test3)); // Expected: 2
	printf("Test 4: %d\n", ft_count_word(test4)); // Expected: 4
	printf("Test 5: %d\n", ft_count_word(test5)); // Expected: 1
	printf("Test 6: %d\n", ft_count_word(test6)); // Expected: 0
	printf("Test 7: %d\n", ft_count_word(test7)); // Expected: 3
	printf("Test 8: %d\n", ft_count_word(test8)); // Expected: 3
	printf("Test 9: %d\n", ft_count_word(test9)); // Expected: 5

	return 0;
} */