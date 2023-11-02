/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:27:03 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/25 15:39:49 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static int	parsing(char *argv, t_data *data);
static int	put_numbers_in_array(t_data *array, int map);
static int	ft_close(t_data *data);
static void	assign_zoom_to_map(t_data *data);

int main(int argc, char **argv)
{
	t_data	data;
	(void)argc;
	int		map;

	if (!argv[1])
		return (1);
	data.width = 0;
	data.height = 0;
	if (parsing(argv[1], &data))
		return (1);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		return (ft_free_z_matrix(&data), 1);
	if (put_numbers_in_array(&data, map))
		return (1);
	data.mlx= mlx_init();
	if (data.mlx == NULL)
		return (ft_free_z_matrix(&data), perror("Error"), 1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "mlx 42");
	if (data.win == NULL)
		return (ft_free_z_matrix(&data), perror("Error"), 1);
	assign_zoom_to_map(&data);
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	drawing(&data);
	mlx_hook(&(data.win), 17, 0L, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}

static int	parsing(char *argv, t_data *data)
{
	int		map;
	char	*pars;
	int		x;
	int		test;
	
	x = 0;
	test = 0;
	if (get_width_and_height(argv, data) == -1)
		return (perror("Error"), 1);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	if (data->z_matrix == NULL)
		return (perror("Error"), 1);
	map = open(argv, O_RDONLY, 0);
	if (map == -1)
		return (free(data->z_matrix), 1);
	while (x <= data->height)
	{
		data->z_matrix[x] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!(data->z_matrix[x]))
			return (free(data->z_matrix), perror("Error"), 1);
		pars = get_next_line(map);
		if (pars == NULL && test == 0)
			return (ft_free_z_matrix(data), perror("Error"), 1);
		if (pars == NULL)
			break;
		free(pars);
		x++;
		test++;
	}
	close(map);
	return (0);
}

static int	put_numbers_in_array(t_data *array, int map)
{
	char	*str;
	char	**to_int;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (array->height > y)
	{
		str = get_next_line(map);
		if (str == NULL)
			return (1);
		to_int = ft_split(str, ' ');
		if (to_int == NULL)
			return (1);
		free (str);
		while (to_int[x])
		{
			array->z_matrix[y][x] = atoi(to_int[x]);
			x++;
		}
		x = 0;
		y++;
		free_double_array(to_int);
	}
	return (0);
}

static int	ft_close(t_data *data)
{
	ft_free_z_matrix(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// free (data);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	assign_zoom_to_map(t_data *data)
{
	if (data->height <= 30 && data->width <= 50)
		data->zoom = 30;
	else if(data->height <= 60 && data->width <= 100)
		data->zoom = 15;
	else
		data->zoom = 2;
}
