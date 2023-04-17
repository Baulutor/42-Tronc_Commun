/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:53:29 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/14 16:14:00 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalnum(int a)
{
	if ((a <= 57 && a >= 48) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}