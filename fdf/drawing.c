/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:33:37 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 10:59:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y);
static void	assign_zoom(t_data *data, float *coor_x, float *coor_y);
static void	bresenham(float coor_x1, float coor_y1, t_data *data);
static int	check_inbound(float new_x, float new_y);
static void	isometric(float *x, float *y, int z);

int	drawing(t_data *data)
{
	data->y0 = 0;
	while (data->y0 < data->height)
	{
		data->y1 = data->y0 + 1;
		data->x0 = 0;
		while (data->x0 < data->width)
		{
			data->x1 = data->x0 + 1;
			if (data->x0 < data->width - 1)
				bresenham(data->x0 + 1, data->y0, data);
			if (data->y0 < data->height - 1)
				bresenham(data->x0, data->y0 + 1, data);
			data->x0++;
		}
		data->y0++;
	}
	return (0);
}

static void	bresenham(float coor_x1, float coor_y1, t_data *data)
{
	int max;

	data->z0 = data->z_matrix[(int)data->y0][(int)data->x0];
	data->z1 = data->z_matrix[(int)coor_y1][(int)coor_x1];
	assign_pos(data, &coor_x1, &coor_y1);
	assign_zoom(data, &coor_x1, &coor_y1);
	isometric(&(data->new_x), &(data->new_y), data->z0);
	isometric(&coor_x1, &coor_y1, data->z1);
	data->x_step = coor_x1 - data->new_x;
	data->y_step = coor_y1 - data->new_y;
	max = fmax(fabs(data->x_step), fabs(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while (check_inbound(data->new_x, data->new_y) && ((int)(data->new_x - coor_x1) || (int)(data->new_y - coor_y1)))
	{
		my_mlx_pixel_put(data, (int)data->new_x + 960, (int)data->new_y + 540);
		data->new_x += data->x_step;
		data->new_y += data->y_step;
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = 0xffffff;
}

static void	assign_zoom(t_data *data, float *coor_x, float *coor_y)
{
	data->new_x *= data->zoom;
	data->new_y *= data->zoom;
	*coor_x *= data->zoom;
	*coor_y *= data->zoom;
	data->z0 *= data->zoom;
	data->z1 *= data->zoom;
}

static int	check_inbound(float new_x, float new_y)
{
	if ((new_x + 960 <= 1 || new_y + 540 >= 1080 \
	|| new_x + 960 >= 1920 || new_y + 540 <= 1))
		return (0);
	return (1);
}

static void	isometric(float *x, float *y, int z)
{
	float x1;
	
	x1 = *x;
	*x = (*x - *y) * cos(0.5);
	*y = (x1 + *y) * sin(0.5) - z;
}
