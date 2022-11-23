/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:11:12 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 18:07:14 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t				i;

	if ((char *)destination > (char *)source)
	{
		while (size > 0)
		{
			((char *)destination)[size - 1] = ((char *)source)[size - 1];
			size--;
		}
	}
	else if ((char *) destination < (char *)source)
	{
		i = 0;
		while (size > i)
		{
			((char *)destination)[i] = ((char *)source)[i];
			i++;
		}
	}
	return ((void *)(char *)destination);
}
