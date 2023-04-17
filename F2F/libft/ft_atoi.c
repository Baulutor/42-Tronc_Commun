/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:24:17 by dbaule            #+#    #+#             */
/*   Updated: 2023/04/13 09:42:50 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *a)
{
	size_t	x;
	int		sign;
	int		value;

	x = 0;
	sign = 1;
	value = 0;
	while (a[x] == ' ' || (a[x] >= 9 && a[x] <= 13))
		x++;
	if (a[x] == '+' || a[x] == '-')
	{
		if (a[x] == '-')
		{	
			sign *= -1;
		}
		x++;
	}
	while ((a[x] <= 57 && a[x] >= 48))
	{
		if (value != ((value * 10 + (sign * (a[x] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		value = 10 * value + ((a[x] - 48) * sign);
		x++;
	}
	return (value);
}
