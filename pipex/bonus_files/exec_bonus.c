/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:48:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/25 15:59:37 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	exec_child(t_pipex *pip, int ac, char **av, char **environ);
static int	dup_in_file_child(t_pipex *pip, char **av);
static int	dup_out_file_child(t_pipex *pip, char **av, int ac);
static int	execute_child(t_pipex *pip, char **environ, char **av);

/*
Forking -> creating a child process that will execute command
*/

int	exec(t_pipex *struc, int ac, char **av, char **environ)
{
	int	id;

	id = fork();
	if (id == -1)
	{
		struc->error = FORK;
		return (errors(FORK, "0"), 1);
	}
	if (id == 0)
	{
		if (exec_child(struc, ac, av, environ) == 1)
			return (1);
	}
	return (0);
}

/*
The hub to execute all the child that we need to
*/

static int	exec_child(t_pipex *pip, int ac, char **av, char **environ)
{
	int err;

	if (dup_in_file_child(pip, av) == 1)
		return (1);
	if (dup_out_file_child(pip, av, ac) == 1)
		return (1);
	err = execute_child(pip, environ, av);
	if (err == 1)
		return (1);
	else if (err == 2)
		return (2); //besoin de faire deux code erreur ?
	return (0);
}

/* 
Set up where the execution need to get his information
for applicate the command
*/

static int	dup_in_file_child(t_pipex *pip, char **av)
{
	int	infile;

	if (pip->ind_child == 0 && pip->here_doc == 0)
	{
		infile = open(av[1], O_RDONLY);
		if (infile == -1)
			return (errors(OPEN, "0"), 1);
		if (dup2(infile, STDIN_FILENO) == -1)
			return (errors(DUP, "0"), 1);
		if (close(infile) == -1)
			return (errors(CLOSE, "0"), 1);
	}
	else if (pip->ind_child == 0 && pip->here_doc == 1)
	{
		if (dup2(pip->outin[pip->ind_child][0], STDIN_FILENO) == -1)
			return (errors(DUP, "0"), 1);
	}
	else if (pip->ind_child != 0)
	{
		if (dup2(pip->outin[pip->ind_child - 1 + pip->here_doc][0], STDIN_FILENO) == -1)
			return (errors(DUP, "0"), 1);
	}
	return (0);
}

/*
Set up the STDOUT_FILENO for putting the information that we gonna get
when we will execute the command
*/

static int	dup_out_file_child(t_pipex *pip, char **av, int ac)
{
	int	outfile;

	if (pip->ind_child == pip->nb_pipe - pip->here_doc)
	{
		outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR + \
				S_IWUSR + S_IRGRP + S_IROTH);
		if (outfile < 0)
			return (errors(OPEN, "0"), 1);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			return (errors(DUP, "0"), 1);
		if (close(outfile) == -1)
			return (errors(CLOSE, "0"), 1);
	}
	else
	{
		if (dup2(pip->outin[pip->ind_child + pip->here_doc][1], STDOUT_FILENO) == -1)
			return (errors(DUP, "0"), 1);
	}
	return (0);
}

/* get the command from the arguments that the user set it up for the computer
and execute it */

static int	execute_child(t_pipex *pip, char **environ, char **av)
{
	char	**splitted;
	char	*cmd;

	splitted = ft_split(av[pip->ind_child + pip->here_doc + 2], ' ');
	if (splitted == NULL)
		return (errors(SPLIT, "0"), 1);
	cmd = cmd_build(splitted[0], environ);
	if (cmd == NULL)
		return (errors(CMD, splitted[0]), anihilation(splitted), 1);
	if (close_all_pipes(pip) == 1)
		return (free(cmd), anihilation(splitted), 2);
	execve(cmd, splitted, environ);
	errors(EXEC, "0");
	return (free(cmd), anihilation(splitted), 2); //pk code erreur 2 ??
}
