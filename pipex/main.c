/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/26 18:10:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *environ[])
{
	int		outin[2];

	if (ac == 5 && environ != NULL)
	{
		if (pipe(outin) == -1)
			return (errors(PIPE, NULL), 1);
		if (child(outin, av, environ) == 1)
			return (1);
		if (parent(outin, av, environ) == 1)
			return (1);
		close_pipe(outin);
		waitpid(-1, NULL, 0);
	}
	else
		errors(CONDITIONS, NULL);
	return (0);
}
