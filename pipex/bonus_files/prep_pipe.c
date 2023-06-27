/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:40:39 by marvin            #+#    #+#             */
/*   Updated: 2023/06/27 12:39:35 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	check_here_doc(char **av, t_pipex *struc, int ac);
static int		writing_here_doc(t_pipex *pip, char **av);
static int		get_str_to_print(t_pipex *pip);


int	prep_pipe(t_pipex *pip, char **av, int ac)
{
	int	i;

	i = 0;
	check_here_doc(av, pip, ac);
	if (pip->outin == NULL)
		return (ft_printf_fd(2, "Error : Problem with calloc function\n"), 1);
	while (i < pip->nb_pipe)
	{
		pip->outin[i] = (int *) ft_calloc(2, sizeof(int));
		if (pip->outin[i] == NULL)
		{
			pip->nb_pipe = i;
			ft_printf_fd(2, "Error : Problem with calloc function\n");
			return (close_all_pipes(pip), 1);
		}
		if (pipe(pip->outin[i]) == -1)
		{
			pip->nb_pipe = i;
			return (close_all_pipes(pip), errors(PIPE, NULL), 1);
		}
		i++;
	}
	if (verif_here_doc(pip, av) == 1)
		return (1);
	return (0);
}

static void	check_here_doc(char **av, t_pipex *struc, int ac)
{
	if (ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
		struc->here_doc = 1;
	else
		struc->here_doc = 0;
	struc->nb_proc = ac - 3 - struc->here_doc;
	struc->nb_pipe = struc->nb_proc - 1 + struc->here_doc;
	struc->error = OK;
	struc->outin = (int **)ft_calloc(struc->nb_pipe + 1, sizeof(int *));
}

int	set_up_heredoc(char **av, t_pipex *stru)
{
	stru->str = ft_strdup("\0");
	if (stru->str == 0)
		return (close_all_pipes(stru), errors_bonus(STRDUP), 1);
	stru->lenght = 1;
	if (writing_here_doc(stru, av) == 1)
		return (1);
	free(stru->str);
	free(stru->buf);
	return (0);
}

static int	writing_here_doc(t_pipex *pip, char **av)
{
	pip->str_heredoc = NULL;
	pip->buf = NULL;
	while (ft_strncmp(av[2], pip->str, pip->lenght) != 0)
	{
		free(pip->str);
		if (get_str_to_print(pip) == 1)
			return (1);
		pip->lenght = ft_strlen(pip->buf);
		pip->str = ft_strdup(pip->buf);
		if (pip->str == NULL)
			return (free_here_doc(pip), errors_bonus(STRDUP), 1);
		pip->str[pip->lenght - 1] = '\0';
	}
	if (write(pip->outin[0][1], pip->str_heredoc, \
		ft_strlen(pip->str_heredoc)) == -1)
		return (free_here_doc(pip), free(pip->str), errors_bonus(WRITE), 1);
	free(pip->str_heredoc);
	return (0);
}

static int	get_str_to_print(t_pipex *pip)
{
	if (pip->str_heredoc != NULL)
	{
		pip->str_heredoc = ft_strjoin_pip(pip->str_heredoc, pip->buf);
		if (pip->str_heredoc == NULL)
			return (errors(JOIN, NULL), 1);
	}
	if (pip->buf != NULL && pip->str_heredoc == NULL)
		return (close_all_pipes(pip), free(pip->buf), 1);
	if (pip->buf != NULL)
		free(pip->buf);
	if (write(STDOUT_FILENO, "> ", 2) == -1)
		errors_bonus(WRITE);
	pip->buf = get_next_line(STDIN_FILENO);
	if (pip->buf == NULL)
		errors_bonus(GNL);
	if (pip->str_heredoc == NULL)
		pip->str_heredoc = ft_strdup(pip->buf);
	if (pip->str_heredoc == NULL)
		return (free(pip->buf), errors_bonus(STRDUP), 1);
	return (0);
}
