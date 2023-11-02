/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:32:18 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:24:36 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsignedint(unsigned int u)
{
	unsigned int	nbr;
	size_t			x;

	nbr = u;
	x = 0;
	if (nbr >= 10)
	{
		x += ft_printunsignedint(nbr / 10);
		x += ft_printunsignedint(nbr % 10);
	}
	else
	{
		nbr += 48;
		x += write(1, &nbr, 1);
	}
	return (x);
}
