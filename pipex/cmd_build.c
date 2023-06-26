/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:13:17 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/26 18:11:50 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_command(char *str, char *new);

char	*cmd_build(char *str, char **env)
{
	int		new;
	char	*paths;
	char	*cmd;
	size_t	i;

	if (ft_in('/', str) == 1)
		return (ft_strdup(str));
	i = 0;
	while (env[i])
	{
		new = ft_strncmp(env[i], "PATH=", 5);
		if (!new)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	paths = ft_strdup(&env[i][5]);
	if (!paths)
		return (NULL);
	cmd = search_command(str, paths);
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
	i = 0;
	while (path[i + 1] && path[i++])
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
