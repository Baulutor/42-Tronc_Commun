/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/24 16:02:12 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static void bresenham(int x, int y, float x1, float y1, t_data *data);
static void assign_pos(t_data *data, float *x1, float *y1, int *x, int *y, float *new_x, float *new_y);
static void	isometric(float *x, float *y, int z);
static void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

void drawing(t_data *data)
{
	int x;
	int y;
	y = 0;
	data->pos_tabx = 0;
	data->pos_taby = 0;
	while (y < data->height)
	{
		x = 0;
		data->pos_tabx = x;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
			data->pos_tabx = x;
		}
		y++;
		data->pos_taby = y;
	}
}

static void bresenham(int x, int y, float x1, float y1, t_data *data)
{
	float x_step;
	float y_step;
	float new_x;
	float new_y;
	int max;
	int z;
	int	z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	assign_pos(data, &x1, &y1, &x, &y, &new_x, &new_y);
	
	new_x *= data->zoom;
	new_y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom;
	z1 *= data->zoom;
	data->color = (z || z1) ? 0x800000 : 0xffffff;
	isometric(&new_x, &new_y, z);
	isometric(&x1, &y1, z1);
	new_x += 960;
	new_y += 540;
	x1 += 960;
	y1 += 540;
	x_step = x1 - new_x;
	y_step = y1 - new_y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(new_x - x1) || (int)(new_y - y1))
	{
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		// my_mlx_pixel_put(data, (int)new_x, (int)new_y, data->color);
		new_x += x_step;
		new_y += y_step;
	}
}
static void assign_pos(t_data *data, float *x1, float *y1, int *x, int *y, float *new_x, float *new_y)
{
	*new_x = *x - data->width / 2;
	*new_y = *y - data->height / 2;
	*x1 -= data->width / 2;
	*y1 -= data->height / 2;
}

static void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.5);
	*y = (*x + *y) * sin(0.5) - z;
}

static void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
