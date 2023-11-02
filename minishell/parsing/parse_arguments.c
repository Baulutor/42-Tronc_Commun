/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:26:42 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/26 14:09:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"
#include "../incs/minishell.h"

static void	check_first_conditions(t_pars *p, const char *rd_line, int *flag);
static void	check_second_conditions(t_pars *p, const char *rd_line, int *flag);
static void	check_third_conditions(t_pars *p, const char *rd_line, int *flag);

void	parse_arguments(t_pars *p, int *flag, const char *rd_line)
{
	while (rd_line[p->i])
	{
		check_first_conditions(p, rd_line, flag);
		if (rd_line[p->i] == '\0')
			return ;
		check_second_conditions(p, rd_line, flag);
		check_third_conditions(p, rd_line, flag);
		if (rd_line[p->i] == ' ' && *flag == 0)
			*flag = 3;
		if ((*flag != 3 && rd_line[p->i] != '|') || \
		(*flag != 0 && rd_line[p->i] == '|') || *flag == 5)
		{
			p->spt[p->compt][p->j] = rd_line[p->i];
			p->j++;
		}
		p->i++;
	}
}

static void	check_first_conditions(t_pars *p, const char *rd_line, int *flag)
{
	if (p->i > 0 && rd_line[p->i] == '|' && rd_line[p->i - 1] != ' ' \
	&& (*flag == 0 || *flag == 3 || *flag == 4))
		p->spt[p->compt++][p->j] = '\0';
	while (rd_line[p->i] == '|' && (*flag == 0 || *flag == 3 || *flag == 4))
	{
		p->spt[p->compt][0] = '|';
		p->spt[p->compt][1] = '\0';
		p->j = 0;
		p->i++;
		if (rd_line[p->i] != '\0')
			p->compt++;
	}
	if (rd_line[p->i] == '\0')
		return ;
	if (rd_line[p->i] == '\n' && (*flag == 0 || *flag == 3))
	{
		p->tmp_flag = -1;
		*flag = 5;
		p->spt[p->compt][p->j] = '\n';
		p->spt[p->compt][p->j + 1] = '\0';
		if (p->i > 0 && rd_line[p->i - 1] != ' ')
			p->compt++;
		p->j = 0;
		p->i++;
	}
}

static void	check_second_conditions(t_pars *p, const char *rd_line, int *flag)
{
	if ((rd_line[p->i] == '<' || rd_line[p->i] == '>') && p->tmp_flag == 0 \
	&& *flag != 5)
		p->tmp_flag = 1;
	else if (ft_is_redirection(rd_line, p->i) && p->tmp_flag == 1)
	{
		if (p->i > 0 && rd_line[p->i - 1] != ' ')
			p->spt[p->compt++][p->j] = '\0';
		p->j = 0;
		p->spt[p->compt][p->j++] = rd_line[p->i++];
		if (rd_line[p->i] == '>' || rd_line[p->i] == '<')
			p->spt[p->compt][p->j++] = rd_line[p->i++];
	}
	else if (p->tmp_flag == 1 && (rd_line[p->i] == ' '))
		p->tmp_flag = 0;
	else if (rd_line[p->i] == '\n' && p->tmp_flag == 1 && *flag != 5)
	{
		p->spt[p->compt][p->j + 1] = '\0';
		p->j = 0;
		p->i++;
		p->compt++;
		p->tmp_flag = 0;
	}
	if (rd_line[p->i] != ' ' && *flag == 3)
		*flag = 0;
}

static void	check_third_cond_bid(t_pars *p, const char *rd_line, int *flag)
{
	if (rd_line[p->i] == '\'' && *flag == 2)
	{
		*flag = 0;
		p->spt[p->compt][p->j] = '\'';
		if (rd_line[p->i + 1] == ' ' || (rd_line[p->i + 1] != '\0' \
		&& rd_line[p->i + 1] != ' ' && p->new_flag == 1))
		{
			p->spt[p->compt][p->j + 1] = '\0';
			p->j = 0;
			p->i++;
			p->compt++;
		}
		p->new_flag = 0;
	}
	else if (p->i > 0 && rd_line[p->i] == ' ' && rd_line[p->i - 1] != '|' \
	&& *flag == 0 && p->i > 0)
	{
		p->spt[p->compt][p->j] = '\0';
		p->j = 0;
		p->compt++;
	}
	else if (rd_line[p->i] == '\n' && (*flag == 1 || *flag == 2))
		p->new_flag = 1;
}

static void	check_third_conditions(t_pars *p, const char *rd_line, int *flag)
{
	if (rd_line[p->i] == '"' && *flag == 0)
		*flag = 1;
	else if (rd_line[p->i] == '"' && *flag == 1)
	{
		*flag = 0;
		p->spt[p->compt][p->j] = '"';
		if (rd_line[p->i + 1] == ' ' || (rd_line[p->i + 1] != '\0' \
		&& rd_line[p->i + 1] != ' ' && p->new_flag == 1))
		{
			p->spt[p->compt][p->j + 1] = '\0';
			p->j = 0;
			p->i++;
			p->compt++;
		}
		p->new_flag = 0;
	}
	else if (rd_line[p->i] == '\'' && *flag == 0)
		*flag = 2;
	else
		check_third_cond_bid(p, rd_line, flag);
}
