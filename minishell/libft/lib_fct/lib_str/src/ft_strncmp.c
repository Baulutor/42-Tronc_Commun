/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:11:33 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/18 17:58:00 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

int	ft_strncmp(const char *first, const char *sec, size_t n)
{
	size_t			len;
	unsigned char	*u_first;
	unsigned char	*u_sec;

	len = 0;
	u_first = (unsigned char *) first;
	u_sec = (unsigned char *) sec;
	while ((u_first[len] != '\0' || u_sec[len] != '\0') && len < n)
	{
		if (u_first[len] != u_sec[len])
			return (u_first[len] - u_sec[len]);
		len++;
	}
	return (0);
}
