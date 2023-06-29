/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:09:22 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 22:27:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_z_matrix(t_data *data)
{
	size_t	x;

	x = 0;
	while(data->height > (int)x)
	{
		free (data->z_matrix[x]);
		x++;
	}
	free (data->z_matrix);
	
}

int	check_width(t_data *data, char **to_int)
{
	int	x;

	x = 0;
	while (to_int[x])
		x++;
	if (x == data->width)
		return (0);
	else
		return (1);
}
