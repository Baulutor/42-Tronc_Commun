/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:28:10 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 16:56:15 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_instruct(t_stacklist *array)
{
	sa_instruct(array);
	sb_instruct(&array);
}

void	rr_instruct(t_stacklist **lst_a, t_stacklist **lst_b)
{
	rb_instruct(lst_b);
	ra_instruct(lst_a);
}

void	rrr_instruct(t_stacklist **lst_a, t_stacklist **lst_b)
{
	rrb_instruct(lst_b);
	rra_instruct(lst_a);
}