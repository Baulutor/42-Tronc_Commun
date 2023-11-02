/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_red_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:43:47 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 15:18:06 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection.h"

int	write_hd_to_pip(t_cmd *struc)
{
	t_write_hd	w;

	w.i = -1;
	w.compt = 0;
	while (struc->hd_history[struc->ind_hd][++(w.i)])
		if (struc->hd_history[struc->ind_hd][w.i] == '\n' && \
		struc->hd_history[struc->ind_hd][w.i + 1] != '\0')
			w.compt = w.i;
	w.tmp = (char *) malloc(sizeof(char) * (w.compt + 2));
	if (w.tmp == NULL)
		return (error(MALLOC, "0"), 1);
	w.i = -1;
	while (++(w.i) <= w.compt)
		w.tmp[w.i] = struc->hd_history[struc->ind_hd][w.i];
	w.tmp[w.i] = '\0';
	if (write(struc->here_pipe[1], w.tmp, ft_strlen(w.tmp)) == -1)
		return (free(w.tmp), error(WRITE, "0"), 1);
	if (close(struc->here_pipe[1]) == -1)
		return (free(w.tmp), error(CLOSE, "0"), 1);
	if (dup2(struc->here_pipe[0], STDIN_FILENO) == -1)
		return (free(w.tmp), error(DUP, "0"), 1);
	if (close(struc->here_pipe[0]) == -1)
		return (free(w.tmp), error(CLOSE, "0"), 1);
	return (free(w.tmp), 0);
}

int	redir_in_bis(t_red *r, char **arg)
{
	r->file = open(&r->buf[r->i][1], O_RDONLY);
	if (r->file == -1)
		return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
		g_status = 1, -1);
	if (dup2(r->file, STDIN_FILENO) == -1)
		return (anihilation(r->buf), anihilation(arg), close(r->file), \
		error(DUP, "0"), -1);
	close(r->file);
	return (0);
}

int	redit_append_bis(t_red *r, char **arg)
{
	r->file = open(&r->buf[r->i][2], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (r->file == -1)
		return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
		g_status = 1, -1);
	else if (dup2(r->file, STDOUT_FILENO) == -1)
		return (anihilation(r->buf), anihilation(arg), close(r->file), \
		error(DUP, "0"), -1);
	close(r->file);
	return (0);
}

int	redir_out_bis(t_red *r, char **arg)
{
	if (r->buf[r->i + 1] == NULL)
		return (anihilation(r->buf), anihilation(arg), error(TOKEN, "0"), \
		-1);
	r->file = open(r->buf[r->i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (r->file == -1)
		return (anihilation(r->buf), anihilation(arg), error(OPEN, "0"), \
		g_status = 1, -1);
	else if (dup2(r->file, STDOUT_FILENO) == -1)
		return (anihilation(r->buf), anihilation(arg), close(r->file), \
		error(DUP, "0"), -1);
	close(r->file);
	r->i++;
	return (0);
}
