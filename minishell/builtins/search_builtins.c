/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/28 21:45:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

static void	determine_echo_or_cd(char **str, int *option);
static int	search_pwd_exit_env(char **spt, t_cmd *pip);

int	search_builtins(char **spt, t_cmd *pip)
{
	int	option;

	option = 0;
	if (spt == NULL || !spt[0])
	{
		return (1);
	}
	if (search_pwd_exit_env(spt, pip) == 1)
		return (1);
	else if ((ft_strlen(spt[0]) == 4 && ft_strncmp(spt[0], "echo", 4) == 0) \
	|| (ft_strlen(spt[0]) == 2 && ft_strncmp(spt[0], "cd", 2) == 0))
	{
		determine_echo_or_cd(spt, &option);
		if (option == 0 || option == 1)
			return (echo(spt, option), g_status = 0, 1);
		else if (option == 2)
			return (1);
	}
	else if ((ft_strlen(spt[0]) == 6 \
	&& ft_strncmp(spt[0], "export", 6) == 0) && spt[1] == NULL)
		return (print_export(pip->exp_env), 1);
	else if ((ft_strlen(spt[0]) == 6 && ft_strncmp(spt[0], "export", 6) == 0) \
	|| (ft_strlen(spt[0]) == 5 && ft_strncmp(spt[0], "unset", 5) == 0))
		return (1);
	return (0);
}

static int	search_pwd_exit_env(char **spt, t_cmd *pip)
{
	if (ft_strlen(spt[0]) == 3 && ft_strncmp(spt[0], "pwd", 3) == 0)
	{
		if (spt[1] && spt[1][0] == '-')
			return (ft_printf_fd(2, "Error : invalid option\n"), \
			g_status = 2, 1);
		return (free(pwd()), 1);
	}
	else if (ft_strlen(spt[0]) == 4 && ft_strncmp(spt[0], "exit", 4) == 0)
		return (intermediate_exit(spt), 1);
	else if (ft_strlen(spt[0]) == 3 && ft_strncmp(spt[0], "env", 3) == 0)
	{
		return (env(pip->env), 1);
	}
	return (0);
}

static void	determine_echo_or_cd(char **str, int *option)
{
	if (ft_strlen(str[0]) == 4 && ft_strncmp(str[0], "echo", 4) == 0)
	{
		if (str[1] == NULL)
			return ;
		else if (ft_strncmp(str[1], "-n", 2) == 0)
		{
			*option = 1;
			if (str[2] == NULL)
				return ;
		}
	}
	else if (ft_strlen(str[0]) == 2 && ft_strncmp(str[0], "cd", 2) == 0)
	{
		*option = 1;
		if (str[1] == NULL)
			return ;
		*option = 2;
		if (str[2] != NULL)
			return (error(TOO_MANY_ARG, str[0]));
	}
	else
		*option = 3;
	return ;
}
