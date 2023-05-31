/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:12 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/24 17:21:52 by dbaule           ###   ########.fr       */
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
		return(perror("open"), NULL);
	str = get_next_line(fd);
	if (str == NULL)
		return (perror("malloc"), NULL);
	data->width = width_count(str);
	free(str);
	data->height = width_check(fd, data->width);
	if (data->height == -1)
		return(NULL); // free data ??
	close(fd);
	return (data);
}


static int		width_count(char *str)
{
	char	**array;
	int		x;
	
	x = 0;
	array = ft_split_fdf(str, ' ');
	while (array[x])
	{
		printf("array %s\n" , array[x]);
		x++;
	}
	free_double_array(array);
	return(x);
}
static int		width_check(int fd, int width)
{
	char	*result;
	char	**check;
	int		height;
	int		y;
	// int		test;
	
	y = 0;
	height = 1;
	// test = 0;
	result = "test";
	while (result != NULL)
	{
		result = get_next_line(fd);
		// if (!result && test == 0)
		// 	return (perror("malloc"), -1);
		if (result == NULL)
			break;
		check = ft_split_fdf(result, ' ');
		if (!check)
			return(perror("malloc"), -1);
		while (check[y])
			y++;
		if (y != width)
			return (write(2, "Error, not the same amount of number on axes, or too many line break\n", 70), free(result), free_double_array(check), -1);
		y = 0;
		free (result);
		free_double_array(check);
		height++;
	}
	ft_printf("apres check\n");
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
