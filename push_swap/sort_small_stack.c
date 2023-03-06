/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/04 19:58:33 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two_numbers(s_stack **lst_a)
{
	s_stack	*buf;

	buf = *lst_a;
	buf = buf->next;
	if ((*lst_a)->value > buf->value)
		sa_instruct(lst_a);
	else
		return ;	
}

void	sorting_three_numbers(s_stack **stack_a, int first, int second, int third)
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
	else if (first > third && first > second && second < third)
		ra_instruct(stack_a);
	else if (second > first && second > third && first < third)
	{
		sa_instruct(stack_a);
		ra_instruct(stack_a);
	}
}

void	sorting_three_numbers_initialise(s_stack **stack_a)
{
	int	first;
	int	second;
	int	third;
	s_stack	*tmp;

	tmp = *stack_a;
	first = tmp->index;
	tmp = tmp->next;
	second = tmp->index;
	tmp = tmp->next;
	third = tmp->index;
	sorting_three_numbers(stack_a, first, second, third);
}

void	sorting_four_numbers_command(s_stack **stack_a, s_stack **stack_b, int x)
{
	if (x == 0)
		pb_instruct(stack_a, stack_b);
	else if (x == 1)
	{
		sa_instruct(stack_a);
		pb_instruct(stack_a, stack_b);
	}
	else if (x == 2)
	{
		ra_instruct(stack_a);
		sa_instruct(stack_a);
		pb_instruct(stack_a, stack_b);
	}
	else if (x == 3)
	{
		rra_instruct(stack_a);
		pb_instruct(stack_a, stack_b);
	}
}

void	sorting_four_numbers(s_stack **stack_a, s_stack **stack_b)
{
	s_stack	*buf;
	int		x;

	buf = (*stack_a);
	x = 0;
	while (buf->index != 1)
	{
		buf = buf->next;
		x++;
	}
	sorting_four_numbers_command(stack_a, stack_b, x);
	sorting_three_numbers_initialise(stack_a);
	while ((*stack_b) != NULL)
		pa_instruct(stack_a, stack_b);
}

void	sorting_five_numbers(s_stack **stack_a, s_stack **stack_b)
{
	int	x;
	int	y;
	s_stack	*buf;

	x = 0;
	y = 0;
	buf = *stack_a;
	while (buf->index != 2)
	{
		buf = buf->next;
		x++;
	}
	while (y < x)
	{
		ra_instruct(stack_a);
		y++;
	}
	pb_instruct(stack_a, stack_b);
	sorting_four_numbers(stack_a, stack_b);
	sa_instruct(stack_a);
	
}

void	sorting_small_stack(s_stack **stack_a, s_stack **stack_b)
{
	if ((*stack_a)->count == 1)
		return ;
	else if ((*stack_a)->count == 2)
		sorting_two_numbers(stack_a);
	else if ((*stack_a)->count == 3)
		sorting_three_numbers_initialise(stack_a);
	else if ((*stack_a)->count == 4)
		sorting_four_numbers(stack_a, stack_b);
	else
		sorting_five_numbers(stack_a, stack_b);
}
