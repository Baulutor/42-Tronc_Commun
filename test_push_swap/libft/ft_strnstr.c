/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:50:04 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/18 16:37:28 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	if (little[y] == 0)
		return ((char *)big);
	while (big[x] && len > x && little[y])
	{
		while ((big[x + y] == little[y]) && len > (x + y))
		{
			if (little[y + 1] == 0)
				return ((char *)big + x);
			y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}
