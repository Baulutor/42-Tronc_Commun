/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:07:36 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:10:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

static void	ft_analyse(const char *src, const char *c, size_t *l, size_t *l_f)
{
	size_t	save_l;

	*l = 0;
	while (ft_in(src[*l], c) == 1)
		(*l)++;
	save_l = *l;
	*l_f = *l;
	while (src[save_l] != '\0')
	{
		if (ft_in(src[save_l], c) == 0)
			*l_f = save_l;
		save_l++;
	}
}

char	*ft_strtrim(const char *src, const char *c)
{
	size_t	begin;
	size_t	end;
	char	*new;

	ft_analyse(src, c, &begin, &end);
	new = ft_substr(src, (unsigned int) begin, end - begin + 1);
	if (new == 0)
		return (0);
	return (new);
}
