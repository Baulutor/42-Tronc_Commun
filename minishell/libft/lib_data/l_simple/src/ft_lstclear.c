/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:11:32 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 20:27:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_simple.h"

void	ft_lstclear(t_listft **lst, void (*del)(void *))
{
	t_listft	*tmp;

	if (lst == 0 || *lst == 0)
		return ;
	tmp = *lst;
	if (tmp->next == 0)
		ft_lstdelone(tmp, del);
	else
	{
		ft_lstclear(&(tmp->next), del);
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
