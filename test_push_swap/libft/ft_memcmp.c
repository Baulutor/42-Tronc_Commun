/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:52:18 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 18:07:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t	x;

	x = 0;
	while (x < size)
	{
		if (*(unsigned char *)(s1 + x) != *(unsigned char *)(s2 + x))
			return (*(unsigned char *)(s1 + x) - *(unsigned char *)(s2 + x));
		x++;
	}
	return (0);
}
