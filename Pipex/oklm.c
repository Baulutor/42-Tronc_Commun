/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oklm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/05/16 18:53:01 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*cmd_build(char *str)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (str[0] == '/' && str[1] == 'b' && str[2] == 'i' && str[3] == 'n'
			&& str[4] == '/')
		return (str);
	new = (char *) malloc(sizeof(char) * (5 + ft_strlen(str)));
	if (!new)
		return(NULL);
	i = 5;
	j = 0;
	new[0] = '/';
	new[1] = 'b';
	new[2] = 'i';
	new[3] = 'n';
	new[4] = '/';
	while (j < ft_strlen(str))
		new[i++] = str[j++];
	new[i] = 0;
	return (new);
}

#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	int		id;
	int		outin[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	**trql;

	if (pipe(outin) == -1)
		ft_printf("Error : There is a probleme with the pipe system.\n");
	id = fork();
	if (ac == 5)
	{
		if (id == 0) // child
		{
			close(outin[0]);
			infile = open(av[1], O_RDONLY);
			if (infile == -1)
				ft_printf("Error : Wrong opening infile.\n");
			if (dup2(infile, STDIN_FILENO) == -1)
				return (1);
			if (dup2(outin[1], STDOUT_FILENO) == -1);
				return (1);
			close(infile);
			cmd = cmd_build(ft_split(av[2], ' ')[0]);
			if (!cmd)
				return (1);
			if (execve(cmd, ft_split(av[2], ' '), env) == -1)
				ft_printf("Error : Wrong child execution.\n");
		}
		else if (id > 0) // parent
		{
			wait(NULL);
			close(outin[1]);
			outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);
			if (outfile < 0)
				ft_printf("Error : Wrong opening outfile.\n");
			if (dup2(outin[0], STDIN_FILENO) == -1)
			{
				ft_printf("Error : Problem with first dup programme in parent.\n");
				return 1;
			}
			if (dup2(outfile, STDOUT_FILENO) == -1)
			{
				ft_printf("Error : Problem with second dup programme in parent.\n");
				return 1;
			}
			close(outfile);
			cmd = cmd_build(ft_split(av[3], ' ')[0]);
			dprintf(2, "%s\n\n", cmd);
			/* ft_printf("cmd = %s\n", cmd); */
			if (!cmd)
				return (1);
			if (execve(cmd, ft_split(av[3], ' '), env) == -1)
			{
				ft_printf("Error : Wrong parent execution.\n");
				return (1);
			}
		}
		else
			ft_printf("Error : There is a problem with the fork system.\n");
	}
	else
		ft_printf("Error : You don't have enought parameters.\n");
	return (0);
}