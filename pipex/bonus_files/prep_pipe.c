/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:40:39 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 15:42:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void		check_here_doc(char **av, t_pipex *struc, int ac);
static int		set_up_heredoc(char **av, t_pipex *struc);
static int		writing_here_doc(t_pipex *pip, char **av);

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
	if (pip->here_doc == 1)
		set_up_heredoc(av, pip);
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
	struc->outin = (int **) ft_calloc(struc->nb_pipe + 1, sizeof(int *));
}

static int	set_up_heredoc(char **av, t_pipex *stru)
{
	stru->str = ft_strdup("\0");
	if (stru->str == 0)
		return (close_all_pipes(stru), errors_bonus(STRDUP), 1);
	stru->buf = ft_strdup("\0");
	if (stru->buf == 0)
		return (free(stru->str), close_all_pipes(stru), \
				errors_bonus(STRDUP), 1);
	stru->lenght = 1;
	if (writing_here_doc(stru, av) == 1)
		return (1);
	free(stru->str);
	free(stru->buf);
	return (0);
}

static int	writing_here_doc(t_pipex *pip, char **av)
{
	int	err;

	while (ft_strncmp(av[2], pip->str, pip->lenght) != 0)
	{
		free(pip->str);
		err = write(pip->outin[0][1], pip->buf, ft_strlen(pip->buf));
		if (pip->buf != NULL && err == -1)
			return (close_all_pipes(pip), free(pip->buf), \
					errors_bonus(WRITE), 1);
		if (pip->buf != NULL)
			free(pip->buf);
		if (write(STDOUT_FILENO, "> ", 2) == -1)
			errors_bonus(WRITE);
		pip->buf = get_next_line(STDIN_FILENO);
		if (pip->buf == NULL)
			errors_bonus(GNL);
		pip->lenght = ft_strlen(pip->buf);
		pip->str = ft_strdup(pip->buf);
		if (pip->str == NULL)
			errors_bonus(STRDUP);
		pip->str[pip->lenght - 1] = '\0';
	}
	return (0);
}
