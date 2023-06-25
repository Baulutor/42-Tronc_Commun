/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:07:50 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 14:15:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

static int	ft_iswhitespace(int car)
{
	char	c;

	c = (char) car;
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	res;
	size_t		ind;
	int			minus;

	ind = 0;
	res = 0;
	minus = 1;
	while (str[ind] != '\0' && ft_iswhitespace(str[ind]) == 1)
		ind++;
	if (str[ind] == '-')
	{
		ind++;
		minus = -1;
	}
	else if (str[ind] == '+')
		ind++;
	while (str[ind] && ft_isdigit(str[ind]))
	{
		if (ft_isdigit(str[ind]))
			res = res * 10 + (str[ind] - '0');
		ind++;
	}
	res = res * minus;
	return ((int) res);
}
