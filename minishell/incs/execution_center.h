/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_center.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:29:35 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 17:10:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_CENTER_H
# define EXECUTION_CENTER_H

typedef struct t_exec
{
	char	**exec_cmd;
	int		*arg_count;
	int		statut;
	int		exit_status;
	int		id;
	int		ret;
	int		value_ret;
	char	**buf;
	int		i;
}	t_exec;

void	parent_wait_and_signal(t_exec *ex, pid_t *tab_pid, t_cmd *pip);

int		prep_pipe(t_cmd *pip);

int		checking_pipe(t_list *spt);

int		trash_and_build(t_exec *ex, t_cmd *pip);

int		handle_builtins_parent_bis(t_exec *ex, t_cmd *pip, t_list *spt);

#endif