/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:50:47 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/26 11:05:45 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void assign_pos(t_data *data, float *x1, float *y1, int *x, int *y, float *new_x, float *new_y)
{
	*new_x = *x -(data->width / 2);
	*new_y = *y - (data->height / 2);
	*x1 -= (data->width / 2);
	*y1 -= (data->height / 2);
}

int	check_inbound(float new_x, float new_y)
{
	if ((new_x + 960 <= 1 || new_y + 540 >= 1080 \
	|| new_x + 960 >= 1920 || new_y + 540 <= 1))
		return (0);
	return (1);
}

void assign_zoom(t_data *data, t_pos *pos)
{
	pos->x1 *= data->zoom;
	pos->y1 *= data->zoom;
	pos->z *= data->zoom;
	pos->z1 *= data->zoom;
}