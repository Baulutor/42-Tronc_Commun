/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:58:39 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 21:06:50 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	car;

	str = (char *) s;
	car = (char) c;
	while (*str && *str != car)
		str++;
	if (*str == car)
		return (str);
	return (0);
}
