/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 16:00:13 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection.h"

static int	init_redirection(t_red *r, char **arg, t_cmd *struc);
static void	creat_tab(t_red *r, char **arg);
static void	fill_tab(t_red *r, char **arg);

char	**check_redirection(char **arg, t_cmd *struc)
{
	t_red	r;

	if (init_redirection(&r, arg, struc) == -1)
		return (NULL);
	if (duplication(&r, arg, struc) == -1)
		return (NULL);
	anihilation(r.buf);
	if (struc->in == FALSE && struc->out == FALSE)
		return (arg);
	if (struc->heredoc == 1)
		if (write_hd_to_pip(struc) == 1)
			return (anihilation(arg), NULL);
	creat_tab(&r, arg);
	r.tmp = (char **) malloc(sizeof(char *) * (r.compt + 1));
	if (r.tmp == NULL)
		return (error(MALLOC, "0"), anihilation(arg), g_status = 1, NULL);
	r.i = 0;
	r.j = 0;
	fill_tab(&r, arg);
	free(arg);
	arg = r.tmp;
	arg[r.j] = NULL;
	return (arg);
}

static int	init_redirection(t_red *r, char **arg, t_cmd *struc)
{
	r->i = 0;
	struc->in = FALSE;
	struc->out = FALSE;
	if (check_heredoc(arg, struc) == 1)
		return (-1);
	while (arg[r->i])
		r->i++;
	r->buf = malloc(sizeof(char *) * (r->i + 1));
	r->i = 0;
	while (arg[r->i])
	{
		if (arg[r->i][0] == '"' || arg[r->i][0] == '\'')
			r->buf[r->i] = ft_strdup(arg[r->i]);
		else
			r->buf[r->i] = trash_quote(arg[r->i]);
		r->i++;
	}
	r->buf[r->i] = NULL;
	r->i = 0;
	return (0);
}

static void	creat_tab(t_red *r, char **arg)
{
	r->i = 0;
	r->compt = 0;
	while (arg[r->i])
	{
		if (arg[r->i][0] == '<')
		{
			r->compt--;
			if (arg[r->i][1] == '\0' || (arg[r->i][1] == '<' \
			&& arg[r->i][2] == '\0'))
				r->i += 1;
		}
		else if (arg[r->i][0] == '>')
		{
			r->compt--;
			if (arg[r->i][1] == '\0' || (arg[r->i][1] == '>' \
			&& arg[r->i][2] == '\0'))
				r->i += 1;
		}
		r->i++;
		r->compt++;
	}
}

static void	fill_tab(t_red *r, char **arg)
{
	while (arg[r->i])
	{
		if (arg[r->i][0] == '<')
		{
			if (arg[r->i][1] == '\0' || (arg[r->i][1] == '<' \
			&& arg[r->i][2] == '\0'))
				free(arg[r->i++]);
			free(arg[r->i]);
		}
		else if (arg[r->i][0] == '>')
		{
			if (arg[r->i][1] == '\0' || (arg[r->i][1] == '>' \
			&& arg[r->i][2] == '\0'))
				free(arg[r->i++]);
			free(arg[r->i]);
		}
		else
			r->tmp[r->j++] = arg[r->i];
		r->i++;
	}
}
