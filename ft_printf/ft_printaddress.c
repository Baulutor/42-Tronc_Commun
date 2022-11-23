/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:26 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:07:03 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexaaddress(unsigned long long a)
{
	unsigned long long	nbr;
	size_t				x;

	nbr = a;
	x = 0;
	if (nbr >= 16)
	{
		x += ft_hexaaddress(nbr / 16);
		x += ft_hexaaddress(nbr % 16);
	}
	else if (nbr >= 10 && nbr < 16)
	{
		nbr -= 10;
		nbr += 97;
		x += write (1, &nbr, 1);
	}
	else
	{
		nbr += 48;
		x += write(1, &nbr, 1);
	}
	return (x);
}

int	ft_printaddress(unsigned long long a)
{
	size_t	x;

	x = 0;
	x += write(1, "0x", 2);
	if (!a)
		return (x += write(1, "0", 1));
	x += ft_hexaaddress(a);
	return (x);
}
