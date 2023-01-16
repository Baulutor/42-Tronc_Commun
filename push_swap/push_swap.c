/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/16 18:49:02 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split numbers into a array of int

int	*stacks_a(char *numbers)
{
	char	**buf;
	int		*array;
	int		x;
	int		count;

	x = 0;
	buf = ft_split(numbers, ' ');
	count = count_numbers(buf);
	array = malloc(sizeof(int *) * (count)); // mal malloc, 1 seule valeur ou 4 font begueiller
	while (buf[x])
	{
		array[x] = ft_atoi(buf[x]);
		x++;
	}
	return (array);
}

int main (int argc, char **argv)
{
	int		*array;
	char	*numbers;
	size_t	x;
	(void)argc;
	

	if (verif(argv) == -1)
		return (ft_printf("Error\n"));
	numbers = join_numbers(argv);
	if (error_overflow(numbers) == -1)
	{
		ft_printf("Error\n");
		return (free(numbers), numbers = NULL, 0);
	}
	array = stacks_a(numbers);
	check_duplicate(array); // recupere la valeur du nombre de numero dans le tab de int 
	x = 0;
	int max = 2;
	while (x < max)
	{
		ft_printf("%d\n",array[x]);
		x++;
	}
	return (0);
}