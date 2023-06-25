/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:15:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/13 18:34:09 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	clear_cell(t_list *lst, t_cell *cell, void (*f)(void *))
{
	if (lst == 0 || cell == 0 || f == 0)
	{
		ft_printf("ERROR : fct clear_cell : One or more arguments are null");
		return ;
	}
	if (lst->head == cell)
		lst->head = cell->next;
	if (lst->tail == cell)
		lst->tail = cell->prev;
	if (cell->next != 0)
		cell->next->prev = cell->prev;
	if (cell->prev != 0)
		cell->prev->next = cell->next;
	f(cell->data_cell->data);
	free(cell->data_cell);
	free(cell);
}
