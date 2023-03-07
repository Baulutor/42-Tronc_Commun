/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:41:58 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:19:27 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* take each element and allocate them space 
to exist in my linked list */

t_stacks	*ft_lst_new(int content)
{
	t_stacks	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->value = content;
	link->next = NULL;
	return (link);
}

//put me at the end of my linked list

t_stacks	*ft_lst_last(t_stacks *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// add an element in my linked list at the last position.

void	ft_lstadd(t_stacks **lst, t_stacks *new)
{
	t_stacks	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lst_last((*lst));
	last->next = new;
}

// add an element to the front of my list

void	ft_lst_add_front(t_stacks **lst, t_stacks *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* add each elements of the array of int into 
my linked list and put it in order, 
the first one element still the first in my stacks.
take the number of element that is in my list*/

t_stacks	*linked_list_initialise(t_a_b_list elem)
{
	t_stacks	*link;
	t_stacks	*buf;
	int			x;

	x = 0;
	link = NULL;
	while (x < elem.count)
	{
		buf = ft_lst_new(elem.array_a[x]);
		if (!buf)
			return (NULL);
		ft_lstadd(&link, buf);
		x++;
	}
	link->count = x;
	return (link);
}
