/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:00:28 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/21 19:50:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	y;
	char			*tab;

	y = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		tab = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else if ((len + start) > ft_strlen(s))
		tab = (char *)malloc(sizeof(char) * (len));
	else
		tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (y < len && s[start])
	{
		tab[y] = s[start];
		y++;
		start++;
	}
	tab[y] = '\0';
	return (tab);
}
