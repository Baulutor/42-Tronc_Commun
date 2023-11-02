/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_center_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:17:58 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 16:56:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	execute_child(char **environ, char **str, t_cmd *pip);
static int	in_case_execve_didnt_work(t_cmd *pip, DIR *dir, char *cmd);

int	cmd_center_simple(char **str, t_cmd *pip)
{
	if (search_builtins(str, pip) == 1)
		return (1);
	if (execute_child(pip->env, str, pip) == 1)
		return (1);
	return (-1);
}

static int	execute_child(char **environ, char **str, t_cmd *pip)
{
	char	*cmd;
	DIR		*dir;

	dir = NULL;
	if (str[0][0] == '\0')
		return (error(CMD, str[0]), 1);
	cmd = cmd_build(str[0], environ);
	if (cmd == NULL)
		return (1);
	exec_signals();
	execve(cmd, str, pip->env);
	if (in_case_execve_didnt_work(pip, dir, cmd) == 1)
		return (1);
	return (1);
}

static int	in_case_execve_didnt_work(t_cmd *pip, DIR *dir, char *cmd)
{
	pip->ani_flag = 1;
	dir = opendir(cmd);
	if (dir == NULL && access(cmd, F_OK | X_OK) != -1)
	{
		ft_printf_fd(2, "Error : invalid permission\n");
		free(cmd);
		return (1);
	}
	else if (dir != NULL)
		error(DIREC, cmd);
	else
		error(EXEC, "0");
	closedir(dir);
	free(cmd);
	return (0);
}
