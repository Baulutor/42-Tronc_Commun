/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_check_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:05:08 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:53:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection_parent.h"

static int	write_and_close_hd_pip(t_cmd *struc, char *tmp);

int	write_hd_to_pip_par(t_cmd *struc)
{
	int		i;
	int		compt;
	char	*tmp;

	i = -1;
	compt = 0;
	while (struc->hd_history[struc->ind_hd][++i])
	{
		if (struc->hd_history[struc->ind_hd][i] == '\n' && \
		struc->hd_history[struc->ind_hd][i + 1] != '\0')
			compt = i;
	}
	tmp = (char *) malloc(sizeof(char) * (compt + 2));
	if (tmp == NULL)
		return (error(MALLOC, "0"), 1);
	i = -1;
	while (++i <= compt)
		tmp[i] = struc->hd_history[struc->ind_hd][i];
	tmp[i] = '\0';
	if (write_and_close_hd_pip(struc, tmp) == 1)
		return (1);
	free(tmp);
	return (0);
}

static int	write_and_close_hd_pip(t_cmd *struc, char *tmp)
{
	if (write(struc->here_pipe[1], tmp, ft_strlen(tmp)) == -1)
		return (free(tmp), error(WRITE, "0"), 1);
	if (close(struc->here_pipe[1]) == -1)
		return (free(tmp), error(CLOSE, "0"), 1);
	if (close(struc->here_pipe[0]) == -1)
	{
		return (free(tmp), error(CLOSE, "0"), 1);
	}
	return (0);
}

// This function should set up the heredoc pipe if necessary.
// To find out, check if the last redirection is a heredoc or not
int	check_heredoc(char **arg, t_cmd *struc)
{
	int	i;

	i = -1;
	struc->heredoc = 0;
	while (arg[++i])
	{
		if (arg[i][0] == '<')
		{
			if (arg[i][1] == '<')
			{
				struc->ind_hd++;
				struc->heredoc = 1;
			}
			else
				struc->heredoc = 0;
		}
	}
	if (struc->heredoc == 0)
		return (0);
	struc->here_pipe = (int *)ft_calloc(2, sizeof(int));
	if (struc->here_pipe != NULL && pipe(struc->here_pipe) == -1)
		return (error(PIPE, "0"), free(struc->here_pipe), 1);
	else if (struc->here_pipe == NULL)
		return (error(CALLOC, "0"), 1);
	return (0);
}
