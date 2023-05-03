/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:49:56 by dbaule            #+#    #+#             */
/*   Updated: 2023/03/07 17:54:40 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if the argument is only numbers or operator '+' and '-',
that is correctly write. While we are in the argument (argv), 
space is for now accepted.*/

int	int_condition(char **argv, int x, int y)
{
	if (((argv[x][y] > '9' || argv[x][y] < '0') && argv[x][y] != ' ' &&
		argv[x][y] != '-' && argv[x][y] != '+')
		|| ((argv[x][y] == '-' || argv[x][y] == '+') &&
		(argv[x][y + 1] > '9' || argv[x][y + 1] < '0'))
		|| ((argv[x][y] == '-' || argv[x][y] == '+') &&
		(argv[x][y - 1] <= '9' && argv[x][y - 1] >= '0')))
		return (-1);
	return (0);
}

int	atoi_test(size_t y, size_t index, char *numbers)
{
	int	buf;

	if (y > 8)
	{
		buf = ft_atoi(numbers + index);
		if (buf == 0 || buf == -1)
			return (-1);
	}
	return (0);
}
