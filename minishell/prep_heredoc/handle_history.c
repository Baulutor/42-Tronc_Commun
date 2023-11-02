/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:04 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/prep_heredoc.h"

static int	creat_hd(t_prep_hist *p, t_cmd *pip);
static int	get_hd_history(t_prep_hist *p, t_cmd *pip);
static int	load_from_history(t_prep_hist *p);

int	handle_hist(int compt, t_list *spt, t_cmd *pip)
{
	t_prep_hist	p;

	p.i = 0;
	p.tmp = spt->head;
	p.unt_lst = untail_list(spt, DEBUG);
	p.rdline = ft_split((char *) p.unt_lst->data_cell->data, '\n');
	if (p.rdline == NULL)
		return (error(SPLIT, "0"), -1);
	p.j = 0;
	p.test_buff = 0;
	while (p.i < compt)
	{
		if (creat_hd(&p, pip) == -1)
			return (-1);
		if (p.buff == NULL)
			return (p.i);
	}
	free(p.unt_lst->data_cell->data);
	free(p.unt_lst->data_cell);
	free(p.unt_lst);
	free(p.rdline);
	return (p.i - p.test_buff);
}

static int	creat_hd(t_prep_hist *p, t_cmd *pip)
{
	while (p->tmp->next != NULL && \
	((char *)(p->tmp->data_cell->data))[0] != '<'
	&& ((char *)(p->tmp->data_cell->data))[1] != '<')
		p->tmp = p->tmp->next;
	if (p->tmp->next != NULL && ((char *)(p->tmp->data_cell->data))[2] == '\0')
		p->stop = (char *) p->tmp->next->data_cell->data;
	else
		p->stop = &((char *) p->tmp->data_cell->data)[2];
	p->tmp = p->tmp->next;
	p->k = 0;
	while (p->stop[p->k] != '\n' && p->stop[p->k] != '\0')
		p->k++;
	p->stop[p->k] = '\0';
	p->buf = NULL;
	p->buff = NULL;
	p->rd_line = NULL;
	p->buff = p->rdline[p->j++];
	if (p->buff == NULL)
		return (p->i);
	if (get_hd_history(p, pip) == -1)
		return (-1);
	return (0);
}

static int	get_hd_history(t_prep_hist *p, t_cmd *pip)
{
	if (load_from_history(p) == -1)
		return (-1);
	if (p->rd_line != NULL && p->buff != NULL)
	{
		p->buf = ft_strjoin(p->buff, "\n");
		if (p->buf == NULL)
			return (error(JOIN, "0"), free(p->buff), free(p->rd_line), -1);
		free(p->buff);
		p->buff = ft_strjoin(p->rd_line, p->buf);
		if (p->buff == NULL)
			return (error(JOIN, "0"), free(p->rd_line), free(p->buf), -1);
		free(p->rd_line);
		free(p->buf);
	}
	if (p->buff == NULL)
	{
		p->test_buff++;
		p->buff = p->rd_line;
	}
	pip->hd_history[p->i] = ft_strdup(p->buff);
	free(p->buff);
	if (pip->hd_history[p->i] == NULL)
		return (anihilation(pip->hd_history), error(STRDUP, "0"), -1);
	p->i++;
	return (0);
}

static int	load_from_history(t_prep_hist *p)
{
	while (p->buff && ft_strncmp(p->stop, p->buff, ft_strlen(p->buff) + 1) != 0)
	{
		if (p->rd_line == NULL)
		{
			p->rd_line = ft_strjoin(p->buff, "\n");
			if (p->rd_line == NULL)
				return (error(JOIN, "0"), free(p->buff), free(p->buf), -1);
			free(p->buff);
		}
		else
		{
			p->buf = ft_strjoin(p->buff, "\n");
			if (p->buf == NULL)
				return (error(JOIN, "0"), free(p->buff), free(p->rd_line), -1);
			free(p->buff);
			p->buff = ft_strjoin(p->rd_line, p->buf);
			if (p->buff == NULL)
				return (error(JOIN, "0"), free(p->rd_line), free(p->buf), -1);
			free(p->rd_line);
			free(p->buf);
			p->rd_line = p->buff;
		}
		p->buff = p->rdline[p->j++];
	}
	return (0);
}
