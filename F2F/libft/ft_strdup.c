/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:24:40 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/28 14:27:14 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dup(const char *src, char *tab)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = ' ';
	tab[i + 1] = 0;
	return (tab);
}

char	*ft_strdup(const char *src)
{
	char	*tab;

	tab = malloc(sizeof(char) * ft_strlen(src) + 2);
	if (!tab)
		return (0);
	ft_dup(src, tab);
	return (tab);
}
