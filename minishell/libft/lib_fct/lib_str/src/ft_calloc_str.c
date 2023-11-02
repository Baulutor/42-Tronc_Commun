/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:45:53 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 13:51:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

void	*ft_calloc_str(size_t nbr, size_t size)
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
