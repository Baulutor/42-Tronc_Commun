/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/31 11:12:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_two_numbers(t_stacks **lst_a)
{
	t_stacks	*buf;

	buf = *lst_a;
	buf = buf->next;
	if ((*lst_a)->value > buf->value)
		sa_instruct(lst_a);
	else
		return ;
}

// operation needed to do for sorting 3 numbers of a stack

static void	command_sort(t_stacks **stack_a, int first, int second, int third)
{
	if (third < second && third < first && second > first)
		rra_instruct(stack_a);
	else if (first > second && first < third)
		sa_instruct(stack_a);
	else if (second > third && second < first)
	{
		sa_instruct(stack_a);
		rra_instruct(stack_a);
	}
	else if (first < third && first < second && second > third)
	{
		sa_instruct(stack_a);
		ra_instruct(stack_a);
	}
	else if (first > third && first > second && second < third)
		ra_instruct(stack_a);
	else if (second > first && second > third && first < third)
	{
		sa_instruct(stack_a);
		ra_instruct(stack_a);
	}
}

void	sorting_three_numbers_initialise(t_stacks **stack_a)
{
	int			first;
	int			second;
	int			third;
	t_stacks	*tmp;

	tmp = *stack_a;
	first = tmp->index;
	tmp = tmp->next;
	second = tmp->index;
	tmp = tmp->next;
	third = tmp->index;
	command_sort(stack_a, first, second, third);
}

// the hub of stack between 1 and 5

void	sorting_small_stack(t_stacks **stack_a, t_stacks **stack_b)
{
	int	z;

	z = 0;
	if ((*stack_a)->count == 1)
		return ;
	else if ((*stack_a)->count == 2)
		sorting_two_numbers(stack_a);
	else if ((*stack_a)->count == 3)
		sorting_three_numbers_initialise(stack_a);
	else if ((*stack_a)->count == 4)
		sorting_four_numbers(stack_a, stack_b, z);
	else
		sorting_five_numbers(stack_a, stack_b);
}
