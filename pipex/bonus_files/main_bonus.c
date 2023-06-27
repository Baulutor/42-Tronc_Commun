/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:59:04 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/27 13:35:55 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	parent_process_wait(t_pipex *struc);
static int	end(t_pipex *struc);

int	main(int ac, char **av, char *environ[])
{
	t_pipex	struc;
	int		i;

	if (ac >= 5 && environ != NULL)
	{
		if (prep_pipe(&struc, av, ac) == 1)
			return (1);
		struc.ind_child = -1;
		while (++struc.ind_child < struc.nb_proc)
		{
			i = exec(&struc, ac, av, environ);
			if (i == 2)
				return (1);
			else if (i == 1)
				break ;
		}
		if (close_all_pipes(&struc) == 1)
			return (1);
		if (parent_process_wait(&struc) == 1)
			return (1);
	}
	else
		errors(CONDITIONS, NULL);
	return (end(&struc));
}

static int	parent_process_wait(t_pipex *struc)
{
	int	i;

	i = 0;
	while (i < struc->nb_proc)
	{
		if (wait(NULL) == -1)
			return (errors(WAIT, NULL), 1);
		i++;
	}
	return (0);
}

static int	end(t_pipex *struc)
{
	if (struc->error != OK)
		return (1);
	return (0);
}
