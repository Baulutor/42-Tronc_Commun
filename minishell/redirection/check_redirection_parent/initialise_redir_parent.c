/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_redir_parent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:10:04 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:53:50 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection_parent.h"

static int	allocate_new_buf(char **arg, int i, t_red_par *red);

int	initialise_redir_parent(t_red_par *red, char **arg, t_cmd *struc)
{
	int	i;

	i = 0;
	struc->in = FALSE;
	struc->out = FALSE;
	if (check_heredoc(arg, struc) == 1)
		return (anihilation(arg), anihilation(struc->hd_history), 1);
	while (arg[i])
		i++;
	red->buf = malloc(sizeof(char *) * (i + 1));
	if (!red->buf)
		return (1);
	i = 0;
	while (arg[i])
	{
		if (allocate_new_buf(arg, i, red) == 1)
			return (1);
		i++;
	}
	red->buf[i] = NULL;
	anihilation(arg);
	return (0);
}

static int	allocate_new_buf(char **arg, int i, t_red_par *red)
{
	if (arg[i][0] == '"' || arg[i][0] == '\'')
	{
		red->buf[i] = ft_strdup(arg[i]);
		if (!red->buf[i])
			return (error(MALLOC, "0"), red->buf[i] = '\0', \
			anihilation(arg), anihilation(red->buf), 1);
	}
	else
	{
		red->buf[i] = trash_quote(arg[i]);
		if (!red->buf[i])
			return (error(MALLOC, "0"), red->buf[i] = '\0', \
			anihilation(arg), anihilation(red->buf), 1);
	}
	return (0);
}
