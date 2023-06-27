/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:13:17 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/27 13:37:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_command(char *str, char *new);
static char	*check_slash(char *cmd, char *str);

char	*cmd_build(char *str, char **env)
{
	int		new;
	char	*cmd;
	size_t	i;

	i = 0;
	cmd = NULL;
	cmd = check_slash(cmd, str);
	if (cmd == NULL && ft_in('/', str) == 1)
		return (NULL);
	while (env[i])
	{
		new = ft_strncmp(env[i], "PATH=", 5);
		if (!new)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	cmd = ft_strdup(&env[i][5]);
	if (!cmd)
		return (perror("Error"), NULL);
	cmd = search_command(str, cmd);
	if (cmd == NULL)
		return (errors(CMD, str), NULL);
	return (cmd);
}

static char	*search_command(char *str, char *new)
{
	char	**path;
	char	*cmd;
	int		i;

	path = ft_split(new, ':');
	free(new);
	if (path == NULL)
		return (perror("Error"), NULL);
	i = -1;
	while (path[++i])
	{
		new = ft_strjoin(path[i], "/");
		if (new == NULL)
			return (anihilation(path), errors(JOIN, "0"), NULL);
		cmd = ft_strjoin(new, str);
		free(new);
		new = NULL;
		if (cmd == NULL)
			return (anihilation(path), errors(JOIN, "0"), NULL);
		if (access(cmd, F_OK | X_OK) == 0)
			return (anihilation(path), cmd);
		free(cmd);
		cmd = NULL;
	}
	return (anihilation(path), free(cmd), NULL);
}

static char	*check_slash(char *cmd, char *str)
{
	if (ft_in('/', str) == 1)
	{
		cmd = ft_strdup(str);
		if (cmd == NULL)
			return (perror("Error"), NULL);
		if (access(cmd, F_OK | X_OK) == -1)
			return (errors(CMD, str), free(cmd), NULL);
		return (cmd);
	}
	return (cmd);
}
