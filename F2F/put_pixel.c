/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:14:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/27 19:16:32 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

#define MAX(a, b) (a > b ? a : b)

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

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
	data->color = (z || z1) ? 0x800000 : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z);
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(fmodule(x_step), fmodule(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1)) // peut etre necessaire d ele cast en int
	{
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}


void drawing(t_data *data)
{
	int x;
	int y;
	y = 0;
	
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}