/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:28:10 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/21 17:22:01 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_instruct(s_stack **lst_a, s_stack **lst_b)
{
	sa_instruct(lst_a);
	sb_instruct(lst_b);
	ft_printf("ss\n");
}

void	rr_instruct(s_stack **lst_a, s_stack **lst_b)
{
	rb_instruct(lst_b);
	ra_instruct(lst_a);
	ft_printf("rr\n");
}

void	rrr_instruct(s_stack **lst_a, s_stack **lst_b)
{
	rrb_instruct(lst_b);
	rra_instruct(lst_a);
	ft_printf("rrr\n");
}
