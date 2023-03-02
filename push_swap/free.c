/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:52:39 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/02 14:25:23 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(s_stack **lst_a)
{
	s_stack	*s1;
	s_stack *s2;

	s1 = *lst_a;
	s2 = *lst_a;
	while (s2 != NULL)
	{
		s2 = s2->next;
		free(s1);
		s1 = s2;
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
