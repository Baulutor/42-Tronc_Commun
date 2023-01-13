/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/13 15:35:03 by dbaule           ###   ########.fr       */
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

// split numbers into a array of int

int	*stacks_a(char *numbers)
{
	char	**buf;
	int	*array;
	int x;
	int		count;

	x = 0;
	
	while (numbers[x])
	{
		buf = ft_split(numbers, ' ');
		x++;
	}
	count = count_numbers(buf);
	array = malloc(sizeof(int *) * count);
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	return (array);
}

int main (int argc, char **argv)
{
	int		*array;
	char	*numbers;
	size_t	x;
	(void)argc;
	
	x = 0;
	if (verif(argv) == -1)
		return (printf("Error\n"));
	numbers = join_numbers(argv);
	array = stacks_a(numbers);
	while (array[x])
	{
		printf("%d\n",array[x]);
		x++;
	}
	return (0);
}