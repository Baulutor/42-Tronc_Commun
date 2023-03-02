/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:14:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/02 14:52:29 by dbaule           ###   ########.fr       */
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

void	sorting_stack(s_stack **lst_a, s_stack **lst_b)
{
	int x;
	int	y;
	int	z;
	s_stack	*tmp;

	x = 0;
	y = 0;
	z = 0;
	tmp = *lst_a;
	while (((*lst_a)->count + 1) >> y != 0)
		y++;
	while (y > x)
	{
		z = 0;
		
		while(z < (tmp->count))
		{
			if (((*lst_a)->index >> x &1) == 0)
				pb_instruct(lst_a, lst_b);
			else
				ra_instruct(lst_a);
			z++;
		}
		while ((*lst_b) != NULL)
			pa_instruct(lst_a, lst_b);
		x++;
	}
}
