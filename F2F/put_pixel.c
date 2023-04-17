/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/17 14:37:22 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

#define MAX(a, b) (a > b ? a : b)

void bresenham(float x, float y, float x1, float y1, t_data *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int	z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z) ? 0x800000 : 0xffffff;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1)) // peut etre necessaire d ele cast en int
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}

void drawing(t_data *data)
{
	int x;
	int y;
	y = 0;
	
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
		{
			if (x < data->width)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}