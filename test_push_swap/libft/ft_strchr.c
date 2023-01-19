/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:42:42 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 18:00:13 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *a, int c)
{
	size_t			x;
	unsigned char	cha;

	x = 0;
	cha = (char)c;
	while (a[x])
	{
		if (a[x] == cha)
			return ((char *)a + x);
		x++;
	}
	if (cha == 0)
		return ((char *) a + x);
	return (NULL);
}
