/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:40:40 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/14 18:11:33 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

t_data	*init_data(void *d, t_type t, t_bool allow, t_data *cell)
{
	if (cell == 0)
		return (ft_printf("Error : fct init_data : cell null\n"), NULL);
	cell->allowed = allow;
	cell->type_data = t;
	cell->data = d;
	return (cell);
}
