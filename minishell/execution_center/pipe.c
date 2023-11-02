/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:02:48 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:07:30 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/execution_center.h"

int	checking_pipe(t_list *spt)
{
	int		count;
	t_cell	*tmp;

	count = 1;
	tmp = spt->head;
	while (tmp != NULL)
	{
		if (((char *)(tmp->data_cell->data))[0] == '|')
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	prep_pipe(t_cmd *pip)
{
	int	i;

	i = 0;
	pip->pipe = (int **) ft_calloc(pip->nb_pipe, sizeof(int *));
	if (pip->pipe == NULL)
	{
		return (1);
	}
	while (i < pip->nb_pipe)
	{
		pip->pipe[i] = (int *)ft_calloc(2, sizeof(int));
		if (pip->pipe[i] == NULL)
		{
			pip->nb_pipe = i;
			return (error(CALLOC, "0"), close_all_pipes(pip), 1);
		}
		if (pipe(pip->pipe[i]) == -1)
		{
			pip->nb_pipe = i;
			return (close_all_pipes(pip), error(PIPE, NULL), 1);
		}
		i++;
	}
	return (0);
}
