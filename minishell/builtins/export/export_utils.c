/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:48:07 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:46:15 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/export.h"

static int	check_sort(t_cmd *pip);

int	pars_exp(int *flag, char *na_val)
{
	int	i;

	i = 0;
	if (na_val[0] == '=')
		return (ft_printf_fd(2, "Error : not a valid identifier\n"), \
		free(na_val), g_status = 1, -1);
	while (na_val[i] && na_val[i] != '=')
	{
		if ((na_val[i] == '-' || (i > 0 && na_val[i] == '+' && na_val[i - 1] \
		!= '+' && (na_val[i + 1] != '=' || na_val[i + 1] == '\0'))))
			return (ft_printf_fd(2, "Error : not a valid identifier\n"), \
			g_status = 1, free(na_val), -1);
		else if (na_val[i + 1] && na_val[i] == '+' && na_val[i + 1] == '=')
			*flag = 1;
		i++;
	}
	return (i);
}

int	strcmp_plus(char *first, char *sec, size_t n)
{
	size_t			len;
	unsigned char	*u_first;
	unsigned char	*u_sec;

	len = 0;
	u_first = (unsigned char *) first;
	u_sec = (unsigned char *) sec;
	while ((u_first[len] != '\0' || u_sec[len] != '\0') && len < n)
	{
		if (u_sec[len] != '+')
		{
			if (u_first[len] != u_sec[len])
				return (u_first[len] - u_sec[len]);
		}
		len++;
	}
	return (0);
}

void	sort_export(t_cmd *pip)
{
	size_t	i;
	char	*buf;

	i = 0;
	while (pip->exp_env[i])
	{
		if (pip->exp_env[i + 1] && strncmp(pip->exp_env[i], \
		pip->exp_env[i + 1], ft_strlen(pip->exp_env[i])) > 0)
		{
			buf = pip->exp_env[i];
			pip->exp_env[i] = pip->exp_env[i + 1];
			pip->exp_env[i + 1] = buf;
		}
		i++;
	}
	if (check_sort(pip) == 1)
		sort_export(pip);
	else
		return ;
}

static int	check_sort(t_cmd *pip)
{
	size_t	i;

	i = 0;
	while (pip->exp_env[i + 1])
	{
		if (ft_strncmp(pip->exp_env[i], pip->exp_env[i + 1], \
		ft_strlen(pip->exp_env[i])) > 0)
			return (1);
		i++;
	}
	return (0);
}
