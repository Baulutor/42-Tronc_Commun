/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:18 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/19 12:25:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(char *tab, long int n, unsigned int size)
{
	long int	nbr;
	long int	buf;

	nbr = n;
	size = size - 1;
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr *= -1;
	}
	buf = nbr;
	while (size > 0)
	{
		buf %= 10;
		tab[size] = buf + 48;
		nbr /= 10;
		buf = nbr;
		size--;
	}
	if (n >= 0)
		tab[size] = nbr + 48;
	return (tab);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*tab;
	long int		buf1;

	size = 0;
	buf1 = n;
	if (n < 0)
	{
		buf1 *= -1;
		size++;
	}
	while (buf1 >= 10)
	{
		buf1 = buf1 / 10;
		size++;
	}
	size++;
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	tab[size] = 0;
	ft_putnbr(tab, n, size);
	return (tab);
}
