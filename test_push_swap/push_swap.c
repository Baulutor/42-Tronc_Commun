/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/25 15:54:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

a_b_list	stacks_a(char *numbers)
{
	char		**buf;
	int			*array;
	int			x;
	a_b_list	a_listnd_count;

	x = 0;
	buf = ft_split(numbers, ' ');
	(a_listnd_count).count = count_numbers(buf);
	array = malloc(sizeof(int) * (a_listnd_count.count));
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	(a_listnd_count).array_a = array;
	return (a_listnd_count);
}

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

int main (int argc, char **argv)
{
	a_b_list	array;
	a_list		*link;
	char		*numbers;
	int			x;
	(void)argc;
	

	if (verif(argv) == -1)
		return (ft_printf("Error\n"));
	numbers = join_numbers(argv);
	if (numbers == NULL)
		return (ft_printf("Error\n"), 0);
	if (error_overflow(numbers) == -1)
	{
		ft_printf("Error\n");
		return (free(numbers), numbers = NULL, 0);
	}
	array = stacks_a(numbers);
	if (check_duplicate(array) == -1)
		return (ft_printf("Error"), free(numbers), free(array.array_a), numbers = NULL, array.array_a = NULL, 0);
	x = 0;
	link = malloc(sizeof(*link));
	if (!link)
		return (0);
	link = linked_list_initialise(array);
	// while (link != NULL)
	// {
	// 	ft_printf("%d\n",link->value);
	// 	link = link->next;
	// }
	free (array.array_a);
	free (numbers);
	return (0);
}