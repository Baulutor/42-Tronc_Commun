/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 16:45:25 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

t_a_b_list	stacks_a(char *numbers)
{
	char		**buf;
	int			*array;
	int			x;
	t_a_b_list	a_listnd_count;

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
	t_stacklist	*stack;
	t_stacklist *stack_b;
	(void)argc;
	
	stack = error_check_and_initialize(argv);
	if (stack == NULL)
		return (0);
	stack_b = NULL;
	while (stack != NULL)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
	while (stack_b != NULL)
	{
		ft_printf("%d stack B\n", stack_b->value);
		stack_b = stack_b->pos_b;
	}
	return (0);
}