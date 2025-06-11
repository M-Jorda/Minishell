/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:35:51 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/08 18:21:42 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

char	**alloc_env(char **env, int skip)
{
	int		i;
	int		count;
	char	**new;

	i = 0;
	count = 0;
	while (env[i])
		i++;
	new = malloc(sizeof(char *) * i);
	if (!new)
		return (NULL);
	i = 0;
	count = 0;
	while (env[i])
	{
		if (i != skip)
			new[count++] = env[i];
		else
			free(env[i]);
		i++;
	}
	new[count] = NULL;
	return (new);
}

int	builtin_unset(char **args, char ***env)
{
	int		idx;
	char	**new;

	if (!args[1])
		return (0);
	idx = get_env_index(*env, args[1]);
	if (idx < 0)
		return (0);
	new = alloc_env(*env, idx);
	if (!new)
		return (1);
	free(*env);
	*env = new;
	return (0);
}