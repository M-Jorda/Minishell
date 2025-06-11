/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:41:32 by alearroy          #+#    #+#             */
/*   Updated: 2025/04/16 18:26:55 by alearroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

int		execute_command(t_command *cmd, t_env *env);
char	*get_path(char *cmd, char **envp);
t_list	*ast_to_command_list(t_ast_node *ast);

#endif
