/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 09:35:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/prep_heredoc.h"

static int	creat_hd(t_prep *p, t_cmd *pip, t_list *spt);
static int	demanding_user(t_prep *p, t_cmd *pip);
static int	get_hd(t_prep *p);

char	**prep_hd(t_cmd *pip, t_list *spt)
{
	t_prep	p;

	p.tmp = spt->head;
	search_hd(&p);
	if (p.compt != 0)
		pip->hd_history = (char **) ft_calloc(p.compt + 1, sizeof(char *));
	if (pip->hd_history == NULL && p.compt != 0)
		return (pip->status_hd = 2, g_status = 1, NULL);
	if (pip->hd_history == NULL)
		return (NULL);
	p.i = 0;
	while (((char *) spt->tail->data_cell->data)[p.i] != '\n' \
	&& ((char *) spt->tail->data_cell->data)[p.i] != '\0')
		p.i++;
	if (((char *) spt->tail->data_cell->data)[p.i] == '\n')
		p.i = handle_hist(p.compt, spt, pip);
	else
		p.i = 0;
	p.tmp = spt->head;
	while (p.i < p.compt)
		if (creat_hd(&p, pip, spt) == 1)
			return (pip->status_hd = 2, anihilation(pip->hd_history), NULL);
	pip->hd_history[p.i] = NULL;
	pip->ind_hd = -1;
	return (pip->hd_history);
}

static int	creat_hd(t_prep *p, t_cmd *pip, t_list *spt)
{
	while (p->tmp != NULL && ((char *)(p->tmp->data_cell->data))[0] != '<' \
	&& ((char *)(p->tmp->data_cell->data))[1] != '<')
		p->tmp = p->tmp->next;
	if (((char *)(p->tmp->data_cell->data))[2] == '\0' && p->tmp->next == NULL)
		return (annihilation(spt, free, DEBUG), error(SYNTAX, "newline"), \
		g_status = 2, 1);
	if (((char *)(p->tmp->data_cell->data))[2] == '\0')
		p->stop = (char *) p->tmp->next->data_cell->data;
	else
		p->stop = &(((char *) p->tmp->data_cell->data)[2]);
	p->tmp = p->tmp->next;
	p->j = 0;
	while (p->stop[p->j] != '\n' && p->stop[p->j] != '\0')
		p->j++;
	p->stop[p->j] = '\0';
	p->buf = NULL;
	p->buff = NULL;
	p->rd_line = pip->hd_history[p->i];
	p->buff = readline("> ");
	if (demanding_user(p, pip) == 1)
		return (1);
	pip->hd_history[p->i] = ft_strdup(p->buff);
	free(p->buff);
	p->i++;
	return (0);
}

static int	demanding_user(t_prep *p, t_cmd *pip)
{
	while (p->buff != NULL && g_status != 130 \
	&& ft_strncmp(p->stop, p->buff, ft_strlen(p->buff) + 1) != 0)
		if (get_hd(p) == 1)
			return (1);
	if (verif_status_hd(p, pip) == 1)
		return (1);
	if (p->rd_line != NULL)
	{
		p->buf = ft_strjoin(p->buff, "\n");
		if (p->buf == NULL)
			return (error(JOIN, "0"), free(p->buff), free(p->rd_line), 1);
		free(p->buff);
		p->buff = ft_strjoin(p->rd_line, p->buf);
		if (p->buff == NULL)
			return (error(JOIN, "0"), free(p->rd_line), free(p->buf), 1);
		free(p->rd_line);
		free(p->buf);
	}
	return (0);
}

static int	get_hd(t_prep *p)
{
	if (ft_strncmp(p->stop, p->buff, ft_strlen(p->buff) + 1) == 0)
		return (0);
	if (p->rd_line == NULL)
	{
		p->rd_line = ft_strjoin(p->buff, "\n");
		if (p->rd_line == NULL)
			return (error(JOIN, "0"), free(p->buff), free(p->buf), 1);
		free(p->buff);
	}
	else
	{
		p->buf = ft_strjoin(p->buff, "\n");
		if (p->buf == NULL)
			return (error(JOIN, "0"), free(p->buff), free(p->rd_line), 1);
		free(p->buff);
		p->buff = ft_strjoin(p->rd_line, p->buf);
		if (p->buff == NULL)
			return (error(JOIN, "0"), free(p->rd_line), free(p->buf), 1);
		free(p->rd_line);
		free(p->buf);
		p->rd_line = p->buff;
	}
	p->buff = readline("> ");
	return (0);
}
