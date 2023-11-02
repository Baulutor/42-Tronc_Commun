/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:28:01 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:27:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		*(unsigned char *)(s + len) = (unsigned char) c;
		len++;
	}
	return (s);
}
