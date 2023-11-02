/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:12:06 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:16:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	ind;

	ind = 0;
	new = ft_strdup(src);
	if (new == 0)
		return (0);
	while (new[ind] != '\0')
	{
		new[ind] = f(ind, new[ind]);
		ind++;
	}
	return (new);
}
