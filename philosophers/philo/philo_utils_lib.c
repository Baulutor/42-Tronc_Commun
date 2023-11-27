/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_lib.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:35:20 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/25 22:35:48 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_atoi(const char *a)
{
	size_t				x;
	int					sign;
	unsigned long		value;

	x = 0;
	sign = 1;
	value = 0;
	while (a[x] == ' ' || (a[x] >= 9 && a[x] <= 13))
		x++;
	if (a[x] == '+')
		x++;
	while (a[x] <= 57 && a[x] >= 48)
	{
		if (value != ((value * 10 + (sign * (a[x] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		value = 10 * value + ((a[x] - 48) * sign);
		x++;
	}
	return (value);
}

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	unsigned int	x;
	unsigned char	*cha;
	unsigned char	*cha2;

	x = 0;
	cha = (unsigned char *) a;
	cha2 = (unsigned char *) b;
	while ((cha2[x] || cha[x]) && x < n)
	{
		if (cha2[x] < cha[x])
			return (1);
		else if (cha2[x] > cha[x])
			return (-1);
		x++;
	}
	return (0);
}
