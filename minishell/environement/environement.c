/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:26:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/29 17:13:40 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/environement.h"

static int	allocate_env(t_cmd *pip, char **env);
static int	sh_lvl_incrementation(t_env *cpy, int i, t_cmd *pip);
static int	prep_sh_lvl(int z, int i, t_cmd *pip, t_env *cpy);

int	cpy_env(char **env, t_cmd *pip)
{
	t_env	cpy;
	int		i;

	i = 0;
	pip->save_path = NULL;
	while (env[i])
		i++;
	pip->env = malloc(sizeof(char *) * (i + 1));
	if (pip->env == NULL)
	{
		return (error(MALLOC, 0), 1);
	}
	if (allocate_env(pip, env) == 1)
		return (1);
	i = 0;
	while (pip->env[i])
	{
		if (strncmp(pip->env[i], "SHLVL=", 6) == 0)
		{
			if (sh_lvl_incrementation(&cpy, i, pip) == 1)
				return (1);
		}
		i ++;
	}
	return (0);
}

static int	allocate_env(t_cmd *pip, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			pip->save_path = ft_split(&(env[i])[4], '/');
			if (!pip->save_path)
				return (error(MALLOC, "0"), pip->env[i] = '\0', \
				anihilation(pip->env), 1);
		}
		pip->env[i] = ft_strdup(env[i]);
		if (pip->env[i] == NULL)
		{
			if (pip->save_path)
				anihilation(pip->save_path);
			return (error(MALLOC, "0"), pip->env[i] = '\0', \
			anihilation(pip->env), 1);
		}
		i++;
	}
	pip->env[i] = NULL;
	return (0);
}

static int	sh_lvl_incrementation(t_env *cpy, int i, t_cmd *pip)
{
	int	z;

	z = 0;
	if (prep_sh_lvl(z, i, pip, cpy) == 1)
		return (anihilation(pip->save_path), 1);
	cpy->buf = malloc(sizeof(char) * (ft_strlen(cpy->sh_lvl) + 7));
	if (!cpy->buf)
		return (free(cpy->sh_lvl), anihilation(pip->env), \
		anihilation(pip->save_path), 1);
	ft_strlcpy(cpy->buf, "SHLVL=", 7);
	ft_strlcat(cpy->buf, cpy->sh_lvl, ft_strlen(cpy->sh_lvl) + 7);
	free(cpy->sh_lvl);
	if (export(pip, cpy->buf) == 1)
		return (anihilation(pip->env), anihilation(pip->save_path), \
		free(cpy->buf), 1);
	free(cpy->buf);
	return (0);
}

static int	prep_sh_lvl(int z, int i, t_cmd *pip, t_env *cpy)
{
	while ((pip->env[i][z] >= 'A' && pip->env[i][z] <= 'Z') \
	|| pip->env[i][z] == '=')
		z++;
	cpy->for_sh = ft_atoi(&pip->env[i][z]);
	cpy->for_sh += 1;
	if (cpy->for_sh > 1000)
	{
		cpy->for_sh = 1;
		ft_printf_fd(2, "warning : shell level (1000) too high, \
		resetting to 1\n");
	}
	cpy->sh_lvl = ft_itoa(cpy->for_sh);
	if (!cpy->sh_lvl)
		return (anihilation(pip->env), error(MALLOC, "0"), 1);
	return (0);
}
