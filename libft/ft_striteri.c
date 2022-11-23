/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:38:19 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/19 09:23:53 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	if (s != NULL || f != NULL)
	{	
		y = ft_strlen(s);
		while (x < y)
		{
			(*f)(x, s);
			x++;
			s++;
		}
	}
}
