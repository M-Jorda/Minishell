/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:32:52 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/06 13:20:55 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	how_many(char const *s, char c)
{
	int	i;
	int	counter;
	int	b_check;

	counter = 0;
	i = 0;
	b_check = 0;
	while (s[i])
	{
		if (s[i] != c && b_check == 0)
		{
			b_check = 1;
			counter++;
		}
		else if (s[i] == c)
			b_check = 0;
		i++;
	}
	return (counter);
}

static char	**ft_arrmaker(char const *s, char c)
{
	char	**str;
	int		size_arr;

	if (!s)
		return (NULL);
	size_arr = how_many(s, c);
	str = (char **) malloc((size_arr + 1) * sizeof(char *));
	if (!str)
		return ((char **) ft_mallocfailed("ft_split"));
	str[size_arr] = NULL;
	return (str);
}

static int	ft_splitereate(char const *s, int *i, int len, char c)
{
	if (len == 0)
	{
		while (s[*i] && s[*i] != c)
		{
			len++;
			*i += 1;
		}
		return (len);
	}
	while (s[*i] && s[*i] == c)
		*i += 1;
	return (*i);
}

/*
* Allocates (with malloc(3)) and returns an array of strings obtained by
* splitting ’s’ using the character ’c’ as a delimiter. The array must end
* with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		i;
	int		size;

	i = 0;
	size = 0;
	str = ft_arrmaker(s, c);
	if (!str || !s)
		return (NULL);
	while (s[i])
	{
		ft_splitereate(s, &i, 1, c);
		if (s[i] == '\0')
			break ;
		start = i;
		str[size] = ft_substr(s, start, ft_splitereate(s, &i, 0, c));
		if (!str[size])
			return (ft_leak(str, size), NULL);
		size++;
	}
	return (str);
}

/* int	main(int argc, char **argv)
{
	char **str = ft_split(argv[1], ' ');
	for (int i = 0; str[i]; i++)
		ft_printerr("%s\n", str[i]);
	ft_free(str);
	return (0);
} */

/* void    ft_free_split(char **split);

void    print_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		printf("split[%d]: %s\n", i, split[i]);
		i++;
	}
}

void    test_ft_split(char const *s, char c)
{
	char **result = ft_split(s, c);
	if (result == NULL)
	{
		printf("ft_split returned NULL\n");
		return;
	}
	print_split(result);
	ft_free_split(result);
}

void    ft_free_split(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int main(void)
{
	printf("Test 1: Basic split\n");
	test_ft_split("hello world this is a test", ' ');

	printf("\nTest 2: Multiple delimiters\n");
	test_ft_split("hello  world  this  is  a  test", ' ');

	printf("\nTest 3: Leading and trailing delimiters\n");
	test_ft_split("  hello world this is a test  ", ' ');

	printf("\nTest 4: Only delimiters\n");
	test_ft_split("     ", ' ');

	printf("\nTest 5: No delimiters\n");
	test_ft_split("helloworld", ' ');

	printf("\nTest 6: Empty string\n");
	test_ft_split("", ' ');

	printf("\nTest 7: Delimiter not in string\n");
	test_ft_split("hello,world,this,is,a,test", ' ');

	return 0;
} */