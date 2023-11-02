/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtins_parent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:57:06 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 15:43:25 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

static int	search_cd(char **exec_cmd, t_cmd *pip);
static int	search_export(char **exec_cmd, t_cmd *pip);
static int	search_unset(char **exec_cmd, t_cmd *pip);

int	parent_builtins(t_cmd *pip, char **exec_cmd)
{
	int	ret;

	pip->builtin = FALSE;
	if (ft_strlen(exec_cmd[0]) == 4 && ft_strncmp(exec_cmd[0], "exit", 4) == 0)
		return (intermediate_exit(exec_cmd), -1);
	ret = search_cd(exec_cmd, pip);
	if (ret == -1)
		return (-1);
	if (ret == 1)
		return (1);
	ret = search_export(exec_cmd, pip);
	if (ret == -1)
		return (-1);
	if (ret == 2)
		return (2);
	ret = search_unset(exec_cmd, pip);
	if (ret == -1)
		return (-1);
	if (ret == 3)
		return (3);
	return (0);
}

static int	search_cd(char **exec_cmd, t_cmd *pip)
{
	int	i;

	i = 0;
	if (ft_strlen(exec_cmd[0]) == 2 && ft_strncmp(exec_cmd[0], "cd", 2) == 0)
	{
		pip->parent_builtin = TRUE;
		if (exec_cmd[1] == NULL || (exec_cmd[1][0] == '~' && !exec_cmd[2] && \
		(!exec_cmd[1][1] || (exec_cmd[1][1] == '/' && !exec_cmd[1][2]))))
		{
			if (chdir("/") == -1)
				return (perror("Error "), g_status = 1, -1);
			while (pip->save_path[i])
			{
				if (chdir(pip->save_path[i]) == -1)
					return (perror("Error "), g_status = 1, -1);
				i++;
			}
			return (1);
		}
		return (cd(exec_cmd, pip), 1);
	}
	return (0);
}

static int	search_export(char **exec_cmd, t_cmd *pip)
{
	int	i;

	i = 1;
	if (ft_strlen(exec_cmd[0]) == 6 \
	&& ft_strncmp(exec_cmd[0], "export", 6) == 0)
	{
		pip->parent_builtin = TRUE;
		if (!exec_cmd[i])
			return (pip->parent_builtin = FALSE, 0);
		while (exec_cmd[i] != NULL)
		{
			if (export(pip, exec_cmd[i]) == -1)
				return (-1);
			i++;
		}
		return (2);
	}
	return (0);
}

static int	search_unset(char **exec_cmd, t_cmd *pip)
{
	int	i;

	i = 0;
	if (ft_strlen(exec_cmd[0]) == 5 && ft_strncmp(exec_cmd[0], "unset", 5) == 0)
	{
		pip->parent_builtin = TRUE;
		while (exec_cmd[i] != NULL)
		{
			if (unset(pip, exec_cmd[i]) == 1)
				return (-1);
			i++;
		}
		return (3);
	}
	return (0);
}
