/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:14:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/23 17:16:23 by dbaule           ###   ########.fr       */
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

int		binary_test(s_stack *stack, int x, int end)
{
	int	i;

	i = 0;
	while (i <= end)
	{
		if (((stack->index >> x)&1) == 1)
			return(0);
		i++;
	}
	return (1);
}

// void	make_instruct(s_stack *stack_a, s_stack *stack_b, int x)
// {

// }

s_stack	*sorting_stack(s_stack *stack_a, s_stack *stack_b)
{
	int	i;
	int	x;
	int	j;
	int count;
	s_stack	*buf;

	i = 0;
	x = 1;
	j = 0;
	buf = stack_a;
	count = stack_a->count;
	while (j < 11)
	{
		if (binary_test(buf, x, count) == 0)
		{
			while (i <= count)
			{
				if (((stack_a->index >> x)&1) == 1)
					ra_instruct(&stack_a);
				else
					pb_instruct(&stack_a, &stack_b);
				i++;
			}
		}
		while (stack_b != NULL)
			pa_instruct(&stack_a, &stack_b);
		i = 0;
		x++;
		j++;
	}
	return (stack_a);
}
