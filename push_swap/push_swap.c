/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/11 18:16:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(t_stacks *lst)
{
	int	buf;

	buf = 0;
	while (lst)
	{
		if (buf > lst->index)
			return (0);
		buf = lst->index;
		lst = lst->next;
	}
	return (-1);
}

// split numbers into a array of int

t_a_b_list	stacks_a(char *numbers)
{
	char		**buf;
	int			*array;
	int			x;
	t_a_b_list	a_list_and_count;

	x = 0;
	buf = ft_split(numbers, ' ');
	(a_list_and_count).count = count_numbers(buf);
	array = malloc(sizeof(int) * (a_list_and_count.count));
	if (!array)
	{
		a_list_and_count.array_a = NULL;
		return (a_list_and_count);
	}
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	(a_list_and_count).array_a = array;
	ft_free_buf(buf);
	return (a_list_and_count);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	(void)argc;
	if (!argv[1])
		return (0);
	stack_a = error_check_and_initialize(argv);
	if (stack_a == NULL)
		return (-1);
	stack_b = NULL;
	organize_index(stack_a);
	if (check_list(stack_a) == -1)
		return (ft_free_all(&stack_a), -1);
	if (stack_a->count < 6)
		sorting_small_stack(&stack_a, &stack_b);
	else
		sorting_stack(&stack_a, &stack_b);
	ft_free_all(&stack_a);
	return (0);
}
