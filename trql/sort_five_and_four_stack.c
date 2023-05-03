/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_and_four_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:49:11 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:19:17 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_numbers_command(t_stacks **stack_a, t_stacks **stack_b, int x)
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

void	sorting_four_numbers(t_stacks **stack_a, t_stacks **stack_b, int z)
{
	t_stacks	*buf;
	int			x;

	buf = (*stack_a);
	x = 0;
	while (buf->index != 1 && z == 0)
	{
		buf = buf->next;
		x++;
	}
	while (buf->index != 2 && z == 1)
	{
		buf = buf->next;
		x++;
	}
	four_numbers_command(stack_a, stack_b, x);
	sorting_three_numbers_initialise(stack_a);
	while ((*stack_b) != NULL)
		pa_instruct(stack_a, stack_b);
}

void	sorting_five_numbers(t_stacks **stack_a, t_stacks **stack_b)
{
	int			x;
	int			y;
	int			z;
	t_stacks	*buf;

	x = 0;
	y = 0;
	z = 0;
	buf = *stack_a;
	while (buf->index != 2)
	{
		if (buf->index == 1 && z++ == 0)
			break ;
		buf = buf->next;
		x++;
	}
	while (y < x)
	{
		ra_instruct(stack_a);
		y++;
	}
	pb_instruct(stack_a, stack_b);
	sorting_four_numbers(stack_a, stack_b, z);
	if (z == 0)
		sa_instruct(stack_a);
}
