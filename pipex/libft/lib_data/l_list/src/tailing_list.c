/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tailing_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:54:05 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/25 17:04:05 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

static void	debuger(int debug, int mod, t_list *lst)
{
	if (debug == 1)
	{
		if (lst == 0)
			write(1, "ERROR : fct tailing_list : lst null\n", 36);
		if (mod == 11)
			write(1, "ERROR : fct tailing_list : Malloc not OK\n", 41);
		else if (mod == 0)
			write(1, "ERROR : fct tailing_list : Utilisation of fct list on \
non stack data structure\n", 80);
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

int	tailing_list(t_list *lst, void *data, t_type t, int debug)
{
	t_data	*d_cell;
	t_cell	*cell;

	if ((lst == 0 || lst->type_lst != LIST) && debug == 1)
		debuger(debug, 0, lst);
	if (lst == 0 || lst->type_lst != LIST)
		return (0);
	d_cell = (t_data *) malloc(sizeof(t_data));
	cell = (t_cell *) malloc(sizeof(t_cell));
	if (debug == 1 && (d_cell == 0 || cell == 0))
		debuger(debug, 1, lst);
	if (d_cell == 0 || cell == 0)
		return (secur_alloc(d_cell, cell), 0);
	init_data(data, t, FALSE, d_cell);
	init_cell(cell, d_cell);
	if (lst->len > 0)
	{
		cell->prev = lst->tail;
		lst->tail->next = cell;
	}
	lst->tail = cell;
	if (lst->len == 0)
		lst->head = cell;
	lst->len++;
	return (1);
}
