/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:44:30 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 19:46:25 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

int	ft_in(const char src, const char *test)
{
	size_t	ind;

	ind = 0;
	while (test[ind] != '\0')
	{
		if (test[ind] == src)
			return (1);
		ind++;
	}
	return (0);
}
