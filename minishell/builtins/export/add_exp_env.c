/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exp_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:41:55 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:46:26 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/export.h"

static int	check_if_exist_exp_env(t_cmd *pip, int *flag, char *buf);
static int	allocate_new_exp_env(t_cmd *pip, int i, char ***new_one, int flag);
static void	closing_new_one(int flag, char *buf, char ***new_one, int i);
static int	put_in_new_exp_env(t_cmd *pip, char *buf, char **new_one, \
int *flag);

int	add_exp_env(t_cmd *pip, char *str)
{
	int		i;
	char	*buf;
	char	**new_one;
	int		flag;

	new_one = NULL;
	buf = malloc(sizeof(char) * (ft_strlen(str) + 12));
	if (!buf)
		return (g_status = 1, 1);
	ft_strlcpy(buf, "declare -x ", 12);
	ft_strlcpy(&(buf[11]), str, ft_strlen(str) + 1);
	flag = 0;
	i = check_if_exist_exp_env(pip, &flag, buf);
	if (i == -1)
		return (0);
	if (allocate_new_exp_env(pip, i, &new_one, flag) == 1)
		return (free(buf), 1);
	i = put_in_new_exp_env(pip, buf, new_one, &flag);
	if (i == -1)
		return (1);
	closing_new_one(flag, buf, &new_one, i);
	anihilation(pip->exp_env);
	pip->exp_env = new_one;
	sort_export(pip);
	return (0);
}

static int	check_if_exist_exp_env(t_cmd *pip, int *flag, char *buf)
{
	int	i;

	i = 0;
	while (pip->exp_env[i])
	{
		if (strncmp(buf, pip->exp_env[i], ft_strlen(buf) + 1) == 0 && \
		ft_in('=', buf) == 1)
			return (free(buf), -1);
		else if (strncmp(buf, pip->exp_env[i], ft_strlen(buf)) == 0 \
		&& ft_in('=', buf) == 0 && pip->exp_env[i][ft_strlen(buf)] == '=')
			return (free(buf), -1);
		if (ft_in('=', buf) == 1 && strncmp(buf, pip->exp_env[i], \
		ft_strlen(pip->exp_env[i])) == 0)
			*flag = 1;
		i++;
	}
	return (i);
}

static int	allocate_new_exp_env(t_cmd *pip, int i, char ***new_one, int flag)
{
	while (pip->exp_env[i])
		i++;
	if (flag == 0)
		*new_one = malloc(sizeof(char *) * (i + 2));
	else
		*new_one = malloc(sizeof(char *) * (i + 1));
	if (*new_one == NULL)
	{
		return (error(MALLOC, "0"), 1);
	}
	return (0);
}

static void	closing_new_one(int flag, char *buf, char ***new_one, int i)
{
	if (flag == 0)
	{
		new_one[0][i] = buf;
		new_one[0][i + 1] = NULL;
	}
	else
	{
		new_one[0][i] = NULL;
		free(buf);
	}
}

static int	put_in_new_exp_env(t_cmd *pip, char *buf, char **new_one, int *flag)
{
	int	i;

	i = 0;
	while (pip->exp_env[i])
	{
		if (ft_in('=', buf) == 1 && strncmp(buf, pip->exp_env[i], \
		ft_strlen(pip->exp_env[i])) == 0)
		{
			new_one[i] = ft_strdup(buf);
			if (!new_one[i])
				return (new_one[i] = '\0', anihilation(new_one), \
				error(MALLOC, "0"), free(buf), -1);
			*flag = 1;
		}
		else
		{
			new_one[i] = ft_strdup(pip->exp_env[i]);
			if (!new_one[i])
				return (new_one[i] = '\0', anihilation(new_one), \
				error(MALLOC, "0"), free(buf), -1);
		}
		i++;
	}
	return (i);
}
