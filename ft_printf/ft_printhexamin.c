/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexamin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:08 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:20:13 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexamin(int a)
{
	unsigned int	nbr;
	size_t			x;

	nbr = a;
	x = 0;
	if (nbr >= 16)
	{
		x += ft_printhexamin(nbr / 16);
		x += ft_printhexamin(nbr % 16);
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
