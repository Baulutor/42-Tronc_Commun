/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:14:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/23 17:40:29 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialise_index(s_stack *stack)
{
	s_stack *buf;

	buf = stack;
	while (buf != NULL)
	{
		buf->index = 0;
		buf = buf->next;
	}
}

static int	sort_order(s_stack *stack, int buf)
{
	int pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->value > buf)
			pos++;
		stack = stack->next;
	}
	return (pos);
}

// put an index on numbers to determinate where they should be 

void	organize_index(s_stack *stack)
{
	int buf;
	int count;
	int pos;
	s_stack	*tmp;

	tmp = stack;
	count = stack->count;
	initialise_index(stack);
	while (stack != NULL)
	{
		buf = stack->value;
		pos = sort_order(tmp, buf);
		stack->index = count - pos;
		stack = stack->next;
	}
}

// int		count_max_binary(int count)
// {
// }

// s_stack	*sorting_stack(s_stack *stack_a, s_stack *stack_b)
// {
// 	int	count;
	
// 	count = count_max_binary(stack_a->count);
	
// 	return (stack_a);
// }
