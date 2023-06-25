/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:09:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_print.h"

static int	print_unsigned(int nbr, int fd)
{
	unsigned int	u_nbr;
	size_t			len;

	u_nbr = nbr;
	len = 0;
	if (u_nbr > 0)
	{
		len += print_unsigned(u_nbr / 10, fd);
		len += ft_putchar_fd('0' + u_nbr % 10, fd);
	}
	return (len);
}

static void	call_print_adr(long long int nbr, char dep, int *res, t_print_a m)
{
	if (nbr == 0)
		(*res) += ft_putstr_fd("0x0", m.fd);
	else
		print_adress_fd(nbr, dep, res, &m);
}

static void	follow_is_format(const char *s, t_print d, va_list *args, int *res)
{
	int	u;

	u = va_arg(*args, int);
	if (u == 0)
		(*res) += ft_putchar_fd('0', d.fd);
	else if (s[d.ind + 1] == 'u')
		(*res) += print_unsigned(u, d.fd);
	else if (s[d.ind + 1] == 'x')
		conv_ten_to_hex_fd(u, 'a', res, d);
	else if (s[d.ind + 1] == 'X')
		conv_ten_to_hex_fd(u, 'A', res, d);
	else if (s[d.ind + 1] == 'i')
		(*res) += ft_putnbr_fd(u, d.fd);
}

static int	is_format(const char *s, t_print d, va_list *args, int *res)
{
	t_print_a	m;

	m.fd = d.fd;
	m.mod = 1;
	if (s[d.ind] == '%' && (s[d.ind + 1] == 'c' || s[d.ind + 1] == 's' || \
				s[d.ind + 1] == 'p' || s[d.ind + 1] == 'd' || s[d.ind + 1] == \
				'i' || s[d.ind + 1] == 'u' || s[d.ind + 1] == 'x' || s[d.ind + \
				1] == 'X' || s[d.ind + 1] == '%'))
	{
		if (s[d.ind + 1] == 'c')
			(*res) += ft_putchar_fd(va_arg(*args, int), d.fd);
		else if (s[d.ind + 1] == 's')
			(*res) += ft_putstr_fd(va_arg(*args, char *), d.fd);
		else if (s[d.ind + 1] == 'p')
			call_print_adr(va_arg(*args, long long unsigned int), 'a', res, m);
		else if (s[d.ind + 1] == 'd')
			(*res) += ft_putnbr_fd(va_arg(*args, int), d.fd);
		else if (s[d.ind + 1] == '%')
			(*res) += ft_putchar_fd('%', d.fd);
		else
			follow_is_format(s, d, args, res);
		return (1);
	}
	else
		return (0);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	t_print	data;
	va_list	args;
	int		format;
	int		res;

	if (write(1, 0, 0) == -1)
		return (-1);
	data.ind = 0;
	data.fd = fd;
	res = 0;
	va_start(args, str);
	while (str[data.ind] != '\0')
	{
		format = is_format(str, data, &args, &res);
		if (str[data.ind] == '%' && format == 0)
			data.ind++;
		if (str[data.ind] == '%' && format == 1)
			data.ind++;
		else
			res += ft_putchar_fd(str[data.ind], fd);
		data.ind++;
	}
	va_end(args);
	return (res);
}
