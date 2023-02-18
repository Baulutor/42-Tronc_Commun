/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:33 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 16:29:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_instruct(t_stacklist **lst)
{
	t_stacklist	*buf;
	t_stacklist	*tmp;
	int		x;
	
	if (!((*lst)->value) || ((*lst)->pos_b == NULL))
		return ;
	x = 0;
	buf = *lst;
	tmp = *lst;
	while(x++ < 2)
		tmp = tmp->pos_b;
	*lst = (*lst)->pos_b; 
	(*lst)->pos_b = buf;
	buf->pos_b = tmp;
}

void	pb_instruct(t_stacklist **lst_a, t_stacklist **lst_b)
{
	if (!(*lst_a))
		return ;
	ft_lst_add_front_b(lst_b, (*lst_a));
	(*lst_a) = (*lst_a)->next;
}

void	rb_instruct(t_stacklist **lst)
{
	t_stacklist	*buf;
	t_stacklist	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->pos_b != NULL)
		tmp = tmp->pos_b;
	tmp->pos_b = buf;
	*lst = (*lst)->pos_b;
	buf->pos_b = NULL;
}

void	rrb_instruct(t_stacklist **lst)
{
	t_stacklist	*buf;
	t_stacklist	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->pos_b->pos_b != NULL)
		tmp = tmp->pos_b;
	while((*lst)->pos_b != NULL)
		*lst = (*lst)->pos_b;
	(*lst)->pos_b = buf;
	tmp->pos_b = NULL;
}