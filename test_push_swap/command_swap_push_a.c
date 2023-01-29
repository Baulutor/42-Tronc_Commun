/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/26 18:36:02 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_instruct(a_list *lst, a_list *new)
{
	int	buf;
	
	buf = lst->value;
	lst = lst->next;
	new->value = lst->value; 
	lst->value = buf;
}

void	ss_instruct(a_list *array)
{
	sa_instruct(array, array);
	sb_instruct(&array);
}

void	pa_instruct(a_list **lst_a, a_list **lst_b)
{
	
}

void	ra_instruct(a_list **lst)
{
	a_list	*buf;
	a_list	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = buf;
	*lst = (*lst)->next;
	buf->next = NULL;
}

void	rra_instruct(a_list **lst)
{
	a_list	*buf;
	a_list	*tmp;

	buf = *lst;
	tmp = *lst;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	while((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = buf;
	tmp->next = NULL;
}