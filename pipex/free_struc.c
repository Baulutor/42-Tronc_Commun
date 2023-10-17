/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:33:13 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/17 13:46:10 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	anihilation(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

int	close_pipe(int outin[2])
{
	if (close(outin[0]) == -1)
		return (errors(CLOSE_P0, "0"), 1);
	if (close(outin[1]) == -1)
		return (errors(CLOSE_P1, "0"), 1);
	return (0);
}
