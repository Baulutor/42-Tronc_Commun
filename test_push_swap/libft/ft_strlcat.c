/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:39:33 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 17:58:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		size;
	size_t		len_dest;

	destination = dest;
	source = src;
	size = dstsize;
	while (size-- != 0 && *destination != '\0')
		destination++;
	len_dest = destination - dest;
	size = dstsize - len_dest;
	if (size == 0)
		return (len_dest + ft_strlen(source));
	while (*source != '\0')
	{
		if (size != 1)
		{
			*destination++ = *source;
			size--;
		}
		source++;
	}
	*destination = '\0';
	return (len_dest + (source - src));
}
