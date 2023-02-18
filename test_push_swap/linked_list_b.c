#include "push_swap.h"

// take each element and allocate them space to exist in my linked list

t_stacklist	*ft_lst_new_b(int content)
{
	t_stacklist	*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->value = content;
	link->pos_b = NULL;
	return (link);
}

//put me at the end of my linked list

t_stacklist	*ft_lst_last_b(t_stacklist *lst)
{
	while (lst != NULL && lst->pos_b != NULL) 
		lst = lst->pos_b;
	return (lst);
}

// add an element in my linked list.

void	ft_lstadd_b(t_stacklist **lst, t_stacklist *new)
{
	t_stacklist	*last;

	if (!(*lst))
	{
		(*lst) = ft_lst_new_b(new->value);
		return ;
	}
	last = ft_lst_last_b((*lst));
	last->pos_b = ft_lst_new_b(new->value);
//	ft_printf("%d last gang\n\n", last->value);
}

void	ft_lst_add_front_b(t_stacklist **lst, t_stacklist *new)
{
	t_stacklist	*buf;

	if (!*lst)
	{
		*lst = ft_lst_new_b(new->value);
		return ;
	}
	buf = ft_lst_new_b(new->value);
	buf->pos_b = *lst;
	*lst = buf;
}