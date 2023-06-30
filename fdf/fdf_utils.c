/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:09:22 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 16:06:05 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_initialize(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (write(2, "Error : mlx init won't start\n", 30), 1);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "mlx 42");
	if (data->win == NULL)
		return (write(2, "Error : new_window won't start\n", 32), \
		mlx_destroy_display(data->mlx), free(data->mlx), 1);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	if (data->img == NULL)
		return (write(2, "Error : Cant make a new image\n", 31), \
		mlx_destroy_window(data->mlx, data->win), \
		mlx_destroy_display(data->mlx), free(data->mlx), 1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (data->addr == NULL)
		return (write(2, "Error : Can't get address of the image\n", 40), \
		ft_close(data), 1);
	mlx_hook(data->win, 17, 0L, ft_close, data);
	return (0);
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

int	ft_close(t_data *data)
{
	if (data->check == 0)
		ft_free_z_matrix(data, data->limit);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	get_next_line(data->fd, 1);
	exit(EXIT_SUCCESS);
}

void	get_width(char **to_int, t_data *data)
{
	int	x;

	x = 0;
	while (to_int[x])
		x++;
	data->width = x;
}

int	get_height(t_data *data)
{
	char	*str;

	data->height = 1;
	while (1)
	{
		str = get_next_line(data->fd, 0);
		if (str == NULL && data->height == 1)
			return (get_next_line(data->fd, 1), 1);
		if (str == NULL)
			break ;
		if (str[0] != '\n')
			data->height++;
		free(str);
	}
	if (close(data->fd) == -1)
		return (perror("Error"), 1);
	data->fd = open(data->path, O_RDONLY);
	if (data->fd == -1)
		return (perror("Error"), 1);
	return (0);
}
