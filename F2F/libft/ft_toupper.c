/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:29:18 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 09:53:49 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
	return (a);
}