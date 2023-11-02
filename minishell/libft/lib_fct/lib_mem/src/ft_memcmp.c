/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:07:34 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:27:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

int	ft_memcmp(const void *s, const void *c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (((unsigned char *)s)[len] != ((unsigned char *)c)[len])
			return (((unsigned char *)s)[len] - ((unsigned char *)c)[len]);
		len++;
	}
	return (0);
}
