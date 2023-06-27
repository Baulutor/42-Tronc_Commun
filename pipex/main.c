/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:42 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/27 13:35:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *environ[])
{
	int	outin[2];

	if (ac == 5 && environ != NULL)
	{
		if (pipe(outin) == -1)
			return (errors(PIPE, NULL), 1);
		if (child(outin, av, environ) == 1)
			return (1);
		if (parent(outin, av, environ) == 1)
			return (1);
		close_pipe(outin);
		if (wait(NULL) == -1)
			return (errors(WAIT, NULL), 1);
		if (wait(NULL) == -1)
			return (errors(WAIT, NULL), 1);
	}
	else
		errors(CONDITIONS, NULL);
	return (0);
}
