/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:33:13 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/20 10:51:06 by eslamber         ###   ########.fr       */
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
