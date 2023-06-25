/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmstack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:53:14 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 16:47:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_stack.h"

void	rmstack(t_list *lst, t_bool allow, int debug)
{
	t_cell	*u_data;

	if (lst == 0)
	{
		if (debug)
			write(1, "Error : fct rmstack : lst null\n", 31);
		return ;
	}
	if (lst->type_lst == STACK && lst->len != 0)
	{
		u_data = unstack(lst, debug);
		if (u_data->data_cell->allowed == TRUE || allow == TRUE)
			free(u_data->data_cell->data);
		free(u_data->data_cell);
		free(u_data);
	}
	else
		if (debug == 1 && lst->type_lst != STACK)
			write(1, "ERROR : fct rmstack : Utilisation of fct stack on non \
stack data structure\n", 76);
}
