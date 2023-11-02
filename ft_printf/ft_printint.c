/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:14:13 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 13:35:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int d)
{
	long long int	nbr;
	size_t			x;

	nbr = d;
	x = 0;
	if (nbr < 0)
	{
		x += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		x += ft_printint(nbr / 10);
		x += ft_printint(nbr % 10);
	}
	else
	{
		nbr += 48;
		x += write(1, &nbr, 1);
	}
	return (x);
}
