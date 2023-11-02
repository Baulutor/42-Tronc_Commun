/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_replace_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:46:28 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:46:12 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/export.h"

static int	check_same_if_plus_env(int j, t_exp *exp, int i, t_cmd *pip);
static int	replace_value_env(t_cmd *pip, t_exp *exp, int z, int i);

int	check_if_replace_env(t_exp *exp, t_cmd *pip, int i, int j)
{
	int		z;
	int		res;

	j = pars_exp(&exp->flag, exp->na_val);
	i = 0;
	while (pip->env[i])
	{
		z = pars_exp(&exp->flag, pip->env[i]);
		if (exp->flag == 1)
		{
			if (strcmp_plus(pip->env[i], exp->na_val, z + 1) == 0)
			{
				if (check_same_if_plus_env(j, exp, i, pip) == -1)
					return (-1);
				break ;
			}
		}
		res = replace_value_env(pip, exp, z, i);
		if (res == -1)
			return (-1);
		if (res != 0)
			break ;
		i++;
	}
	return (i);
}

static int	check_same_if_plus_env(int j, t_exp *exp, int i, t_cmd *pip)
{
	int	z;

	exp->na_val = rm_char(exp->na_val, '+');
	if (exp->na_val == NULL)
		return (error(MALLOC, "0"), free(exp->na_val), -1);
	j = pars_exp(&exp->flag, exp->na_val);
	j++;
	z = ft_strlen(exp->na_val + j) + ft_strlen(pip->env[i]);
	exp->buf = malloc(sizeof(char) * (z + 1));
	if (!exp->buf)
		return (error(MALLOC, "0"), free(exp->na_val), -1);
	ft_strlcpy(exp->buf, pip->env[i], ft_strlen(pip->env[i]) + 1);
	ft_strlcat(exp->buf, exp->na_val + j, z + 1);
	free(pip->env[i]);
	pip->env[i] = ft_strdup(exp->buf);
	free(exp->buf);
	if (!pip->env[i])
		return (error(MALLOC, "0"), free(exp->na_val), -1);
	return (0);
}

static int	replace_value_env(t_cmd *pip, t_exp *exp, int z, int i)
{
	if (ft_strncmp(pip->env[i], exp->na_val, z + 1) == 0)
	{
		free(pip->env[i]);
		pip->env[i] = ft_strdup(exp->na_val);
		if (pip->env[i] == NULL)
			return (error(MALLOC, "0"), free(exp->na_val), g_status = 1, -1);
		return (2);
	}
	return (0);
}
