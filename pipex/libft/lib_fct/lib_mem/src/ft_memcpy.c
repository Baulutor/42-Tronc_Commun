/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:14:14 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 21:09:51 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;

	if (dest == 0 && src == 0)
		return (0);
	len = 0;
	while (len < n)
	{
		((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		len++;
	}
	return (dest);
}
