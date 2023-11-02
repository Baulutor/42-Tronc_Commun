/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:30:24 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/30 09:27:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/historic.h"

static void	check_quote_historic(t_hist *his, char *rd_line);
static int	put_in_historic(t_cmd *pip, t_hist *his, char *rd_line);
static void	renitialize_buf_tmp(t_hist *his);

int	historic_fct(char *rd_line, t_cmd *pip)
{
	int		i;
	t_hist	his;

	i = 0;
	his.save = 0;
	check_quote_historic(&his, rd_line);
	if (his.save != 0)
		his.flag = 1;
	i = his.save;
	while (rd_line[i] != '\n' && rd_line[i] != '\0')
		i++;
	if (rd_line[i] == '\n')
		his.flag = 1;
	rd_line[i] = '\0';
	if (put_in_historic(pip, &his, rd_line) == 1)
		return (1);
	if (his.tmp[0] != '\0')
		add_history(his.tmp);
	if (his.tmp != rd_line)
		free(his.tmp);
	return (0);
}

static void	check_quote_historic(t_hist *his, char *rd_line)
{
	int	i;

	i = 0;
	his->flag = 0;
	while (rd_line[i] != '\0')
	{
		if (rd_line[i] == '"' && his->flag == 0)
			his->flag = 1;
		else if (rd_line[i] == '"' && his->flag == 1)
		{
			his->flag = 0;
			his->save = i + 1;
		}
		else if (rd_line[i] == '\'' && his->flag == 0)
		{
			his->flag = 2;
			his->save = i + 1;
		}
		else if (rd_line[i] == '\'' && his->flag == 2)
		{
			his->flag = 0;
			his->save = i + 1;
		}
		i++;
	}
}

static int	put_in_historic(t_cmd *pip, t_hist *his, char *rd_line)
{
	int	i;

	if (pip->hd_history != NULL)
	{
		renitialize_buf_tmp(his);
		i = -1;
		while (pip->hd_history[++i])
		{
			if (i == 0)
				his->buf = ft_strjoin("\n", pip->hd_history[i]);
			else
				his->buf = ft_strjoin(his->tmp, pip->hd_history[i]);
			if (his->buf == NULL)
				return (error(MALLOC, "0"), 1);
			free(his->tmp);
			his->tmp = his->buf;
		}
		his->tmp = ft_strjoin(rd_line, his->buf);
		if (his->tmp == NULL)
			return (error(MALLOC, "0"), free(his->buf), 1);
		free(his->buf);
	}
	else
		his->tmp = rd_line;
	return (0);
}

static void	renitialize_buf_tmp(t_hist *his)
{
	his->buf = NULL;
	his->tmp = NULL;
}
