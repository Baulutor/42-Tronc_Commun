/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:36:00 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:27:36 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (((unsigned char *)src)[len] == (unsigned char)c)
			return ((unsigned char *)src + len);
		len++;
	}
	return (0);
}
