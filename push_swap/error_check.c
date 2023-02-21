/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:16:07 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/21 16:35:12 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_spacebar(char *argv)
{
	size_t	x;

	x = 0;
	if (argv[x] == '\0')
		return (-1);
	while (argv[x] == ' ' || (argv[x] < '0' && argv[x] > '9'))
	{
		x++;
		if (!argv[x])
			return (-1);
	}
	return (0);
}

/* look at the argv if there is no problem 
but not if the numbers is too high or too low*/

int	verif(char **argv)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	if (!argv[1])
		return (-1);
	while (argv[x])
	{
		if (verif_spacebar(argv[x]) == -1)
			return (-1);
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
	x = 0;
	while (numbers[x])
	{
		while (numbers[x] == '0')
			x++;
		while (numbers[x] >= '0' && numbers[x] <= '9')
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
		if (numbers[x])
			x++;
	}
	return (0);
}

// check if the array didn't have two same value, send an error if it the case.

int	check_duplicate(t_a_b_list array)
{
	int	x;
	int	y;

	x = 0;
	y = x + 1;
	while (x < array.count)
	{
		while (y < array.count && array.array_a[y])
		{
			if (array.array_a[y] == array.array_a[x])
				return (-1);
			y++;
		}
		x++;
		y = x + 1;
	}
	return (0);
}

s_stack	*error_check_and_initialize(char **argv)
{
	t_a_b_list	array;
	s_stack		*stack_a;
	char		*numbers;

	if (verif(argv) == -1)
		return (ft_printf("Error, please put only numbers, nothing else\n"), NULL);
	numbers = join_numbers(argv);
	if (numbers == NULL)
		return (ft_printf("Error of allocation\n"), NULL);
	if (error_overflow(numbers) == -1)
		return (ft_printf("Error, one or more numbers exceed the capacity of a integer\n"), free(numbers), numbers = NULL, NULL);
	array = stacks_a(numbers);
	if (check_duplicate(array) == -1)
		return (ft_printf("Error, got two or more duplicate numbers"), free(numbers), free(array.array_a), numbers = NULL, array.array_a = NULL, NULL);
	stack_a = NULL;
	stack_a = linked_list_initialise(array);
	free (numbers);
	free(array.array_a);
	return (stack_a);
}
