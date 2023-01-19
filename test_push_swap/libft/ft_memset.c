/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:34:37 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 18:05:56 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	x;

	x = 0;
	while (x < count)
	{
		((unsigned char *)pointer)[x] = (unsigned char)value;
		x++;
	}
	return ((void *)pointer);
}
