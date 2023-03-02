/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/02 16:02:25 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

t_a_b_list	stacks_a(char *numbers)
{
	char		**buf;
	int			*array;
	int			x;
	t_a_b_list	a_list_and_count;

	x = 0;
	buf = ft_split(numbers, ' ');
	(a_list_and_count).count = count_numbers(buf);
	array = malloc(sizeof(int) * (a_list_and_count.count));
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	(a_list_and_count).array_a = array;
	ft_free_buf(buf);
	return (a_list_and_count);
}

int	main(int argc, char **argv)
{
	s_stack	*stack_a;
	s_stack	*stack_b;


	(void)argc;
	stack_a = error_check_and_initialize(argv);
	if (stack_a == NULL)
		return (0);
	stack_b = NULL;
	organize_index(stack_a);
	if (stack_a->count < 5)
		sorting_small_stack(&stack_a);
	else
		sorting_stack(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		ft_printf("%d stack_a\n", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_free_all(&stack_a);
	return (0);
}
