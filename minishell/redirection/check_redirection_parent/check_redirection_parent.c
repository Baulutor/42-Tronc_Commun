/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection_parent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:50:36 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 16:43:48 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../incs/check_redirection_parent.h"

static int	allocate_tmp_char(t_red_par *red);
static int	fill_tmp(int *j, t_red_par *red);
static int	count_for_tmp(int *i, int *j, t_red_par *red);

char	**check_redirection_parent(char **arg, t_cmd *struc)
{
	t_red_par	red;
	int			j;

	if (initialise_redir_parent(&red, arg, struc) == 1)
		return (NULL);
	if (search_open_file(&red, struc) == 1)
		return (struc->flag = 1, NULL);
	if (struc->heredoc == 1)
		if (write_hd_to_pip_par(struc) == 1)
			return (anihilation(red.buf), anihilation(struc->hd_history), \
			free(struc->here_pipe), NULL);
	red.compt = 0;
	if (allocate_tmp_char(&red) == 1)
		return (anihilation(red.buf), NULL);
	j = 0;
	if (fill_tmp(&j, &red) == 1)
		return (NULL);
	anihilation(red.buf);
	red.tmp[j] = NULL;
	if (j == 0)
		return (struc->flag = 1, free(struc->here_pipe), \
		anihilation(red.tmp), NULL);
	return (red.tmp);
}

static int	fill_tmp(int *j, t_red_par *red)
{
	int	i;

	i = -1;
	while (red->buf[++i])
	{
		if (count_for_tmp(&i, j, red) == 1)
			return (1);
	}
	return (0);
}

static int	count_for_tmp(int *i, int *j, t_red_par *red)
{
	if (red->buf[*i][0] == '<')
	{
		if (red->buf[*i][1] == '\0' || (red->buf[*i][1] == '<' \
		&& red->buf[*i][2] == '\0'))
			*i += 1;
	}
	else if (red->buf[*i][0] == '>')
	{
		if (red->buf[*i][1] == '\0' || (red->buf[*i][1] == '>' \
		&& red->buf[*i][2] == '\0'))
			*i += 1;
	}
	else
	{
		red->tmp[*j] = ft_strdup(red->buf[*i]);
		if (red->tmp[*j] == NULL)
			return (error(MALLOC, "0"), anihilation(red->buf), \
			red->tmp[*j] = '\0', anihilation(red->tmp), 1);
		*j += 1;
	}
	return (0);
}

static int	allocate_tmp_char(t_red_par *red)
{
	int	i;

	i = -1;
	while (red->buf[++i])
	{
		if (red->buf[i][0] == '<')
		{
			red->compt--;
			if (red->buf[i][1] == '\0' || (red->buf[i][1] == '<' && \
			red->buf[i][2] == '\0'))
				i += 1;
		}
		else if (red->buf[i][0] == '>')
		{
			red->compt--;
			if (red->buf[i][1] == '\0' || (red->buf[i][1] == '>' && \
			red->buf[i][2] == '\0'))
				i += 1;
		}
		red->compt++;
	}
	red->tmp = (char **) malloc(sizeof(char *) * (red->compt + 1));
	if (!red->tmp)
		return (error(MALLOC, "0"), 1);
	return (0);
}
