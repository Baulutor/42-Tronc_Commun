/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:42:18 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 22:32:46 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static int	fdf_initialize(t_data *data, char **argv);
static int	ft_close(t_data *data);
static int	parsing(t_data *data);
static void get_width(char **to_int, t_data *data);
static int	put_in_array(t_data *data);
static int	get_height(t_data *data);


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write(2, "Error : wrong numbers of arguments\n", 36), 1);
	if (fdf_initialize(&data, argv))
		return (1);
	if (parsing(&data))
		return (1);
}

static int	parsing(t_data *data)
{
	char	*str;
	char	**to_int;
	
	str = get_next_line(data->fd);
	if (str == NULL)
		return (1);
	to_int = ft_split(str, ' ');
	free(str);
	if (to_int == NULL)
		return (1);
	get_width(to_int, data);
	get_height(data);
	put_in_array(data);
	return (0);
}

static int	fdf_initialize(t_data *data, char **argv)
{
	data->path = argv[1];
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		return (perror("Error"), 1);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return(write(2, "Error : mlx init won't start\n", 30), 1);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "mlx 42");
	if (data->win == NULL)
		return (write(2, "Error : new_window won't start\n", 32) , 1);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, ft_close, data->mlx);
	// mlx_hook(data->win, 2, 1L << 0, ft_close, data->mlx);
	mlx_loop(data->mlx);
	return (0);
} 

static int	ft_close(t_data *data)
{
	ft_free_z_matrix(data);
	// mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	close(data->fd);
	free(data->mlx);
	// free(data->win);
	// free(data->img);
	// free (data);
	exit(EXIT_SUCCESS);
	return (0);
}

static void get_width(char **to_int, t_data *data)
{
	int	x;

	x = 0;
	while (to_int[x])
		x++;
	data->width = x;
}

static int	put_in_array(t_data *data)
{
	char	*str;
	char	**to_int;
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->z_matrix = malloc(sizeof(int*) * data->height);
	while (y < data->height)
	{
		str = get_next_line(data->fd);
		if (str == NULL && to_int == NULL)
			return (1);
		else if (str == NULL)
			break;
		to_int = ft_split(str, ' ');
		if (to_int == NULL)
			return (1);
		while (to_int[x])
		{
			if (check_width(data, to_int) == 1)
				return (write(2, "Error : wrong map not the same width", 37));
			data->z_matrix = malloc(sizeof(int) * data->width);
			data->z_matrix[y][x] = ft_atoi(to_int[x]);
			x++;
		}
		y++;
	}
	close(data->fd);
	return (0);
}

static int	get_height(t_data *data)
{
	char	*str;

	str = "pass";
	data->height = 1;
	while (str != NULL)
	{
		str = get_next_line(data->fd);
		if (str == NULL && data->height == 1)
			return (1);
		if (str == NULL)
			break;
		data->height++;
	}
	if (close(data->fd) == -1)
		return (perror("Error"), 1);
	data->fd = open(data->path, O_RDONLY);
	if (data->fd == -1)
		return (perror("Error"), 1);
	return (0);
}


