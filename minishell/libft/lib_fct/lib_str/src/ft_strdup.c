/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:08:28 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/18 12:20:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	len;

	len = ft_strlen(src) + 1;
	new = (char *) malloc(sizeof(char) * len);
	if (new == 0)
		return (0);
	ft_strlcpy(new, src, len);
	return (new);
}
