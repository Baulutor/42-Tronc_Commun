/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:09:52 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/05 16:56:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_data.h"

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

static void	call_print_adr(long long int nbr, char dep, int *res, int mod)
{
	if (nbr == 0)
		(*res) += ft_putstr_fd("0x0", 1);
	else
		print_adress(nbr, dep, res, mod);
}

static void	following_is_format(const char *s, int i, va_list *args, int *res)
{
	int	u;

	u = va_arg(*args, int);
	if (u == 0)
		(*res) += ft_putchar_fd('0', 1);
	else if (s[i + 1] == 'u')
		(*res) += print_unsigned(u, 1);
	else if (s[i + 1] == 'x')
		conv_ten_to_hex(u, 'a', res);
	else if (s[i + 1] == 'X')
		conv_ten_to_hex(u, 'A', res);
	else if (s[i + 1] == 'i')
		(*res) += ft_putnbr_fd(u, 1);
}

static int	is_format(const char *s, size_t i, va_list *args, int *res)
{
	if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p' \
				|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u' \
				|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%'))
	{
		if (s[i + 1] == 'c')
			(*res) += ft_putchar_fd(va_arg(*args, int), 1);
		else if (s[i + 1] == 's')
			(*res) += ft_putstr_fd(va_arg(*args, char *), 1);
		else if (s[i + 1] == 'p')
			call_print_adr(va_arg(*args, long long unsigned int), 'a', res, 1);
		else if (s[i + 1] == 'd')
			(*res) += ft_putnbr_fd(va_arg(*args, int), 1);
		else if (s[i + 1] == '%')
			(*res) += ft_putchar_fd('%', 1);
		else
			following_is_format(s, i, args, res);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	ind;
	va_list	args;
	int		format;
	int		res;

	if (write(1, 0, 0) == -1)
		return (-1);
	ind = 0;
	res = 0;
	va_start(args, str);
	while (str[ind] != '\0')
	{
		format = is_format(str, ind, &args, &res);
		if (str[ind] == '%' && format == 0)
			ind++;
		if (str[ind] == '%' && format == 1)
			ind++;
		else
			res += ft_putchar_fd(str[ind], 1);
		ind++;
	}
	va_end(args);
	return (res);
}
