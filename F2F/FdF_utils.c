/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:12 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 18:22:56 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static int		width_count(char *str);
static int		width_check(int fd, int width);


int	get_width_and_height(char *argv, t_data *data)
{
	int		fd;
	char	*str;

	data->width = 0;
	fd = open(argv, O_RDONLY, 0);
	if (fd == -1)
		return (perror("Error"), 1);
	str = get_next_line(fd);
	if (str == NULL)
		return (1);
	data->width = width_count(str);
	free(str);
	data->height = width_check(fd, data->width);
	if (data->height == -1)
		return (1);
	if (close(fd) == -1)
		return(perror("Error"), 1);
	return (0);
}

static int		width_count(char *str)
{
	char	**array;
	int		x;
	
	x = 0;
	array = ft_split(str, ' ');
	if (array == NULL)
		return (perror("Error"), -1);
	while (array[x])
		x++;
	free_double_array(array);
	return(x);
}
static int		width_check(int fd, int width)
{
	char	*result;
	char	**check;
	int		height;
	int		y;
	
	y = 0;
	height = 1;
	result = "test";
	while (result != NULL)
	{
		result = get_next_line(fd);
		if (result == NULL)
			break;
		check = ft_split(result, ' ');
		if (check == NULL)
			return (perror("Error"), -1);
		while (check[y])
			y++;
		if (y != width)
			return (write(2 ,"Error, not the same width in the map\n", 38), \
			free(result), free_double_array(check), -1);
		y = 0;
		free (result);
		free_double_array(check);
		height++;
	}
	if (result != NULL)
		free (result);
	return (height);
}

void	free_double_array(char **array)
{
	size_t	x;

	x = 0; 
	while (array[x])
	{
		free(array[x]);
		x++;
	}
	free(array);
}

void	ft_free_z_matrix(t_data *data)
{
	size_t	x;

	x = 0;
	while(data->height > (int)x)
	{
		free (data->z_matrix[x]);
		x++;
	}
	free (data->z_matrix);
	
}
