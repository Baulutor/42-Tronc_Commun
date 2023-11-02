/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexamaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:14:10 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:22:36 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexamaj(int b)
{
	unsigned int	nbr;
	size_t			x;

	nbr = b;
	x = 0;
	if (nbr >= 16)
	{
		x += ft_printhexamaj(nbr / 16);
		x += ft_printhexamaj(nbr % 16);
	}
	else if (nbr >= 10 && nbr < 16)
		x += ft_printchar(nbr + 55);
	else
		x += ft_printchar(nbr + 48);
	return (x);
}
