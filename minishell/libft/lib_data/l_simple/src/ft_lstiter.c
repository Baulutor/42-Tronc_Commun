/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:31:00 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 20:27:13 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_simple.h"

void	ft_lstiter(t_listft *lst, void (*f)(void *))
{
	if (lst == 0)
		return ;
	f(lst->content);
	ft_lstiter(lst->next, f);
}
