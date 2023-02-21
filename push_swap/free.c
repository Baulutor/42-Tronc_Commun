/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:52:39 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/21 17:26:58 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(s_stack **lst_a, s_stack **lst_b)
{
	while ((*lst_a) != NULL)
	{
		free((*lst_a));
		(*lst_a) = (*lst_a)->next;
	}
	while (*lst_b != NULL)
	{
		free(*lst_b);
		*lst_b = (*lst_b)->next;
	}
}

void	ft_free_buf(char **buf)
{
	int	x;

	x = 0;
	while (buf[x])
	{
		free(buf[x]);
		x++;
	}
	free(buf);
}
