/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:22:31 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/17 20:42:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_simple.h"

t_listft	*ft_lstnew(void *new_content)
{
	t_listft	*new;

	new = (t_listft *) malloc(sizeof(t_listft));
	if (new == 0)
		return (0);
	new->next = 0;
	new->content = new_content;
	return (new);
}
