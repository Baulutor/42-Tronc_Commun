/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:28:10 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:15:28 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	sa_instruct(lst_a);
	sb_instruct(lst_b);
	ft_printf("ss\n");
}

void	rr_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	rb_instruct(lst_b);
	ra_instruct(lst_a);
	ft_printf("rr\n");
}

void	rrr_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	rrb_instruct(lst_b);
	rra_instruct(lst_a);
	ft_printf("rrr\n");
}
