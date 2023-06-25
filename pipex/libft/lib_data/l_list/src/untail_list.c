/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untail_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:14:29 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 16:44:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_cell	*untail_list(t_list *lst, int debug)
{
	t_cell	*rm;

	if (lst == 0)
	{
		if (debug)
			write(1, "ERROR : fct untail_list : lst null\n", 35);
		return (0);
	}
	if (lst->type_lst != LIST || lst->len == 0)
	{
		if (debug == 1 && lst->type_lst != LIST)
			write(1, "ERROR : fct untail_list : Utilisation of fct list on non \
list data structure\n", 78);
		return (0);
	}
	rm = lst->tail;
	if (lst->len > 1)
		lst->tail = rm->prev;
	lst->tail->next = 0;
	if (lst->len == 1)
	{
		lst->head = 0;
		lst->tail = 0;
	}
	lst->len--;
	return (rm);
}
