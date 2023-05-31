/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:22:05 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 18:20:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*allocation_cat(char *cmd);

int	exec_hub(char *cmd)
{
	char	**suffix;
	char	*cat;

	cat = allocation_cat(cmd);
	suffix = ft_split(cat, ' ');
	if (suffix[1] == 0)
	{
		char *args[] = {suffix[0], NULL};
		execve(*suffix, args, NULL);
		return (perror("execve"), -1);
	}
	else if (suffix[2] == 0)
	{
		char *args[] = {suffix[0], suffix[1], NULL};
		execve(*suffix, args, NULL);
		return (perror("execve"), -1);
	}
	else
	{
		char *args[] = {suffix[0], suffix[1], suffix[2], NULL};
		execve(*suffix, args, NULL);
		return (perror("execve"), -1);
	}
	exit(EXIT_FAILURE);
	return(0);
}

static char	*allocation_cat(char *cmd)
{
	char	*cat;
	char	*path;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (cmd[0] == '/' && cmd[1] == 'b' && cmd[2] == 'i' && cmd[3] == 'n' && cmd[4] == '/')
		return (cmd);
	path = "/bin/";
	cat = malloc(sizeof(char) * (5 * ft_strlen(cmd)) + 1);
	while (x < 5)
	{
		cat[x] = path[x];
		x++;
	}
	while (cmd[y])
	{
		cat[x] = cmd[y];
		x++;
		y++;
	}
	cat[x] = 0;
   x = 0;
   while (cat[x])
   {
      ft_printf("%c\n" , cat[x]);
      x++;
   }
	return (cat);
}