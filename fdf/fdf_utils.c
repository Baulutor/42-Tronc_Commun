/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:09:22 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 14:16:39 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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

int	ft_close(t_data *data)
{
	if (data->check == 0)
		ft_free_z_matrix(data, data->limit);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

void get_width(char **to_int, t_data *data)
{
	int	x;

	x = 0;
	while (to_int[x])
		x++;
	data->width = x;
}
