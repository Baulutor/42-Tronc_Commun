/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:14:37 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:20:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_hubprint(int c, va_list list)
{
	size_t	x;

	x = 0;
	if (c == 'c')
		x += ft_printchar(va_arg(list, int));
	if (c == 's')
		x += ft_printstr(va_arg(list, char *));
	if (c == 'i' || c == 'd')
		x += ft_printint(va_arg(list, int));
	if (c == 'u')
		x += ft_printunsignedint(va_arg(list, unsigned int));
	if (c == 'x')
		x += ft_printhexamin(va_arg(list, int));
	if (c == 'X')
		x += ft_printhexamaj(va_arg(list, int));
	if (c == 'p')
		x += ft_printaddress(va_arg(list, unsigned long long));
	if (c == '%')
		x += ft_printchar('%');
	return (x);
}

static int	ft_checkc(size_t x, const char *s)
{
	if (s[x + 1] == 'c' || s[x + 1] == 'i' || s[x + 1] == 's')
		return (1);
	else if (s[x + 1] == 'u' || s[x + 1] == 'x' || s[x + 1] == 'X')
		return (1);
	else if (s[x + 1] == 'p' || s[x + 1] == '%' || s[x + 1] == 'd')
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	x;
	va_list	list;
	ssize_t	len;

	if (write(1, 0, 0) != 0)
		return (-1);
	x = 0;
	len = 0;
	va_start(list, s);
	while (s[x])
	{
		if (s[x] == '%')
			len += ft_hubprint(s[x + 1], list);
		else
			len += write(1, &s[x], 1);
		if ((s[x] == '%' && ft_checkc(x, s) == 1))
			x++;
		x++;
	}
	va_end(list);
	return (len);
}
