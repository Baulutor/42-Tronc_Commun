/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:17:55 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/15 17:13:59 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	unsigned int	x;
	unsigned char	*cha;
	unsigned char	*cha2;

	x = 0;
	cha = (unsigned char *) a;
	cha2 = (unsigned char *) b;
	while ((cha2[x] || cha[x]) && x < n)
	{
		if (cha2[x] < cha[x])
			return (1);
		else if (cha2[x] > cha[x])
			return (-1);
		x++;
	}
	return (0);
}
