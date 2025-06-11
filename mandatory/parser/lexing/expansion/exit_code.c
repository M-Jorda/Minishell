/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:07:28 by jjorda            #+#    #+#             */
/*   Updated: 2025/05/11 12:21:28 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/minishell.h"

static char	*ft_exitloop(char *str, char *code_str, int new_len)
{
	char	*result;
	int		i[2];

	result = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!result)
	{
		free(code_str);
		return (NULL);
	}
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		if (str[i[0]] == '$' && str[i[0] + 1] == '?')
		{
			ft_strlcpy(result + i[1], code_str, ft_strlen(code_str) + 1);
			i[1] += ft_strlen(code_str);
			i[0] += 2;
		}
		else
			result[i[1]++] = str[i[0]++];
	}
	result[i[1]] = '\0';
	free(code_str);
	return (result);
}

/**
 * @brief Handles $? expansion
 *
 * @param str The string to process
 * @param exit_code The last exit code
 * @return char* New string with exit code expanded, NULL on error
 */
char	*ft_expand_exit_code(char *str, int exit_code)
{
	char	*code_str;
	int		i;
	int		new_len;

	if (!str)
		return (NULL);
	code_str = ft_itoa(exit_code);
	if (!code_str)
		return (NULL);
	new_len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			new_len = new_len - 2 + ft_strlen(code_str);
			i += 2;
		}
		else
			i++;
	}
	return (ft_exitloop(str, code_str, new_len));
}

static void	ft_statusloop(char *str, char *new_str, char *status)
{
	int	status_len;
	int	str_len;
	int	i;
	int	j;

	status_len = ft_strlen(status);
	str_len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < str_len)
	{
		if (str[i] == DOLL && str[i + 1] == Q_MRK)
		{
			ft_strlcpy(new_str + j, status, status_len + 1);
			j += status_len;
			i += 2;
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
}

/**
 * @brief Expands the $? status variable to its value
 * 
 * @param shell The shell structure
 * @param tok_c Current token node
 * @param str The string containing the status variable
 * @return bool true on success, false on error
 */
bool	ft_expand_status(t_shell *shell, t_list *tok_c, char *str)
{
	char	*new_str;
	char	*status;

	if (!shell || !tok_c || !str)
		return (false);
	status = ft_itoa(shell->env->last_exit_code);
	if (!status)
		return (false);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str)
				+ ft_strlen(status) + 1));
	if (!new_str)
	{
		free(status);
		return (false);
	}
	ft_statusloop(str, new_str, status);
	free(status);
	free(str);
	tok_c->content.token->value = new_str;
	return (true);
}
