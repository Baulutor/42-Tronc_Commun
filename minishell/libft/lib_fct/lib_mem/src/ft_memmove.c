/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:35:25 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 21:09:26 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long long int	len;

	if (dest == 0 && src == 0)
		return (0);
	if (dest > src)
	{
		len = n - 1;
		while (len >= 0)
		{
			((unsigned char *)dest)[len] = ((unsigned char *) src)[len];
			len--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
