/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:28:10 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 16:47:17 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	(*lst_a)->print = 1;
	(*lst_b)->print = 1;
	sa_instruct(lst_a);
	sb_instruct(lst_b);
	ft_printf("ss\n");
	(*lst_a)->print = 0;
	(*lst_b)->print = 0;
}

void	rr_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	(*lst_a)->print = 1;
	(*lst_b)->print = 1;
	rb_instruct(lst_b);
	ra_instruct(lst_a);
	ft_printf("rr\n");
	(*lst_a)->print = 0;
	(*lst_b)->print = 0;
}

void	rrr_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	(*lst_a)->print = 1;
	(*lst_b)->print = 1;
	rrb_instruct(lst_b);
	rra_instruct(lst_a);
	ft_printf("rrr\n");
	(*lst_a)->print = 0;
	(*lst_b)->print = 0;
}

t_stacks	*init_print(t_stacks **stack_a)
{
	t_stacks	*buf;

	buf = (*stack_a);
	while ((*stack_a) != NULL)
	{
		(*stack_a)->print = 0;
		(*stack_a) = (*stack_a)->next;
	}
	return (buf);
}
