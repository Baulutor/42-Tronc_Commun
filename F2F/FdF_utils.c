/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:12 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/17 13:53:59 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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

int		width_check(int fd, int width)
{
	char	*result;
	char	**check;
	int		y;
	
	y = 0;
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
			return (-1);
		y = 0;
	}
	free_double_array(check); // surement leaks
	free (result);
	return(0);
}

int		width_count(char *str)
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

int	get_width(char *argv)
{
	int		fd;
	int		width;
	char	*str;

	width = 0;
	fd = open(argv, O_RDONLY, 0);
	str = get_next_line(fd);
	width = width_count(str);
	if (width_check(fd, width) == -1)
		return(-1);
	close(fd);
	return (width);
}

int	get_height(char *argv)
{
	int		fd;
	int		height;
	char	*str;

	height = 0;
	fd = open(argv, O_RDONLY, 0);
	str = "test";
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		height++;
	}
	close (fd);
	return (height);
}