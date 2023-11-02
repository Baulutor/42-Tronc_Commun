/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:25:26 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:11:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_print.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n > 9)
	{
		len += ft_putnbr_fd(n / 10, fd);
		len += ft_putchar_fd('0' + n % 10, fd);
	}
	else if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		len += ft_putnbr_fd(-n, fd);
	}
	else
		len += ft_putchar_fd('0' + n, fd);
	return (len);
}
