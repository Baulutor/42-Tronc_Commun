/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/28 21:47:38 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

char	*pwd(void)
{
	char	*cmd;

	cmd = getcwd(NULL, 0);
	if (cmd == NULL)
		return (NULL);
	ft_printf("%s\n", cmd);
	return (cmd);
}

void	env(char **envir)
{
	int	i;

	i = 0;
	while (envir[i])
		ft_printf("%s\n", envir[i++]);
}

void	quit(void)
{
	printf("exit\n");
	silent_quit();
}
