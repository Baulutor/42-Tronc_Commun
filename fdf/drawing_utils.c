/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:26:55 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 14:44:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_pos(t_data *data, float *coor_x, float *coor_y)
{
	data->new_x = data->x0 -(data->width / 2);
	data->new_y = data->y0 - (data->height / 2);
	*coor_x -= (data->width / 2);
	*coor_y -= (data->height / 2);
}

void	assign_zoom(t_data *data, float *coor_x, float *coor_y)
{
	data->new_x *= data->zoom;
	data->new_y *= data->zoom;
	*coor_x *= data->zoom;
	*coor_y *= data->zoom;
	data->z0 *= data->zoom;
	data->z1 *= data->zoom;
}

int	zoom_key(t_data *data, int key)
{
	if (key == 65453)
		data->zoom -= 1;
	if (key == 65451)
		data->zoom += 1;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	drawing(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	hooks(int key, t_data *data)
{
	if (key == 65451 || key == 65453)
		zoom_key(data, key);
	if (key == 65307)
		ft_close(data);
	return (0);
}
