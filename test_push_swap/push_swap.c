/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/19 17:24:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int



int main (int argc, char **argv)
{
	a_b_list	array;
	char		*numbers;
	int			x;
	(void)argc;
	
		return (0);
	if (verif(argv) == -1)
		return (ft_printf("Error\n"));
	numbers = join_numbers(argv);
	if (error_overflow(numbers) == -1)
		return (ft_printf("Error\n"), free(numbers), numbers = NULL, 0);
	array = stacks_a(numbers);
	if (check_duplicate(array) == -1)
		return (ft_printf("Error\n"), free(numbers), free(array.array_a), numbers = NULL, array.array_a = NULL, 0);
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