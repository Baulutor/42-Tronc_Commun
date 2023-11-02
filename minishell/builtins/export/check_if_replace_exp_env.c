/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_replace_exp_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:00:59 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:46:18 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/export.h"

static int	replace_if_plus_exp_env(int j, t_exp *exp, t_cmd *pip, int i);
static int	replace_if_exp_env(t_cmd *pip, t_exp *exp, int i);

int	check_if_replace_exp_env(t_cmd *pip, t_exp *exp, int z, int j)
{
	exp->i = 0;
	while (pip->exp_env[exp->i])
	{
		z = pars_exp(&exp->flag, &(pip->exp_env[exp->i])[11]);
		if (exp->flag == 1)
		{
			if (strcmp_plus(pip->exp_env[exp->i] + 11, exp->na_val, z + 1) == 0)
			{
				if (replace_if_plus_exp_env(j, exp, pip, exp->i) == 1)
					return (free(exp->na_val), -2);
				return (-1);
			}
		}
		else
		{
			if (ft_strncmp(pip->exp_env[exp->i] + 11, exp->na_val, z + 1) == 0)
			{
				if (replace_if_exp_env(pip, exp, exp->i) == 1)
					return (free(exp->na_val), -2);
				return (-1);
			}
		}
		exp->i++;
	}
	return (exp->i);
}

static int	replace_if_plus_exp_env(int j, t_exp *exp, t_cmd *pip, int i)
{
	j++;
	exp->buf = ft_strjoin(pip->exp_env[i], exp->na_val + j);
	if (!exp->buf)
		return (error(MALLOC, "0"), g_status = 1, free(exp->na_val), 1);
	free(pip->exp_env[i]);
	pip->exp_env[i] = ft_strdup(exp->buf);
	if (!pip->exp_env[i])
		return (error(MALLOC, "0"), free(exp->buf), g_status = 1, \
		free(exp->na_val), 1);
	free(exp->buf);
	return (0);
}

static int	replace_if_exp_env(t_cmd *pip, t_exp *exp, int i)
{
	exp->buf = ft_strdup(exp->na_val);
	if (!exp->buf)
		return (error(MALLOC, "0"), g_status = 1, free(exp->na_val), 1);
	free(pip->exp_env[i]);
	pip->exp_env[i] = ft_strjoin("declare -x ", exp->buf);
	if (!pip->exp_env[i])
		return (error(MALLOC, "0"), free(exp->buf), \
		g_status = 1, free(exp->na_val), 1);
	free(exp->buf);
	return (0);
}
