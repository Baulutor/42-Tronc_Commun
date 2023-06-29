/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:33:37 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 23:00:07 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y);

int	drawing(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x0 = data->z_matrix[y][x]; // en verite ici je garde le z
			data->x1 = data->z_matrix[y][x + 1];
			data->y0 = data->z_matrix[y][x];
			data->y1 = data->z_matrix[y + 1][x];
		}
		y++;
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int*)dst = color;
}

static void	making_absolute_value(t_data *data)
{
	if ()	
}
