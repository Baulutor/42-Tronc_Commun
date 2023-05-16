/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 15:47:00 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;
	int			print;
	int			x;

	if (!((*lst)->value) || ((*lst)->next == NULL))
		return ;
	x = 0;
	print = (*lst)->print;
	buf = *lst;
	tmp = *lst;
	while (x++ < 2)
		tmp = tmp->next;
	*lst = (*lst)->next;
	(*lst)->next = buf;
	buf->next = tmp;
	if (print != 1)
		ft_printf("sa\n");
}

void	ra_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;
	int			print;

	print = (*lst)->print;
	buf = *lst;
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = buf;
	*lst = (*lst)->next;
	buf->next = NULL;
	if (print != 1)
		ft_printf("ra\n");
}

void	rra_instruct(t_stacks **lst)
{
	t_stacks	*buf;
	t_stacks	*tmp;
	int			print;

	buf = *lst;
	tmp = *lst;
	print = (*lst)->print;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = buf;
	tmp->next = NULL;
	if (print != 1)
		ft_printf("rra\n");
}

void	pa_instruct(t_stacks **lst_a, t_stacks **lst_b)
{
	t_stacks	*elem;

	if (!(*lst_b))
		return ;
	elem = *lst_b;
	*lst_b = (*lst_b)->next;
	elem->next = NULL;
	ft_lst_add_front(lst_a, elem);
	ft_printf("pa\n");
}
