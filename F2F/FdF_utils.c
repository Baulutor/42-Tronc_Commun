/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:12 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/31 16:26:30 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static int		width_count(char *str);
static int		width_check(int fd, int width);


t_data	*get_width_and_height(char *argv, t_data *data)
{
	int		fd;
	char	*str;

	data->width = 0;
	fd = open(argv, O_RDONLY, 0);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	data->width = width_count(str);
	free(str);
	data->height = width_check(fd, data->width);
	if (data->height == -1)
		return (NULL);
	close(fd);
	return (data);
}


static int		width_count(char *str)
{
	char	**array;
	int		x;
	
	x = 0;
	array = ft_split(str, ' ');
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
		while (check[y])
			y++;
		if (y != width)
			return (free(result), free_double_array(check), -1);
		y = 0;
		free (result);
		free_double_array(check);
		height++;
	}
	if (result != NULL)
		free (result);
	return(height);
}

void	free_double_array(char **array)
{
	int	x;
	
	x = 0;
	while (array[x])
	{
		free(array[x]);
		x++;
	}
	free(array);
}