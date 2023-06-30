/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:42:18 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 16:07:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parsing(t_data *data);
static int	initialize_array(t_data *data);
static int	get_in_array(char **to_int, t_data *data);
static int	put_number_in_array(char **to_int, t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write(2, "Error : wrong numbers of arguments\n", 36), 1);
	data.path = argv[1];
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		return (perror("Error"), 1);
	data.zoom = 10;
	data.check = 1;
	if (fdf_initialize(&data) == 1)
		return (1);
	if (parsing(&data) == 1)
		return (1);
	data.check = 0;
	if (drawing(&data) == 1)
		return (1);
	mlx_key_hook(data.win, hooks, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (1);
}

static int	parsing(t_data *data)
{
	char	*str;
	char	**to_int;

	str = get_next_line(data->fd, 0);
	if (str == NULL)
		return (ft_close(data), 1);
	to_int = ft_split(str, ' ');
	free(str);
	if (to_int == NULL)
		return (get_next_line(data->fd, 1), ft_close(data), 1);
	get_width(to_int, data);
	ft_free_double_char(to_int);
	if (get_height(data) == 1)
		return (ft_close(data), 1);
	if (initialize_array(data) == 1)
		return (ft_close(data), 1);
	return (0);
}

static int	initialize_array(t_data *data)
{
	char	**to_int;

	data->limit = 0;
	to_int = NULL;
	data->z_matrix = malloc(sizeof(int **) * data->height);
	if (data->z_matrix == NULL)
		return (perror("Error"), 1);
	if (get_in_array(to_int, data) == 1)
		return (1);
	if (close(data->fd) == -1)
		return (perror("Error"), data->check = 0, 1);
	return (0);
}

static int	get_in_array(char **to_int, t_data *data)
{
	char	*str;

	while (data->limit < data->height)
	{
		str = get_next_line(data->fd, 0);
		if (str == NULL && to_int == NULL)
			return (perror("Error"), free(data->z_matrix), data->check = 1, 1);
		else if (str == NULL)
			break ;
		to_int = ft_split(str, ' ');
		if (to_int == NULL)
			return (free(str), get_next_line(data->fd, 1), ft_close(data), 1);
		free(str);
		data->z_matrix[data->limit] = malloc(sizeof(int) * data->width);
		if (data->z_matrix[data->limit] == NULL)
			return (perror("Error"), data->check = 1, \
			get_next_line(data->fd, 1), \
			ft_free_double_char(to_int), free(data->z_matrix), 1);
		if (put_number_in_array(to_int, data) == 1)
			return (1);
		data->limit++;
		ft_free_double_char(to_int);
	}
	return (0);
}

static int	put_number_in_array(char **to_int, t_data *data)
{
	int	x;

	x = 0;
	while (to_int[x])
	{
		if (check_width(data, to_int) == 1)
			return (write(2, "Error : wrong map not the same width\n", 38), \
			ft_free_double_char(to_int), \
			get_next_line(data->fd, 1), data->check = 0, 1);
		data->z_matrix[data->limit][x] = ft_atoi(to_int[x]);
		x++;
	}
	return (0);
}
