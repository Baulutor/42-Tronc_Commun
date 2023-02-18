/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:09:02 by dbaule            #+#    #+#             */
/*   Updated: 2023/02/18 11:28:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*tab;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	tab = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 2));
	if (!tab)
		return (NULL);
	while (s1[x])
	{
		tab[x] = s1[x];
		x++;
	}
	tab[x] = ' ';
	x++;
	while (s2[y])
	{
		tab[x] = s2[y];
		x++;
		y++;
	}
	tab[x] = '\0';
	free(s1);
	return (tab);
}
