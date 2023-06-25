/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:04:51 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/22 18:41:14 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	close_all_pipes(t_pipex *pi)
{
	int	j;

	j = 0;
	while (j < pi->nb_pipe)
	{
		if (close(pi->outin[j][0]) == -1)
		{
			pi->error = CLOSE_P0;
			return (errors(CLOSE_P0, "0"), anihilation((char **) pi->outin), 1);
		}
		if (close(pi->outin[j][1]) == -1)
		{
			pi->error = CLOSE_P1;
			return (errors(CLOSE_P1, "0"), anihilation((char **) pi->outin), 1);
		}
		j++;
	}
	anihilation((char **) pi->outin);
	return (0);
}
