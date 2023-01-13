/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:14:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/13 15:34:00 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_strlen for double array

int ft_strlen_array(char **argv)
{
	size_t	x;

	x = 0;
	while (argv[x])
		x++;
	return (x);
}

int ft_strlen_double(char **argv)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (argv[x])
	{
		while (argv[x][y])
			y++;
		x++;
	}
	return (y);
}


// add the last numbers to the chain

char	*add_last(char *argv, char *numbers)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	// if (!numbers)
	// {
	// 	numbers = malloc(sizeof(char) * ft_strlen(argv) + 2);
	// 	if (!numbers)
	// 		return (NULL);
	// }
	while (numbers[x])
		x++;
	while (argv[y])
	{
		numbers[x] = argv[y];
		y++;
		x++;
	}
	numbers[x] = ' ';
	numbers[x + 1] = '\0';
	return (numbers);
}

// put all the numbers in the stack A


char	*join_numbers(char **argv)
{
	char	*numbers;
	int		y;
	
	y = 1;
	while (argv[y + 1] != 0)
	{
		numbers = ft_strjoin(argv[y], argv[y + 1]);
		y++;
	}
	if (argv[y])
	{
		numbers = add_last(argv[y], numbers);
	}
	return (numbers);
}


// look at the argv if there is no problem

int	verif(char **argv)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (argv[x])
	{
		while (argv[x][y])
		{
			if (((argv[x][y] > '9' || argv[x][y] < '0') && (argv[x][y] != ' '))
			&& ((argv[x][y] == '-') && (argv[x][y + 1] < '0' || argv[x][y + 1] > '9'))
			&& ((argv[x][y] == '+') && (argv[x][y + 1] < '0' || argv[x][y + 1] > '9'))) // les signes nazes tu gere pas si il y a un signe seul sans rien
				return (-1);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}