/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:14:54 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 09:55:34 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*x;

	if (!lst || !*(*f))
		return (0);
	tmp = NULL;
	while (lst)
	{
		x = ft_lstnew((f)(lst->content));
		if (!x)
		{
			ft_lstclear(&x, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, x);
		lst = lst->next;
		x = x->next;
	}
	return (tmp);
}
