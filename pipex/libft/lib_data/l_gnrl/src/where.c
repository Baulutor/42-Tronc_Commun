/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:06:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/22 20:29:13 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

t_cell	*where(t_list *lst, t_type t, void *d, size_t n)
{
	t_cell	*tmp;
	size_t	len;
	void	*data;
	size_t	comp;

	tmp = lst->head;
	while (tmp != 0)
	{
		comp = 0;
		if (tmp->data_cell->type_data == t)
		{
			len = 0;
			while (len < n)
			{
				data = tmp->data_cell->data;
				if (((unsigned char *)data)[len] == ((unsigned char *)d)[len])
					comp++;
				len++;
			}
		}
		if (comp == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}
