/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:20:15 by jjorda            #+#    #+#             */
/*   Updated: 2024/12/08 12:15:07 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_loop(const char *s, const char c, int *i)
{
	int	j;

	j = *i;
	while (s[++(*i)])
		if (s[*i] == c)
			return ;
	*i = j;
}

int	ft_find_quotes(char const *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (-1);
	if (s[i] == '\'')
		ft_loop(s, '\'', &i);
	else if (s[i] == '"')
		ft_loop(s, '"', &i);
	return (i);
}
/* 
#include <assert.h>

int	ft_find_quotes(char const *s);

void test_ft_find_quotes()
{
	// Test with single quotes
	assert(ft_find_quotes("'hello world'") == 12);
	assert(ft_find_quotes("'hello' world") == 6);
	assert(ft_find_quotes("'hello") == 0);
	assert(ft_find_quotes("'") == 0);

	// Test with double quotes
	assert(ft_find_quotes("\"hello world\"") == 12);
	assert(ft_find_quotes("\"hello\" world") == 6);
	assert(ft_find_quotes("\"hello") == 0);
	assert(ft_find_quotes("\"") == 0);

	// Test with no quotes
	assert(ft_find_quotes("hello world") == 0);
	assert(ft_find_quotes("") == -1);
	assert(ft_find_quotes(NULL) == -1);

	printf("All tests passed!\n");
}

int main()
{
	test_ft_find_quotes();
	return 0;
} */