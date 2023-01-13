/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:53:21 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/17 18:53:32 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_in_charset(char c, const char *set)
{
	int	x;

	x = 0;
	while (set[x])
	{
		if (c == set[x])
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		x;
	char	*tab;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	x = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_charset(s1[start], set))
			start++;
	while (end > start && is_in_charset(s1[end - 1], set))
		end--;
	tab = ft_substr(s1, start, end - start);
	return (tab);
}
