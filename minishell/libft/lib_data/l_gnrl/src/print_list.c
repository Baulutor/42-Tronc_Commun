/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:09:19 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/27 14:46:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

static void	print_format(t_cell *tmp, t_type type)
{
	if (type == CHAR)
		ft_printf("%c", *((char *)tmp->data_cell->data));
	else if (type == INT)
		ft_printf("%d", *((int *)tmp->data_cell->data));
	else if (type == STRING)
		ft_printf("%s", ((char *)tmp->data_cell->data));
}

void	print_list(t_list *lst)
{
	t_cell	*tmp;
	t_type	type;

	if (lst == 0)
		return ;
	tmp = lst->head;
	ft_printf("{");
	while (tmp != 0)
	{
		type = tmp->data_cell->type_data;
		print_format(tmp, type);
		if (tmp->next != 0)
			ft_printf(" ; ");
		tmp = tmp->next;
	}
	ft_printf("}\n");
}
