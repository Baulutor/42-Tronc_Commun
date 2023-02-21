/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:14:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/19 15:53:54 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// how many number have to be malloc

int	count_numbers(char **buf)
{
	size_t	x;

	x = 0;
	while (buf[x])
		x++;
	return (x);
}

// put all the numbers in the stack A

char	*join_numbers(char **argv)
{
	char	*numbers;
	int		y;

	y = 1;
	if (!argv[2])
	{
		numbers = ft_strdup(argv[y]);
		if (!numbers)
			return (NULL);
		return (numbers);
	}
	numbers = ft_strdup(argv[y]);
	y++;
	while (argv[y])
	{
		numbers = ft_strjoin(numbers, argv[y]);
		if (!numbers)
			return (NULL);
		y++;
	}
	return (numbers);
}
