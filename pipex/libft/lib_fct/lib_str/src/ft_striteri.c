/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:03:20 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:22:00 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	ind;

	ind = 0;
	while (s[ind] != '\0')
	{
		f(ind, &s[ind]);
		ind++;
	}
}
