/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/26 18:35:24 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

a_b_list	stacks_a(char *numbers)
{
	char		**buf;
	int			*array;
	int			x;
	a_b_list	a_listnd_count;

	x = 0;
	buf = ft_split(numbers, ' ');
	(a_listnd_count).count = count_numbers(buf);
	array = malloc(sizeof(int) * (a_listnd_count.count));
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	(a_listnd_count).array_a = array;
	return (a_listnd_count);
}

int main (int argc, char **argv)
{
	a_b_list	array;
	a_list		*stack_a;
	a_list		*stack_b;
	char		*numbers;
	int			x;
	(void)argc;
	
	if (verif(argv) == -1)
		return (ft_printf("Error\n"));
	numbers = join_numbers(argv);
	if (numbers == NULL)
		return (ft_printf("Error\n"), 0);
	if (error_overflow(numbers) == -1)
		return (ft_printf("Error\n"),free(numbers), numbers = NULL, 0);
	array = stacks_a(numbers);
	if (check_duplicate(array) == -1)
		return (ft_printf("Error"), free(numbers), free(array.array_a), numbers = NULL, array.array_a = NULL, 0);
	x = 0;
	stack_a= malloc(sizeof(*link));
	if (!stack_a)
		return (0);
	stack_a= linked_list_initialise(array);
	sb_instruct(&stack_a);
	while (stack_a!= NULL)
	{
		ft_printf("%d\n",stack_a->value);
		stack_a = stack_a->next;
	}
	free (array.array_a);
	free (numbers);
	return (0);
}