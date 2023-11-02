/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:04:59 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 14:54:58 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minishell.h"
#include "incs/main.h"

unsigned char	g_status;

static int	initialise_main(t_main *main, t_cmd *pip, char **env);

static int	launch_minishell(t_cmd *pip, t_main *main);

static int	prepare_prompt(t_cmd *pip, t_main *main);

int	main(int argc, char **argv, char **env)
{
	t_cmd	pip;
	t_main	main;

	(void) argv;
	(void) argc;
	if (initialise_main(&main, &pip, env) == 1)
		return (1);
	while (1)
	{
		if (launch_minishell(&pip, &main) == 1)
			return (1);
	}
	return (0);
}

static int	initialise_main(t_main *main, t_cmd *pip, char **env)
{
	main->cmd = NULL;
	main->rd_line = NULL;
	pip->here_pipe = NULL;
	pip->exp_env = NULL;
	main->rd_line = NULL;
	pip->flag = 0;
	pip->hd_history = NULL;
	pip->ani_flag = 0;
	g_status = 0;
	if (cpy_env(env, pip) == 1)
		return (1);
	if (initialize_exp_env(pip, pip->env) == 1)
		return (error(MALLOC, "0"), anihilation(pip->env), \
		anihilation(pip->save_path), 1);
	using_history();
	rl_bind_key('\t', rl_complete);
	return (0);
}

static int	launch_minishell(t_cmd *pip, t_main *main)
{
	if (prepare_prompt(pip, main) == 1)
		return (1);
	main->buff = ft_strjoin(main->buf, "$ ");
	free(main->buf);
	main->rd_line = readline(main->buff);
	free(main->buff);
	if (main->rd_line == NULL)
	{
		free(main->rd_line);
		free_all(pip);
		return (quit(), 1);
	}
	main->rd_line = verif_read(main->rd_line, pip);
	if (main->rd_line == NULL)
	{
		free_all(pip);
		exit(g_status);
	}
	free(main->cmd);
	if (historic_fct(main->rd_line, pip) == 1)
		return (free_all(pip), anihilation(pip->hd_history), \
		free(main->rd_line), 1);
	free(main->rd_line);
	return (0);
}

static int	prepare_prompt(t_cmd *pip, t_main *main)
{
	int	i;

	pip->status_hd = 0;
	main_signals();
	if (pip->hd_history != NULL)
	{
		anihilation(pip->hd_history);
		pip->hd_history = NULL;
	}
	i = 0;
	pip->nb_proc = 0;
	main->buf = getcwd(NULL, 0);
	if (!main->buf)
	{
		if (chdir("/") == -1)
			return (perror("Error "), 1);
		while (pip->save_path[i])
		{
			if (chdir(pip->save_path[i]) == -1)
				return (perror("Error "), 1);
			i++;
		}
		main->buf = getcwd(NULL, 0);
	}
	return (0);
}
