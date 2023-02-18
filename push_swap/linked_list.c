
#include "push_swap.h"

// take each element and allocate them space to exist in my linked list

t_stacklist	*ft_lst_new(int content)
{
	t_stacklist	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (0);
	link->value = content;
	link->next = 0;
	return (link);
}

//put me at the end of my linked list

t_stacklist	*ft_lst_last(t_stacklist *lst)
{
	while (lst != NULL && lst->next != NULL) // crash ici apres avoir rentre dans la boucle 1 fois.
		lst = lst->next;
	return (lst);
}

// add an element in my linked list.

void	ft_lstadd(t_stacklist **lst, t_stacklist *new)
{
	t_stacklist	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lst_last((*lst));
	last->next = new;
}

void	ft_lst_add_front(t_stacklist **lst, t_stacklist *new)
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

t_stacklist	*linked_list_initialise(t_a_b_list elem)
{
	t_stacklist	*link;
	int		x;

	x = 0;
	link = NULL;
	while (x < elem.count)
	{
		ft_lstadd(&link, ft_lst_new(elem.array_a[x]));
		x++;
	}
	link->count_a = x;
	return (link);
}