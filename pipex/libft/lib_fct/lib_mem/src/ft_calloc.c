/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:45:53 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:12:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_mem.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void					*new;
	long long unsigned int	len;
	long long unsigned int	tot;

	if (size != 0 && nbr > SIZE_MAX / size)
		return (0);
	len = 0;
	tot = size * nbr;
	new = malloc(tot);
	if (new == 0)
		return (0);
	while (len < tot)
	{
		((unsigned char *)new)[len] = 0;
		len++;
	}
	return (new);
}
