/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:47:48 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/10 19:16:15 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"


static char	*search_cmd_in_paths(char **paths, char *cmd)
{
	char	*joined;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		joined = ft_strjoin(paths[i], "/");
		if (!joined)
			return (NULL);
		path = ft_strjoin(joined, cmd);
		free(joined);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (!paths)
		return (NULL);
	path = search_cmd_in_paths(paths, cmd);
	ft_free_arr(paths);
	return (path);
}
