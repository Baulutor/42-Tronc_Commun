/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmindex_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:29:43 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 15:08:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

static int	handle_debug(t_list *lst, int index, int debug);

void	rmindex_list(t_list *lst, t_bool allow, int index, int debug)
{
	int		i;
	t_cell	*tmp;
	t_cell	*sup;

	if (handle_debug(lst, index, debug) == 1)
		return ;
	i = lst->len;
	if (index == 0)
		rmstack_list(lst, allow, debug);
	else if (index == i - 1)
		rmtail_list(lst, allow, debug);
	if (index == 0 || index == i - 1)
		return ;
	i = 0;
	while (i++ < index - 1)
		tmp = tmp->next;
	sup = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;
	if (allow == TRUE)
		free(sup->data_cell->data);
	free(sup->data_cell);
	free(sup);
	lst->len -= 1;
}

static int	handle_debug(t_list *lst, int index, int debug)
{
	if (debug == 1)
	{
		if (lst == NULL)
			return (write(2, "ERROR : fct rmindex_list : lst null\n", 36), 1);
		if (lst->type_lst != LIST)
			return (write(2, "ERROR : fct rmindex_list : Utilisation of fct \
list on non list data structure\n", 79), 1);
		if (index < 0 || (size_t) index >= lst->len)
			return (write(2, "ERROR : fct rmindex_list : index not \
good\n", 42), 1);
	}
	return (0);
}
