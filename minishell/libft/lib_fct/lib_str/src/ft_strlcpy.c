/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:12:56 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 20:44:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n - 1 && src[len] != '\0' && n != 0)
	{
		dest[len] = src[len];
		len++;
	}
	if (n != 0)
		dest[len] = '\0';
	return (ft_strlen(src));
}
