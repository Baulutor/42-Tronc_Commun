/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:13:17 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/20 11:23:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_command(char *str, char *new);

char	*cmd_build(char *str, char **env)
{
	char	*new;
	char	*cmd;
	size_t	i;

	if (ft_in('/', str) == 1)
		return (ft_strdup(str));
	i = 0;
	new = NULL;
	while (env[i])
	{
		new = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (new != NULL)
			break ;
		i++;
	}
	if (new == NULL)
		return (NULL);
	new += ft_strlen("PATH=");
	cmd = search_command(str, new);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}

static char	*search_command(char *str, char *new)
{
	char	**path;
	char	*cmd;
	int		i;

	path = ft_split(new, ':');
	if (path == NULL)
		return (NULL);
	i = 0;
	while (path[i])
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
		i++;
	}
	return (anihilation(path), free(cmd), NULL);
}
