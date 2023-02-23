/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:41:58 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/23 14:28:48 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* take each element and allocate them space 
to exist in my linked list */

s_stack	*ft_lst_new(int content)
{
	s_stack	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (0);
	link->value = content;
	link->next = 0;
	return (link);
}

//put me at the end of my linked list

s_stack	*ft_lst_last(s_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// add an element in my linked list.

void	ft_lstadd(s_stack **lst, s_stack *new)
{
	s_stack	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lst_last((*lst));
	last->next = new;
}

void	ft_lst_add_front(s_stack **lst, s_stack *new)
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

s_stack	*linked_list_initialise(t_a_b_list elem)
{
	s_stack	*link;
	int			x;

	x = 0;
	link = NULL;
	while (x < elem.count)
	{
		ft_lstadd(&link, ft_lst_new(elem.array_a[x]));
		x++;
	}
	link->count = x;
	return (link);
}
