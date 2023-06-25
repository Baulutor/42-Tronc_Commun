/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ten_to_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:03:08 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/17 17:58:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

void	print_adress(long long int nbr, char dep, int *res, int mod)
{
	long long unsigned int	u_nbr;

	if (mod == 1)
		(*res) += ft_putstr_fd("0x", 1);
	u_nbr = nbr;
	if (u_nbr > 0)
	{
		print_adress(u_nbr / 16, dep, res, 0);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}

void	conv_ten_to_hex(int nbr, char dep, int *res)
{
	unsigned int	u_nbr;

	u_nbr = nbr;
	if (u_nbr > 0)
	{
		conv_ten_to_hex(u_nbr / 16, dep, res);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, 1);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, 1);
	}
}

void	print_adres_fd(long long int nbr, char dep, int *res, t_p_a *m)
{
	long long unsigned int	u_nbr;

	if (m->mod == 1)
		(*res) += ft_putstr_fd("0x", m->fd);
	u_nbr = nbr;
	if (u_nbr > 0)
	{
		m->mod = 0;
		print_adres_fd(u_nbr / 16, dep, res, m);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, m->fd);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, m->fd);
	}
}

void	conv_to_hex_fd(int nbr, char dep, int *res, t_p d)
{
	unsigned int	u_nbr;

	u_nbr = nbr;
	if (u_nbr > 0)
	{
		conv_to_hex_fd(u_nbr / 16, dep, res, d);
		u_nbr = u_nbr % 16;
		if (u_nbr > 9)
			(*res) += ft_putchar_fd(dep + u_nbr % 10, d.fd);
		else
			(*res) += ft_putchar_fd('0' + u_nbr, d.fd);
	}
}
