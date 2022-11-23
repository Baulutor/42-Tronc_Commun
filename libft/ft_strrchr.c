/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:25:03 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/19 10:42:45 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *a, int c)
{
	int	x;

	x = ft_strlen(a);
	while (x >= 0)
	{
		if (a[x] == (char)c)
			return ((char *)(a + x));
		x--;
	}
	return (NULL);
}
