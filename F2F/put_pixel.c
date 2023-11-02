/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/29 13:18:01 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static void	bresenham(int x, int y, float x1, float y1, t_data *data);
static void	isometric(float *x, float *y, int z);
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

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
	t_pos pos;
	int max;

	int z;
	int	z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	assign_pos(data, &x1, &y1, &x, &y, &pos.new_x, &pos.new_y);
	pos.new_x *= data->zoom;
	pos.new_y *= data->zoom;
	// assign_zoom(data, &pos);
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom;
	z1 *= data->zoom;
	data->color = (z || z1) ? 0x800000 : 0xffffff;
	isometric(&pos.new_x, &pos.new_y, z);
	isometric(&x1, &y1, z1);
	pos.x_step = x1 - pos.new_x;
	pos.y_step = y1 - pos.new_y;
	max = fmax(fabs(pos.x_step), fabs(pos.y_step));
	pos.x_step /= max;
	pos.y_step /= max;
	while (check_inbound(pos.new_x, pos.new_y) && ((int)(pos.new_x - x1) || (int)(pos.new_y - y1)))
	{
		my_mlx_pixel_put(data, (int)pos.new_x + 960, (int)pos.new_y + 540, data->color);
		pos.new_x += pos.x_step;
		pos.new_y += pos.y_step;
	}
}


static void	isometric(float *x, float *y, int z)
{
	float *x1;
	
	x1 = x;
	*x = (*x - *y) * cos(0.5);
	*y = (*x1 + *y) * sin(0.5) - z;
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


