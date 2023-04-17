/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:27:03 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/17 14:25:50 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	// ft_free_maps(data);
	exit(EXIT_SUCCESS);
}

int **put_numbers_in_array(t_data *array, int map)
{
	char	*str;
	char	**to_int;
	int		x;
	int		y;
	int		**array_return;

	x = 0;
	y = 0;
	array_return = array->z_matrix;
	ft_printf("avant de retrer dans la boucle put numbers la hauteur %d", array->height);
	while (array->height > y)
	{
		str = get_next_line(map);
		to_int = ft_split(str, ' ');
		while (to_int[x])
		{
			ft_printf("la to_int %s\n", to_int[x]);
			array->z_matrix[y][x] = atoi(to_int[x]);
			x++;
		}
		x = 0;
		y++;
	}
	return (array_return);
}


// il y a + opti pour mettre un pixel, tu verra plus tard sur le site https://harm-smits->github->io/42docs/libs/minilibx/getting_started->html#x-your-skills

// + y est eleve plus il est bas et plus x eteleve plus il est a droite

//il faut faire un parsing pur uniquement avoir des nombre utilisable, utilise split and get_next line, pour avoir leur ordinate et leur axis, 
// un compteur de nombre de fois u tu a eu besoin de faire get next line pour estimer l'ordonne, sinon l'axe selon la position dans le split->

int	parsing(char *argv, t_data *data)
{
	int		map;
	char	*pars;
	int		x;
	int		test;
	
	x = 0;
	test = 0;
	data->width = get_width(argv);
	if (data->width == -1)
		return(-1);
	data->height = get_height(argv);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1)); // pas sur du +1 pareil pour celui d'apres
	if (data->z_matrix == NULL)
		return(-1);
	map = open(argv, O_RDONLY, 0);
	if (map == -1)
		return (0);
	while (x <= data->height)
	{
		data->z_matrix[x] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!(data->z_matrix[x]))
			return(-1);
		pars = get_next_line(map);
		if (pars == NULL && test == 0)
			return (-1);
		if (pars == NULL)
			break;
		// if(verif(pars) == -1) // gere pas les couleurs.
		// 	return (free(pars), printf("prob au parsing\n"), 0);
		
		x++;
		test++;
	}
	close(map);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	*data;
	(void)argc;
	int		map;

	data = malloc(sizeof(data));
	data->width = 0;
	data->height = 0;
	if (!argv[1])
		return (0);
	if (parsing(argv[1], data) == -1)
		return(printf("Error"), 0);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		return (0); // faut free tous le parsing 
	ft_printf("avant le transfert\n");
	data->z_matrix = put_numbers_in_array(data, map);
	if (data->z_matrix == NULL)
		return (ft_printf("Error from color"), 0);


	
	data->mlx= mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "mlx 42");
	data->zoom = 20;

	
	drawing(data);
	mlx_hook(data->win, 17, 0, ft_close, data->mlx);
	mlx_loop(data->mlx);
	
	return (0);
}
