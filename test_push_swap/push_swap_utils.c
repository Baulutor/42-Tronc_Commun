/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:14:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/17 18:43:12 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// how many number have to be malloc

int count_numbers(char **buf)
{
	size_t	x;
	
	x = 0;
	while (buf[x])
		x++;
	return (x);
}

// put all the numbers in the stack A

char	*join_numbers(char **argv)
{
	char	*numbers;
	int		y;
	
	y = 1;
	if (!argv[2])
	{
		numbers = ft_strdup(argv[y]);
		if (!numbers)
			return (NULL);
		return(numbers);
	}
	numbers = malloc(sizeof(char) * (ft_strlen(argv[y]) + 2));
	if (!numbers)
		return (NULL);
	while (argv[y])
	{
		numbers = ft_strjoin(numbers, argv[y]);
		y++;
	}
	return (numbers);
}


// look at the argv if there is no problem but not if the numbers is too high or too low

int	verif(char **argv)
{
	int x;
	int y;

	x = 1;
	y = 0;
	if (!argv[1])
		return (-1); // il faut gérer les chaines vides entre " "
	while (argv[x])
	{
		while (argv[x][y])
		{
			if (((argv[x][y] > '9' || argv[x][y] < '0') && argv[x][y] != ' ' && argv[x][y] != '-' && argv[x][y] != '+')
				|| ((argv[x][y] == '-' || argv[x][y] == '+') && (argv[x][y + 1] > '9' || argv[x][y + 1] < '0'))
				|| ((argv[x][y] == '-' || argv[x][y] == '+') && (argv[x][y - 1] <= '9' && argv[x][y - 1] >= '0')))
				return (-1);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

// check that the numbers aren't overflowing a 'int' type number

int	error_overflow(char *numbers)
{
	size_t	x;
	size_t	y;
	size_t	index;
	int		buf;

	y = 0;
	x = 0;
	index = 0;
	while(numbers[x])
	{
		while (numbers[x] == '0')
			x++;
		while(numbers[x] >= '0' && numbers[x] <= '9')
		{
			if (y > 8)
			{
				buf = ft_atoi(numbers + index);
				if (buf == 0 || buf == -1)
					return (-1);
			}
			y++;
			x++;
		}
		index = x;
		y = 0;
		x++;
	}
	return (0);
}

// check if the array didn't have two same value, send an error if it the case.

int	check_duplicate(a_b_list array)
{
	int	x;
	int	y;

	x = 0;
	y = x + 1;
	while (x < array.count)
	{
		while (y < array.count)
		{
			if (array.array_a[y] == array.array_a[x])
				return(-1);
			y++;
		}
		x++;
		y = x + 1;
	}
	return (0);
}