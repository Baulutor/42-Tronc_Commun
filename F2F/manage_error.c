/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:45:19 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/31 15:39:40 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FdF.h"

static int	verif_spacebar(char *str);
static int	int_condition(char *str);

int	verif(char *str)
{
	if (!str[1])
		return (0);
	if (verif_spacebar(str) == -1)
		return (-1);
	if (int_condition(str) == -1)
		return (-1);
	return (0);
}
static int	verif_spacebar(char *str)
{
	size_t	x;

	x = 0;
	if (str[x] == '\0')
		return (0);
	while ((str[x] == ' ' || (str[x] < '0' && str[x] > '9')) && str[x + 2])
	{
		x++;
		if (!str[x + 2])
			return (-1);
	}
	return (0);
}

static int	int_condition(char *str)
{
	int y;
	
	y = 0;
	while (str[y + 1])
	{
		if (((str[y] > '9' || str[y] < '0') && str[y] != ' ' &&
			str[y] != '-' && str[y] != '+')
			|| ((str[y] == '-' || str[y] == '+') &&
			(str[y + 1] > '9' || str[y + 1] < '0'))
			|| ((str[y] == '-' || str[y] == '+') &&
			(str[y - 1] <= '9' && str[y - 1] >= '0')))
			return (-1);
		y++;
	}
	// if (str[y + 1] != '\n' || str[y + 1] != '\0')
	// 	return(-1);
	return (0);
}


// static int	atoi_test(size_t y, size_t index, char *numbers)
// {
// 	int	buf;

// 	if (y > 8)
// 	{
// 		buf = ft_atoi(numbers + index);
// 		if (buf == 0 || buf == -1)
// 			return (-1);
// 	}
// 	return (0);
// }