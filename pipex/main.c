/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/20 11:16:21 by eslamber         ###   ########.fr       */
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
		wait(NULL);
		wait(NULL);
	}
	else
		errors(CONDITIONS, NULL);
	return (0);
}
