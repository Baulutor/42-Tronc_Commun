/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:49:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/02 16:07:17 by dbaule           ###   ########.fr       */
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

void	sorting_three_numbers(s_stack **stack_a)
{
	s_stack	*s1;
	s_stack	*s2;

	s1 = *stack_a;
	s2 = *stack_a;
	while(s1->next != NULL)
		s1 = s1->next;
	s2 = s2->next;
	// if (s1->value > s2->value && s1->value > (*stack_a)->value && (*stack_a)->value < s2->value)
	// 	return ;
	if (s1->value < s2->value && s1->value < (*stack_a)->value && s2->value > (*stack_a)->value)
		rra_instruct(stack_a);
	else if ((*stack_a)->value > s2->value && (*stack_a)->value < s1->value)
		sa_instruct(stack_a);
	else if (s2->value > s1->value && s2->value < (*stack_a)->value)
	{
		sa_instruct(stack_a);
		rra_instruct(stack_a);
	}
	else if ((*stack_a)->value > s1->value && (*stack_a)->value)
}

void	sorting_small_stack(s_stack **stack_a)
{
	if ((*stack_a)->count == 1)
		return ;
	else if ((*stack_a)->count == 2)
		sorting_two_numbers(stack_a);
	else if ((*stack_a)->count == 3)
		sorting_three_numbers(stack_a);
}
