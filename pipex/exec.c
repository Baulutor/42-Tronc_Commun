/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:48:21 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/26 18:28:36 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	exec_child(int outin[2], char **av, char **environ);
static int	exec_parent(int outin[2], char **av, char **environ);

int	child(int outin[2], char **av, char **environ)
{
	int		id;

	id = fork();
	if (id == 0)
		return (exec_child(outin, av, environ));
	else if (id == -1)
		return (errors(FORK, NULL), 1);
	else
		return (0);
}

int	parent(int outin[2], char **av, char **environ)
{
	int		id;

	id = fork();
	if (id == 0)
		return (exec_parent(outin, av, environ));
	else if (id == -1)
		return (errors(FORK, NULL), 1);
	else
		return (0);
}

static int	exec_child(int outin[2], char **av, char **environ)
{
	char	*cmd;
	char	**splitted;
	int		infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		return (ft_printf_fd(2, "Error: %s: ", av[1]), perror(""), 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (dup2(outin[1], STDOUT_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (close(infile) == -1)
		return (errors(CLOSE, NULL), 1);
	splitted = ft_split(av[2], ' ');
	if (splitted == NULL)
		return (errors(SPLIT, NULL), 1);
	cmd = cmd_build(splitted[0], environ);
	if (cmd == NULL)
		return (errors(CMD, splitted[0]), anihilation(splitted),  1);
	if (close_pipe(outin) == 1)
		return (free(cmd), anihilation(splitted), 1);
	if (execve(cmd, splitted, environ) == -1)
		errors(EXEC, "0");
	return (free(cmd), anihilation(splitted), 1);
}

static int	exec_parent(int outin[2], char **av, char **environ)
{
	char	*cmd;
	char	**splitted;
	int		outfile;

	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		return (ft_printf_fd(2, "Error: %s: ", av[4]), perror(""), 1);
	if (dup2(outin[0], STDIN_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (close(outfile) == -1)
		return (errors(CLOSE, NULL), 1);
	splitted = ft_split(av[3], ' ');
	if (splitted == NULL)
		return (errors(SPLIT, NULL), 1);
	cmd = cmd_build(splitted[0], environ);
	if (cmd == NULL)
		return (errors(CMD, splitted[0]), anihilation(splitted), 1);
	if (close_pipe(outin) == 1)
		return (free(cmd), anihilation(splitted), 1);
	if (execve(cmd, splitted, environ) == -1)
		errors(EXEC, "0");
	return (free(cmd), anihilation(splitted), 1);
}
