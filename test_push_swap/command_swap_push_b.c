/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:33 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/26 18:19:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_instruct(a_list **lst)
{
	a_list	*buf;
	a_list	*tmp;
	int		x;
	
	if (!((*lst)->value) || ((*lst)->next == NULL))
		return ;
	x = 0;
	buf = *lst;
	tmp = *lst;
	while(x++ < 2)
		tmp = tmp->next;
	*lst = (*lst)->next; 
	(*lst)->next = buf;
	buf->next = tmp;
}

void	pb_instruct(a_list **lst)
{
	
}