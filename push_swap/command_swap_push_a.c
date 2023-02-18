/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 17:04:14 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_instruct(t_stacklist *lst)
{
	t_stacklist	*new;
	int	buf;
	
	if (lst->next == NULL || !(lst->value))
		return ;
	new = lst;
	buf = lst->value;
	lst = lst->next;
	new->value = lst->value; 
	lst->value = buf;
}

void	ra_instruct(t_stacklist **lst)
{
	t_stacklist	*buf;
	t_stacklist	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = buf;
	*lst = (*lst)->next;
	buf->next = NULL;
}

void	rra_instruct(t_stacklist **lst)
{
	t_stacklist	*buf;
	t_stacklist	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	while((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = buf;
	tmp->next = NULL;
}

void	pa_instruct(t_stacklist **lst_a, t_stacklist **lst_b)
{
	if (!(*lst_b))
		return ;
	ft_lst_add_front(lst_a, (*lst_b));
	(*lst_b) = (*lst_b)->pos_b;
}
