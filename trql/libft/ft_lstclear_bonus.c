/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:50:39 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/22 11:13:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s1;
	t_list	*s2;

	if (!lst || !(del))
		return ;
	s1 = *lst;
	s2 = *lst;
	while (s1)
	{
		s2 = s1->next;
		(*del)(s1->content);
		free(s1);
		s1 = s2;
	}
	*lst = 0;
}
