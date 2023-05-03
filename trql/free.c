/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:52:39 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:14:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//freeing the linked list when I finished used the linked list

void	ft_free_all(t_stacks **lst_a)
{
	t_stacks	*s1;
	t_stacks	*s2;

	s1 = *lst_a;
	while (s1 != NULL)
	{
		s2 = s1;
		s1 = s1->next;
		free(s2);
	}
	*lst_a = 0;
}

// freeing the double array use to be in the linked list

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
