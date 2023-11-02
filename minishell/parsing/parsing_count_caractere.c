/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_count_caractere.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:23:59 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/26 14:09:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"
#include "../incs/minishell.h"

static void	check_first_conditions(t_pars *p, const char *rd_line, int *flag);
static void	check_second_conditions(t_pars *p, const char *rd_line, int *flag);
static void	check_third_conditions(t_pars *p, const char *rd_line, int *flag);

void	parsing_count_caractere(t_pars *p, int *flag, const char *rd_line)
{
	while (rd_line[p->i])
	{
		check_first_conditions(p, rd_line, flag);
		if (rd_line[p->i] == '\0')
			return ;
		check_second_conditions(p, rd_line, flag);
		check_third_conditions(p, rd_line, flag);
		if (*flag != 3)
			p->tab[p->compt] += 1;
		p->i++;
	}
}

static void	check_first_conditions(t_pars *p, const char *rd_line, int *flag)
{
	while (rd_line[p->i] == '|' && (*flag == 0 || *flag == 3 || *flag == 4))
	{
		if (p->i > 0 && rd_line[p->i - 1] != ' ')
			p->compt++;
		*flag = 0;
		p->tab[p->compt] += 1;
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
	if (rd_line[p->i] == '\n' && (*flag == 0 || *flag == 3))
	{
		*flag = 5;
		p->tab[p->compt] += 1;
		p->compt++;
		p->tab[p->compt] -= 1;
	}
}

static void	check_second_conditions(t_pars *p, const char *rd_line, int *flag)
{
	if (p->tmp_flag == 0 && rd_line[p->i] != ' ')
		p->tmp_flag = 1;
	if (rd_line[p->i] != ' ' && *flag == 3)
		*flag = 0;
	if (*flag == 4 && rd_line[p->i] == '\n')
	{
		p->tab[p->compt] += 1;
		p->compt++;
		p->tab[p->compt] -= 1;
		*flag = 5;
	}
	if (*flag == 4 && rd_line[p->i] == ' ')
		*flag = 0;
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
	else if (rd_line[p->i] == ' ' && *flag == 0 && p->tmp_flag == 1)
	{
		p->compt++;
		*flag = 3;
	}
}

static void	check_third_conditions(t_pars *p, const char *rd_line, int *flag)
{
	if ((rd_line[p->i] == '<' || rd_line[p->i] == '>') && *flag == 0)
		*flag = 4;
	else if (ft_is_redirection(rd_line, p->i) && *flag == 4)
	{
		p->compt++;
		p->tab[p->compt] += 1;
		if (rd_line[p->i + 1] == '>' || rd_line[p->i + 1] == '<')
			p->tab[p->compt] += 1;
	}
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
