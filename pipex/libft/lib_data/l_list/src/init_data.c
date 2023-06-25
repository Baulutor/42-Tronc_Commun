/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:38:58 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 16:19:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_data	*init_data(void *d, t_type t, t_bool allow, t_data *cell)
{
	if (cell == 0)
		return (write(1, "Error : fct init_data : cell null\n", 34), 0);
	cell->allowed = allow;
	cell->type_data = t;
	cell->data = d;
	return (cell);
}
