/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/03 17:13:55 by dbaule           ###   ########.fr       */
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
	else if (second == (first + third)  && first < third)
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

void	sorting_small_stack(s_stack **stack_a)
{
	if ((*stack_a)->count == 1)
		return ;
	else if ((*stack_a)->count == 2)
		sorting_two_numbers(stack_a);
	else if ((*stack_a)->count == 3)
		sorting_three_numbers_initialise(stack_a);
}
