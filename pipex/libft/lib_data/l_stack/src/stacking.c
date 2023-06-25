/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 18:34:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

static void	debuger_stacking(int debug, int mod, t_list *lst)
{
	if (debug == 1)
	{
		if (lst == 0)
			write(1, "ERROR : fct stacking : lst null\n", 32);
		if (mod == 1)
			write(1, "ERROR : fct stacking : Malloc not OK\n", 37);
		else if (mod == 0)
			write(1, "ERROR : fct stacking : Utilisation of fct list on \
non list data structure\n", 75);
	}
}

static void	init_cell(t_cell *cell, t_data *d_cell)
{
	cell->data_cell = d_cell;
	cell->next = 0;
	cell->prev = 0;
}

static void	secur_alloc(t_data *data_cell, t_cell *cell)
{
	if (data_cell != 0)
		free(data_cell);
	if (cell != 0)
		free(cell);
}

int	stacking(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;

	if ((lst == 0 || lst->type_lst != STACK) && debug == 1)
		debuger_stacking(debug, 0, lst);
	if (lst == 0 || lst->type_lst != STACK)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	if (debug == 1 && (d_cell == 0 || cell == 0))
		debuger_stacking(debug, 1, lst);
	if (d_cell == 0 || cell == 0)
		return (secur_alloc(d_cell, cell), 0);
	init_data(data, t, FALSE, d_cell);
	init_cell(cell, d_cell);
	if (lst->len == 0)
		lst->tail = cell;
	else
	{
		lst->head->prev = cell;
		cell->next = lst->head;
	}
	lst->len++;
	lst->head = cell;
	return (1);
}
