/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_count_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:22:30 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/26 14:09:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"
#include "../incs/minishell.h"

static void	check_first_condition(t_pars *p, const char *rd_line, int *flag);
static void	check_second_condition(t_pars *p, const char *rd_line, int *flag);
static void	check_third_condition(t_pars *p, const char *rd_line, int *flag);

void	parsing_count_arg(t_pars *p, int *flag, const char *rd_line)
{
	while (rd_line[p->i])
	{
		check_first_condition(p, rd_line, flag);
		if (rd_line[p->i] == '\0')
			return ;
		check_second_condition(p, rd_line, flag);
		if (rd_line[p->i] == '\n' && *flag == 0)
			return ;
		check_third_condition(p, rd_line, flag);
		if (*flag == 4 && rd_line[p->i] == '\n')
			return ;
		if (rd_line[p->i] == ' ' && *flag == 0)
			*flag = 3;
		p->i++;
	}
}

static void	check_first_condition(t_pars *p, const char *rd_line, int *flag)
{
	while (rd_line[p->i] == '|' && (*flag == 0 || *flag == 3 || *flag == 4))
	{
		if (p->i > 0 && rd_line[p->i - 1] != ' ')
			p->compt++;
		*flag = 0;
		p->i++;
	}
	if (rd_line[p->i] == '\0')
	{
		if (p->i > 0 && rd_line[p->i - 1] != '|')
			*flag = 3;
		return ;
	}
	if (p->i > 0 && rd_line[p->i] != ' ' && rd_line[p->i - 1] == '|' \
	&& (*flag == 0 || *flag == 3))
		p->compt++;
}

static void	check_second_condition(t_pars *p, const char *rd_line, int *flag)
{
	if (rd_line[p->i] == '\n' && *flag == 0)
	{
		p->compt++;
		return ;
	}
	if ((rd_line[p->i] != ' ' && *flag == 3) || (p->i > 0 \
	&& rd_line[p->i] == ' ' && rd_line[p->i - 1] == '|' && *flag != 1 \
	&& *flag != 2))
		*flag = 0;
	if (p->tmp_flag == 0 && rd_line[p->i] != ' ')
		p->tmp_flag = 1;
}

static void	check_third_cond_bis(t_pars *p, const char *rd_line, int *flag)
{
	if (rd_line[p->i] == '\'' && *flag == 0)
		*flag = 2;
	else if (rd_line[p->i] == '\'' && *flag == 2)
	{
		if (rd_line[p->i + 1] != '\0' && rd_line[p->i + 1] != ' ' \
		&& p->new_flag == 1)
			p->compt++;
		p->new_flag = 0;
		*flag = 0;
	}
	else if (rd_line[p->i] == '\n' && (*flag == 1 || *flag == 2))
		p->new_flag = 1;
	else if (p->i > 0 && rd_line[p->i] == ' ' && *flag == 0 && p->tmp_flag == 1)
		p->compt++;
}

static void	check_third_condition(t_pars *p, const char *rd_line, int *flag)
{
	if (*flag == 4 && rd_line[p->i] == '\n')
	{
		p->compt++;
		return ;
	}
	if (*flag == 4 && rd_line[p->i] == ' ')
		*flag = 0;
	if ((rd_line[p->i] == '<' || rd_line[p->i] == '>') && *flag == 0)
		*flag = 4;
	else if (ft_is_redirection(rd_line, p->i) && *flag == 4)
		p->compt++;
	else if (rd_line[p->i] == '"' && (*flag == 0 || *flag == 4))
		*flag = 1;
	else if (rd_line[p->i] == '"' && *flag == 1)
	{
		if (rd_line[p->i + 1] != '\0' && rd_line[p->i + 1] != ' ' \
		&& p->new_flag == 1)
			p->compt++;
		p->new_flag = 0;
		*flag = 0;
	}
	else
		check_third_cond_bis(p, rd_line, flag);
}
