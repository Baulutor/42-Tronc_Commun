/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:59:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/25 15:24:03 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	end(t_pipex *struc);

int	main(int ac, char **av, char *environ[])
{
	t_pipex	struc;
	int		test;

	if (ac >= 5 && environ != NULL)
	{
		if (prep_pipe(&struc, av, ac) == 1)
			return (1);
		struc.ind_child = -1;
		while (++struc.ind_child < struc.nb_proc)
		{
			test = exec(&struc, ac, av, environ);
			if (test == 2)
				return (1);
			else if (test == 1)
				break ;
		}
		if (close_all_pipes(&struc) == 1)
			return (1);
		while (wait(NULL) > 0)
			;
	}
	else
		errors(CONDITIONS, NULL);
	return (end(&struc));
}

static int	end(t_pipex *struc)
{
	if (struc->error != OK)
		return (1);
	return (0);
}
