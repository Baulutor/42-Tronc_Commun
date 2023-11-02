/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:17:23 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/26 23:16:09 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/environement.h"

static char	**ft_cpy_env(char **env);
static int	allocate_exp_env(char **buf_env, t_cmd *pip);

int	initialize_exp_env(t_cmd *pip, char **env)
{
	int		i;
	char	**buf_env;

	i = 0;
	buf_env = ft_cpy_env(env);
	if (!buf_env)
		return (1);
	while (buf_env[i])
		i++;
	buf_env[i] = NULL;
	pip->exp_env = ft_calloc(sizeof (char *), (i + 1));
	if (!pip->exp_env)
		return (anihilation(buf_env), 1);
	if (allocate_exp_env(buf_env, pip) == 1)
		return (1);
	return (0);
}

static int	allocate_exp_env(char **buf_env, t_cmd *pip)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (buf_env[i])
	{
		z = 11 + ft_strlen(buf_env[i]);
		pip->exp_env[i] = ft_calloc(sizeof(char), (z + 1));
		if (!pip->exp_env[i])
			return (anihilation(buf_env), pip->exp_env[i] = '\0', \
			anihilation(pip->exp_env), 1);
		ft_strlcpy(pip->exp_env[i], "declare -x ", z);
		ft_strlcpy(&(pip->exp_env[i][11]), buf_env[i], \
		ft_strlen(buf_env[i]) + 1);
		i++;
	}
	pip->exp_env[i] = NULL;
	anihilation(buf_env);
	return (0);
}

static char	**ft_cpy_env(char **env)
{
	int		i;
	char	**buf_env;

	i = 0;
	while (env[i])
		i++;
	buf_env = (char **) malloc(sizeof(char *) * (i + 1));
	if (!buf_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		buf_env[i] = ft_strdup(env[i]);
		if (buf_env[i] == NULL)
			return (free(buf_env), NULL);
		i++;
	}
	buf_env[i] = NULL;
	return (buf_env);
}
