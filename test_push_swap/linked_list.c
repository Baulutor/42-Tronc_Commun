
#include "push_swap.h"

// take each element and allocate them space to exist in my linked list

a_list	*ft_lst_new(int content)
{
	a_list	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (0);
	link->value = content;
	link->next = 0;
	return (link);
}

//put me at the end of my linked list

a_list	*ft_lst_last(a_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

// add an element in my linked list.

void	ft_lstadd(a_list **lst, a_list *new)
{
	a_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lst_last(*lst);
	last->next = new;
}

void	ft_lst_add_front(a_list **lst, a_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/* add each elements of the array of int into my linked list and put it in order, 
the first one element still the first in my stacks.
take the number of element that is in my list*/

a_list	*linked_list_initialise(a_b_list elem)
{
	a_list	*link;
	int		x;
	
	x = 0;
	while (x < elem.count)
	{
		ft_lstadd(&link, ft_lst_new(elem.array_a[x]));
		x++;
	}
	link->count_a = x;
	return (link);
}