/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/19 13:52:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

a_b_list	stacks_a(char *numbers)
{
	char	**buf;
	int		*array;
	int		x;
	a_b_list		list_and_count;

	x = 0;
	buf = ft_split(numbers, ' ');
	(list_and_count).count = count_numbers(buf);
	array = malloc(sizeof(int) * (list_and_count.count));
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	(list_and_count).array_a = array;
	return (list_and_count);
}

int main (int argc, char **argv)
{
	a_b_list	array;
	char		*numbers;
	int			x;
	(void)argc;
	

	if (verif(argv) == -1)
		return (ft_printf("Error\n"));
	numbers = join_numbers(argv);
	if (error_overflow(numbers) == -1)
	{
		ft_printf("Error\n");
		return (free(numbers), numbers = NULL, 0);
	}
	array = stacks_a(numbers);
	if (check_duplicate(array) == -1)
		return (ft_printf("Error"), free(numbers), free(array.array_a), numbers = NULL, array.array_a = NULL, 0);
	x = 0;
	while (x < array.count)
	{
		ft_printf("%d\n",array.array_a[x]);
		x++;
	}
	free (array.array_a);
	free (numbers);
	return (0);
}