/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:16:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 16:11:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
freeing data->z_matrix, 
the value of y depend on if the program as an error or not.
*/

void	ft_free_z_matrix(t_data *data, int y)
{
	size_t	x;

	x = 0;
	if (data->limit == data->height)
		y--;
	while (y >= (int)x)
	{
		free (data->z_matrix[x]);
		x++;
	}
	free (data->z_matrix);
}

void	ft_free_double_char(char **tofree)
{
	int	x;

	x = 0;
	while (tofree[x])
	{
		free(tofree[x]);
		x++;
	}
	free(tofree);
}
