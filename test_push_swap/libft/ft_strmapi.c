/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:09:12 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/19 10:02:17 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	x;

	x = 0;
	if (!s || !f)
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	while (s[x])
	{
		tab[x] = (*f)(x, s[x]);
		x++;
	}
	tab[x] = 0;
	return (tab);
}
