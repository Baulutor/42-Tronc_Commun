/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:33 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:20:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;
	int			x;

	if (!((*lst)->value) || ((*lst)->next == NULL))
		return ;
	x = 0;
	buf = *lst;
	tmp = *lst;
	while (x++ < 2)
		tmp = tmp->next;
	*lst = (*lst)->next;
	(*lst)->next = buf;
	buf->next = tmp;
	ft_printf("sb\n");
}

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

void	rb_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;

	if (!((*lst)->value) || (*lst)->next == NULL)
		return ;
	buf = *lst;
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = buf;
	*lst = (*lst)->next;
	buf->next = NULL;
	ft_printf("rb\n");
}

void	rrb_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;

	if (!((*lst)->value) || (*lst)->next == NULL)
		return ;
	buf = *lst;
	tmp = *lst;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = buf;
	tmp->next = NULL;
	ft_printf("rrb\n");
}
