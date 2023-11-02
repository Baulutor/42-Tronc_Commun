/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:05:26 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 20:51:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	long long	save;
	char		car;

	len = 0;
	save = -1;
	car = (char) c;
	while (s[len] != '\0')
	{
		if (s[len] == car)
			save = len;
		len++;
	}
	if (car == '\0')
		return ((char *)s + len);
	if (save == -1)
		return (0);
	else
		return ((char *)s + save);
}
