/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/19 13:36:21 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_instruct(a_b_list array)
{
	int	*buf;
	
	if (!array.array_a[0] || !array.array_a[1])
		return ;
	buf[0] = array.array_a[0];
	array.array_a[0] = array.array_a[1];
	array.array_a[1] = buf[0];
}

void	sb_instruct(a_b_list array)
{
	int	*buf;
	
	if (!array.array_a[0] || !array.array_a[1])
		return ;
	buf[0] = array.array_b[0];
	array.array_b[0] = array.array_b[1];
	array.array_b[1] = buf[0];
}

void	ss_instruct(a_b_list array)
{
	sa_instruct(array);
	sb_instruct(array);
}

void	pa_instruct(a_b_list array)
{
	if (!array.array_b[0])
		return ;
	
}