/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:21:39 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 16:58:59 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	unset_env(t_cmd *pip, char *name_value, int len);
static int	unset_exp_env(t_cmd *pip, char *name_value, int len);
static int	unset_bis(t_cmd *pip, char *name_value, int *i, \
int *trigger);

int	unset(t_cmd *pip, char *name_value)
{
	int	i;
	int	trigger;

	if (unset_bis(pip, name_value, &i, &trigger) == 0)
		return (0);
	i = 0;
	while (pip->exp_env[i])
	{
		if (ft_strncmp(pip->exp_env[i] + 11, name_value, \
		count_name_env(pip->exp_env[i] + 11) - 1) == 0 && \
		(count_name_env(pip->exp_env[i] + 11) == count_name_env(name_value)))
			trigger++;
		i++;
	}
	if (trigger == 0)
	{
		pip->builtin = TRUE;
		return (0);
	}
	else
		if (unset_env(pip, name_value, i) == 1)
			return (1);
	if (unset_exp_env(pip, name_value, i) == 1)
		return (1);
	return (0);
}

static int	unset_bis(t_cmd *pip, char *name_value, int *i, int *trigger)
{
	*i = 0;
	*trigger = 0;
	if (name_value[0] == '-')
		return (ft_printf_fd(2, "Error : invalid option\n"), \
		g_status = 2, 0);
	if (name_value[0] == '\0' || ft_isdigit(name_value[0]) == 1)
		return (ft_printf_fd(2, "Error : not a valid identifier\n"), \
		g_status = 1, 0);
	while (name_value[*i] && (ft_isalnum(name_value[*i]) == 1 \
	|| name_value[*i] == '_'))
		(*i)++;
	if (name_value[*i] != '\0')
		return (ft_printf_fd(2, "Error : not a valid identifier\n"), \
		g_status = 1, 0);
	*i = 0;
	while (pip->env[*i])
	{
		if (ft_strncmp(pip->env[*i], name_value, \
count_name_env(pip->env[*i]) - 1) == 0 && (count_name_env(pip->env[*i]) \
	== count_name_env(name_value)))
			(*trigger)++;
		(*i)++;
	}
	return (1);
}

static int	unset_env(t_cmd *pip, char *name_value, int len)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = (char **) malloc(sizeof(char *) * (len + 1));
	if (new_env == NULL)
		return (error(MALLOC, "0"), 1);
	while (pip->env[j])
	{
		if (strncmp(pip->env[j], name_value, \
		count_name_env(pip->env[j]) - 1) == 0 && \
		(count_name_env(pip->env[j]) == count_name_env(name_value)))
			free(pip->env[j++]);
		else
			new_env[i++] = pip->env[j++];
	}
	new_env[i] = NULL;
	free(pip->env);
	pip->env = new_env;
	pip->builtin = TRUE;
	return (0);
}

static int	unset_exp_env(t_cmd *pip, char *name_value, int len)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = (char **) malloc(sizeof(char *) * (len + 1));
	if (new_env == NULL)
		return (error(MALLOC, "0"), 1);
	while (pip->exp_env[j])
	{
		if (strncmp(pip->exp_env[j] + 11, name_value, \
			count_name_env(pip->exp_env[j] + 11) - 1) == 0 && \
			(count_name_env(pip->exp_env[j] + 11) == \
			count_name_env(name_value)))
			free(pip->exp_env[j++]);
		else
			new_env[i++] = pip->exp_env[j++];
	}
	new_env[i] = NULL;
	free(pip->exp_env);
	pip->exp_env = new_env;
	pip->builtin = TRUE;
	return (0);
}
