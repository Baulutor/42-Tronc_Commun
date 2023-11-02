/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:47:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:46:21 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/export.h"

static int	check_double_exp_env(char **exp_env, char *str);
static int	check_valid_and_add_only_exp(char *na_val, t_exp *exp, t_cmd *pip);
static int	check_if_replace_exp_env_and_add(t_cmd *pip, t_exp *exp);
static int	add_to_env(int i, t_cmd *pip, t_exp *exp);

int	export(t_cmd *pip, char *name_value)
{
	t_exp	exp;
	int		i;
	int		z;

	exp.flag = 0;
	i = 0;
	exp.na_val = rm_char_exp(name_value, '"');
	if (!exp.na_val)
		return (error(MALLOC, "0"), 1);
	z = check_valid_and_add_only_exp(exp.na_val, &exp, pip);
	if (z == 1)
		return (1);
	if (z == -1)
		return (0);
	i = check_if_replace_env(&exp, pip, i, z);
	if (i == -1)
		return (1);
	if (add_to_env(i, pip, &exp) == 1)
		return (1);
	if (check_if_replace_exp_env_and_add(pip, &exp) == 1)
		return (1);
	pip->builtin = TRUE;
	free(exp.na_val);
	return (0);
}

static int	check_double_exp_env(char **exp_env, char *str)
{
	size_t	i;
	int		z;
	t_exp	flag;

	i = 0;
	while (exp_env[i])
	{
		z = pars_exp(&flag.flag, &(exp_env[i])[11]);
		if (ft_strncmp(&(exp_env[i])[11], str, z) == 0 && \
		ft_strlen(&(exp_env[i])[11]) == ft_strlen(str))
			return (1);
		i++;
	}
	return (0);
}

static int	check_valid_and_add_only_exp(char *na_val, t_exp *exp, t_cmd *pip)
{
	int	i;

	i = 0;
	if (!ft_isalpha(na_val[0]))
		return (error(NVALID, "0"), free(na_val), g_status = 1, -1);
	while (na_val[i] && na_val[i] != '=')
	{
		if (ft_isalnum(na_val[i]) != 1 && na_val[i] != '+')
			return (error(NVALID, "0"), free(na_val), g_status = 1, -1);
		i++;
	}
	i = pars_exp((&exp->flag), na_val);
	if (i == -1)
		return (g_status = 1, -1);
	if (na_val[i] == '\0' && na_val[i - 1] != '=' && exp->flag == 0)
	{
		if (check_double_exp_env(pip->exp_env, na_val) == 1)
			return (free(na_val), -1);
		if (add_exp_env(pip, na_val) == 1)
			return (free(na_val), 1);
		free(na_val);
		pip->builtin = TRUE;
		return (-1);
	}
	return (0);
}

static int	check_if_replace_exp_env_and_add(t_cmd *pip, t_exp *exp)
{
	int	i;
	int	z;
	int	j;

	i = 0;
	z = 0;
	j = pars_exp(&exp->flag, exp->na_val);
	if (pip->exp_env != NULL)
	{
		i = check_if_replace_exp_env(pip, exp, z, j);
		if (i == -2)
			return (1);
		if (i == -1)
			return (0);
		if (pip->exp_env[i] == NULL)
			if (add_exp_env(pip, exp->na_val) == 1)
				return (1);
	}
	return (0);
}

static int	add_to_env(int i, t_cmd *pip, t_exp *exp)
{
	if (!pip->env[i])
	{
		exp->new_env = malloc(sizeof(char *) * (i + 2));
		if (!exp->new_env)
			return (error(MALLOC, "0"), free(exp->na_val), g_status = 1, 1);
		i = 0;
		while (pip->env[i])
		{
			exp->new_env[i] = pip->env[i];
			i++;
		}
		exp->na_val = rm_char(exp->na_val, '+');
		if (!exp->na_val)
			return (error(MALLOC, "0"), free(exp->new_env), g_status = 1, 1);
		exp->new_env[i] = ft_strdup(exp->na_val);
		if (!exp->new_env[i])
			return (error(MALLOC, "0"), free(exp->new_env), free(exp->na_val), \
			g_status = 1, 1);
		exp->new_env[i + 1] = NULL;
		free(pip->env);
		pip->env = exp->new_env;
	}
	return (0);
}
