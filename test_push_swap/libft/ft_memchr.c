/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:58:16 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 18:08:29 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t			x;
	unsigned char	*src;
	unsigned char	c;

	x = 0;
	c = (unsigned char)searchedChar;
	src = (unsigned char *)memoryBlock;
	while (x < size)
	{
		if (c == src[x])
			return (&src[x]);
		x++;
	}
	return (NULL);
}
