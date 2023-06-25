/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:38:02 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 13:56:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_print.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_putstr_fd(s, fd);
	return (len + ft_putchar_fd('\n', fd));
}
