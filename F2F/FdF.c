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
static void	parsing(char *argv, t_data *data);
static int **put_numbers_in_array(t_data *array, int map);
static void	ft_free_maps(int **data);
static int	ft_close(t_data *data);

int main(int argc, char **argv)
{
	t_data	data;
	(void)argc;
	int		map;

	if (!argv[1])
		return (0);
	data.width = 0;
	data.height = 0;
	parsing(argv[1], &data);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		return (-1); // faut free tous le parsing
	data.z_matrix = put_numbers_in_array(&data, map);
	if (data.z_matrix == NULL)
		return (printf("Error"), -1);
	data.mlx= mlx_init();
	if (data.mlx == NULL)
		return (ft_free_maps(data.z_matrix), -1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "mlx 42");
	if (data.win == NULL)
		return (ft_free_maps(data.z_matrix),-1);
	data.zoom = 30;
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	drawing(&data);
	mlx_hook(data.win, 17, 0, ft_close, data.mlx);
	mlx_hook(data.win, 2, 1L << 0, ft_close, data.mlx);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}

static void	parsing(char *argv, t_data *data)
{
	int		map;
	char	*pars;
	int		x;
	int		test;
	
	x = 0;
	test = 0;
	data = get_width_and_height(argv, data);
	if (data->width == -1 || data->height == -1)
		return (perror("error"));
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1)); // pas sur du +1 pareil pour celui d'apres
	if (data->z_matrix == NULL)
		return (perror("malloc"));
	map = open(argv, O_RDONLY, 0);
	if (map == -1)
		return ;
	while (x <= data->height)
	{
		data->z_matrix[x] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!(data->z_matrix[x]))
			return;
		pars = get_next_line(map);
		if (pars == NULL && test == 0)
			return ;
		if (pars == NULL)
		{
			free (pars);
			break;
		}
		free(pars);
		x++;
		test++;
	}
	close(map);
	return;
}

static int **put_numbers_in_array(t_data *array, int map)
{
	char	*str;
	char	**to_int;
	int		x;
	int		y;
	int		**array_return;

	x = 0;
	y = 0;
	array_return = array->z_matrix;
	while (array->height > y)
	{
		str = get_next_line(map);
		to_int = ft_split(str, ' ');
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
	return (array_return);
}
void	ft_free_pars(char **to_free)
{
	size_t x;

	x = 0;
	while (to_free[x])
	{
	printf("free_pars\n");
		free(to_free[x]);
		x++;
	}
	free(to_free);
}

static void	ft_free_maps(int **data)
{
	size_t	x;

	x = 0;
	while (data[x])
	{
		free (data[x]);
		x++;
	}
	free (data);
}


static int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	// ft_free_maps(data->z_matrix);
	free(data->mlx);
	// free (data);
	exit(EXIT_SUCCESS);
	return (0);
}

// il y a + opti pour mettre un pixel, tu verra plus tard sur le site https://harm-smits->github->io/42docs/libs/minilibx/getting_started->html#x-your-skills

// + y est eleve plus il est bas et plus x eteleve plus il est a droite

//il faut faire un parsing pur uniquement avoir des nombre utilisable, utilise split and get_next line, pour avoir leur ordinate et leur axis, 
// un compteur de nombre de fois u tu a eu besoin de faire get next line pour estimer l'ordonne, sinon l'axe selon la position dans le split->

