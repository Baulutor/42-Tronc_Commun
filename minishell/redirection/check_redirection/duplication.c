/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:53:17 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 14:37:08 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection.h"

static int	redir_in(t_red *r, char **arg, t_cmd *s);
static int	redir_append(t_red *r, char **arg);
static int	redir_out(t_red *r, char **arg);

int	duplication(t_red *r, char **arg, t_cmd *s)
{
	while (arg[r->i])
	{
		if (r->buf[r->i][0] == '<')
		{
			if (redir_in(r, arg, s) == -1)
				return (-1);
		}
		else if (r->buf[r->i][0] == '>')
		{
			s->out = TRUE;
			if (redir_out(r, arg) == -1)
				return (-1);
		}
		r->i++;
	}
	return (0);
}

static int	redir_in(t_red *r, char **arg, t_cmd *s)
{
	s->in = TRUE;
	if (r->buf[r->i][1] == '\0')
	{
		if (r->buf[r->i + 1] == NULL)
			return (anihilation(r->buf), anihilation(arg), error(TOKEN, "0"), \
			-1);
		r->file = open(r->buf[r->i + 1], O_RDONLY);
		if (r->file == -1)
			return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
			g_status = 1, -1);
		else if (dup2(r->file, STDIN_FILENO) == -1)
			return (anihilation(r->buf), anihilation(arg), close(r->file), \
			error(DUP, "0"), -1);
		close(r->file);
		r->i++;
	}
	else if (r->buf[r->i][1] == '<' && r->buf[r->i][2] == '\0')
		r->i++;
	else if (r->buf[r->i][1] != '<' || r->buf[r->i][2] == '\0')
		if (redir_in_bis(r, arg) == -1)
			return (-1);
	return (0);
}

static int	redir_append(t_red *r, char **arg)
{
	if (r->buf[r->i][2] == '\0')
	{
		if (r->buf[r->i + 1] == NULL)
			return (anihilation(r->buf), anihilation(arg), error(TOKEN, "0"), \
			-1);
		r->file = open(r->buf[r->i + 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (r->file == -1)
			return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
			g_status = 1, -1);
		else if (dup2(r->file, STDOUT_FILENO) == -1)
			return (anihilation(r->buf), anihilation(arg), close(r->file), \
			error(DUP, "0"), -1);
		close(r->file);
		r->i++;
	}
	else
		if (redit_append_bis(r, arg) == -1)
			return (-1);
	return (0);
}

static int	redir_out(t_red *r, char **arg)
{
	if (r->buf[r->i][1] == '\0')
	{
		if (redir_out_bis(r, arg) == -1)
			return (-1);
	}
	else if (r->buf[r->i][1] == '>')
	{
		if (redir_append(r, arg) == -1)
			return (-1);
	}
	else
	{
		r->file = open(&r->buf[r->i][1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (r->file == -1)
			return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
			g_status = 1, -1);
		else if (dup2(r->file, STDOUT_FILENO) == -1)
			return (anihilation(r->buf), anihilation(arg), close(r->file), \
			error(DUP, "0"), -1);
		close(r->file);
	}
	return (0);
}
