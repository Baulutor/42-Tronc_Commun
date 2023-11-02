/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_center_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:01:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 17:30:21 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/execution_center.h"

void	parent_wait_and_signal(t_exec *ex, pid_t *tab_pid, t_cmd *pip)
{
	if (ex->id != 0)
		free(ex->arg_count);
	if (pip->nb_pipe > 0)
		close_all_pipes(pip);
	ex->i = pip->parent_builtin;
	while (ex->i < pip->nb_proc)
	{
		waitpid(tab_pid[ex->i], &ex->statut, 0);
		ex->i++;
	}
	free(tab_pid);
	if (pip->parent_builtin == FALSE && pip->builtin == FALSE && ex->ret != 1)
	{
		if (WIFSIGNALED(ex->statut))
		{
			if (WTERMSIG(ex->statut) == SIGINT)
				hsigint_exec(SIGINT);
			else if (WTERMSIG(ex->statut) == SIGQUIT)
				hsigquit(SIGQUIT);
			ex->exit_status = 128 + WTERMSIG(ex->statut);
		}
		else if (WIFEXITED(ex->statut))
			ex->exit_status = WEXITSTATUS(ex->statut);
		g_status = ex->exit_status;
	}
}

int	trash_and_build(t_exec *ex, t_cmd *pip)
{
	int	i;

	i = 0;
	while (ex->exec_cmd[i])
	{
		ex->exec_cmd[i] = trash_quote_buil_exec(ex->exec_cmd[i]);
		if (ex->exec_cmd == NULL)
			return (error(MALLOC, "0"), anihilation(ex->exec_cmd), 1);
		i++;
	}
	if (pip->nb_proc > 1)
	{
		if (ex->i > 0 && pip->in == FALSE)
			if (dup2(pip->pipe[ex->i - 1][0], STDIN_FILENO) == -1)
				return (1);
		if (ex->i < pip->nb_pipe && pip->out == FALSE)
			if (dup2(pip->pipe[ex->i][1], STDOUT_FILENO) == -1)
				return (1);
		close_all_pipes(pip);
	}
	return (0);
}

int	handle_builtins_parent_bis(t_exec *ex, t_cmd *pip, t_list *spt)
{
	if (ex->buf == NULL)
		return (free(ex->arg_count), annihilation(spt, free, DEBUG), 1);
	free(pip->here_pipe);
	ex->value_ret = parent_builtins(pip, ex->buf);
	if (ex->value_ret == -1)
		return (annihilation(spt, free, DEBUG), free(ex->arg_count), \
		anihilation(ex->buf), 1);
	anihilation(ex->buf);
	pip->ind_hd = -1;
	return (0);
}
