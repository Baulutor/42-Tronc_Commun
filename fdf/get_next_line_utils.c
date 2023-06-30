/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:16 by dbaule            #+#    #+#             */
/*   Updated: 2023/06/30 14:00:04 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr_gnl(char *a)
{
	size_t	x;
	size_t	y;
	char	*tmp;

	x = 0;
	y = 0;
	while (a[x] && a[x] != '\n')
		x++;
	if (!a[x])
		return (free (a), a = NULL, NULL);
	if (a[x] == '\n' && a[x + 1] == '\0')
		return (free(a), NULL);
	tmp = ft_calloc_gnl((sizeof(char)), (ft_strlen(a) - x + 1));
	if (!tmp)
		return (tmp = NULL, free(a), NULL);
	if (a[x] == '\n')
		x++;
	while (a[x])
		tmp[y++] = a[x++];
	return (free(a), a = NULL, tmp);
}

static char	*ft_strdup_gnl(const char *src)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = ft_calloc_gnl(sizeof(char), ft_strlen(src) + 1);
	if (!tab)
		return (tab = NULL, NULL);
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	*ft_calloc_gnl(size_t elementCount, size_t elementSize)
{
	unsigned char	*tab;
	size_t			x;
	size_t			n;

	x = 0;
	if (elementSize && elementCount > SIZE_MAX / elementSize)
		return (0);
	n = elementCount * elementSize;
	tab = malloc(elementCount * elementSize);
	if (!tab)
		return (perror("Error"), NULL);
	if (n != 0)
	{
		while (x < n)
		{
			((char *)tab)[x] = '\0';
			x++;
		}
	}
	return (tab);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*tab;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!s1 && !s2)
		return (s1 = NULL, s2 = NULL, NULL);
	else if (!s1)
		return (s1 = NULL, ft_strdup_gnl(s2));
	else if (!s2)
		return (s2 = NULL, ft_strdup_gnl(s1));
	tab = ft_calloc_gnl(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (tab = NULL, NULL);
	while (s1[x])
	{
		tab[x] = s1[x];
		x++;
	}
	while (s2[y])
		tab[x++] = s2[y++];
	tab[x] = '\0';
	return (tab);
}
