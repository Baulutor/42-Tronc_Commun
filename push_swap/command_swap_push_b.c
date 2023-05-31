/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:33 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/31 11:20:01 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	t_stacks	*elem;

	if (!(*lst_a))
		return ;
	elem = *lst_a;
	(*lst_a) = (*lst_a)->next;
	elem->next = NULL;
	ft_lst_add_front(lst_b, elem);
	ft_printf("pb\n");
}
