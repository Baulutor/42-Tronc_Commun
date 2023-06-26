/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:38:23 by eslamber          #+#    #+#             */
/*   Updated: 2023/06/26 21:08:19 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define ERR STDERR_FILENO

static void	errors_bis(t_errors error);

void	errors(t_errors error, char *cmd)
{
	if (error == PIPE)
		ft_printf_fd(ERR, "Error : Problem with pipe function.\n");
	else if (error == CONDITIONS)
		ft_printf_fd(ERR, "Error : You don't have enought parameters.\nOr the \
environnement is NULL\n");
	else if (error == FORK)
		ft_printf_fd(ERR, "Error : Problem with fork function\n");
	else if (error == DUP)
		ft_printf_fd(ERR, "Error : Problem with dup function\n");
	else if (error == CLOSE)
		ft_printf_fd(ERR, "Error : Problem with close function\n");
	else if (error == SPLIT)
		ft_printf_fd(ERR, "Error : Problem with split function\n");
	else if (error == CMD && cmd != NULL)
		ft_printf_fd(ERR, "Error : command not found: %s\n", cmd);
	else if (error == EXEC)
		ft_printf_fd(ERR, "Error : Problem with execve function\n");
	else if (error == CLOSE_P0)
		ft_printf_fd(ERR, "Error : Problem when closing pipe[0]\n");
	else if (error == CLOSE_P1)
		ft_printf_fd(ERR, "Error : Problem when closing pipe[1]\n");
	errors_bis(error);
	if (cmd == NULL)
		exit(1);
}

static void	errors_bis(t_errors error)
{
	if (error == JOIN)
		ft_printf_fd(ERR, "Error : Problem with ft_strjoin function\n");
	if (error == WAIT)
		ft_printf_fd(ERR, "Error : Problem with wait function.\n");
}
