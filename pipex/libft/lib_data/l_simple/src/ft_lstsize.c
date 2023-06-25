/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:50:07 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/04 11:05:05 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_simple.h"

int	ft_lstsize(t_listft *lst)
{
	int			len;
	t_listft	*count;

	len = 0;
	if (lst == 0)
		return (0);
	count = lst;
	while (count)
	{
		count = count->next;
		len++;
	}
	return (len);
}
