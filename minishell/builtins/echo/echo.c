/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:01:38 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 17:10:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/echo.h"

void	echo(char **arg, int option)
{
	t_echo	e;

	init_echo(&e);
	if (option == 1)
		e.i = position_echo_n(arg, &e.j, &e.flag, &option);
	while (arg[e.i])
	{
		ft_printf("%s", arg[e.i]);
		e.i += 1;
		if (arg[e.i])
			ft_printf(" ");
	}
	if (option == 0)
		ft_printf_fd(1, "\n");
}
