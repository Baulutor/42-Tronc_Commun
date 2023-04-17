/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:27:17 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 11:02:32 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	unsigned char	*tab;

	if (elementSize && elementCount > SIZE_MAX / elementSize)
		return (0);
	tab = malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	ft_bzero(tab, elementCount * elementSize);
	return (tab);
}
