/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/29 16:21:40 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/verif_read.h"

static int	init_lst_verif_read(t_list **spt);
static int	still_quote(t_verif *verif, char *rd_line, t_cmd *pip, t_list *spt);
static int	init_verif_read(char **line, t_verif *vr, t_cmd *pip, t_list *spt);
static char	*check_vr_read(t_list *spt, char *rd_line, t_cmd *pip, t_verif *vr);

char	*verif_read(char *rd_line, t_cmd *pip)
{
	t_verif	verif;
	t_list	*spt;

	verif.flag = 0;
	verif.buf = NULL;
	spt = NULL;
	if (init_lst_verif_read(&spt) == 1)
		return (g_status = 1, NULL);
	if (rd_line[0] == '|')
		return (error(SYNTAX, "|"), g_status = 2, \
		annihilation(spt, free, DEBUG), rd_line);
	if (init_verif_read(&rd_line, &verif, pip, spt) == 1)
		return (g_status = 1, NULL);
	if (check_expand(rd_line) == 1)
		return (annihilation(spt, free, DEBUG), free(rd_line), \
		verif.buff);
	if (parsing(rd_line, &verif.flag, spt) == 1)
		return (g_status = 1, free(rd_line), free(verif.buff), NULL);
	free(rd_line);
	if (check_vr_read(spt, rd_line, pip, &verif) == NULL)
		return (NULL);
	return (verif.buff);
}

static int	init_lst_verif_read(t_list **spt)
{
	*spt = (t_list *) malloc(sizeof(t_list));
	if (*spt == NULL)
		return (error(MALLOC, "0"), 1);
	init_list(*spt);
	return (0);
}

static int	init_verif_read(char **line, t_verif *vr, t_cmd *pip, t_list *spt)
{
	vr->buff = ft_strdup(*line);
	if (vr->buff == NULL)
		return (error(MALLOC, "0"), annihilation(spt, free, DEBUG), 1);
	vr->expand_flag = 0;
	*line = expand(*line, pip, &vr->expand_flag);
	if (*line == NULL)
		return (free(vr->buff), annihilation(spt, free, DEBUG), 1);
	return (0);
}

static char	*check_vr_read(t_list *spt, char *rd_line, t_cmd *pip, t_verif *vr)
{
	if (spt->len == 0)
		return (annihilation(spt, free, DEBUG), vr->buff);
	if (still_quote(vr, rd_line, pip, spt) == 1)
		return (NULL);
	if (check_arg(spt) == 1)
		return (annihilation(spt, free, DEBUG), vr->buff);
	vr->flag = execution_center(spt, pip);
	if (vr->flag == 1)
		return (free(vr->buff), NULL);
	else if (vr->flag == -1)
		return (free(vr->buff), NULL);
	annihilation(spt, free, DEBUG);
	return (vr->buff);
}

static int	still_quote(t_verif *verif, char *rd_line, t_cmd *pip, t_list *spt)
{
	while (verif->flag == 1 || verif->flag == 2)
	{
		rd_line = readline("> ");
		verif->save = ft_strdup(rd_line);
		rd_line = expand(rd_line, pip, &verif->expand_flag);
		if (rd_line == NULL)
			return (annihilation(spt, free, DEBUG), 1);
		if (verif->save == NULL)
			return (error(MALLOC, "0"), annihilation(spt, free, DEBUG), 1);
		parsing(rd_line, &verif->flag, spt);
		free(rd_line);
		verif->buf = ft_strjoin(verif->buff, "\n");
		if (verif->buf == NULL)
			return (error(MALLOC, "0"), annihilation(spt, free, DEBUG), 1);
		free(verif->buff);
		verif->buff = ft_strjoin(verif->buf, verif->save);
		free(verif->save);
		if (verif->buff == NULL)
			return (error(MALLOC, "0"), annihilation(spt, free, DEBUG), 1);
		free(verif->buf);
	}
	return (0);
}
