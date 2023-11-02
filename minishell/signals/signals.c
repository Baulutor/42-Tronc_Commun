/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:50:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/28 21:41:57 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	main_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &hsigint;
	sigaction(CON_C, &sa, NULL);
	sa.sa_handler = IGN;
	sigaction(QUIT, &sa, NULL);
}

void	exec_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &hsigint_exec;
	sigaction(CON_C, &sa, NULL);
	sa.sa_handler = &hsigquit;
	sigaction(QUIT, &sa, NULL);
}

void	hd_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &hsigint_hd;
	sigaction(CON_C, &sa, NULL);
}

void	unset_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = IGN;
	sigaction(CON_C, &sa, NULL);
	sigaction(QUIT, &sa, NULL);
}
