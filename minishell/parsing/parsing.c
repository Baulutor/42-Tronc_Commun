/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:16:22 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/27 10:54:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"
#include "../incs/minishell.h"

static void	init_parsing(t_pars *struc, int *flag);
static int	creat_tab(t_pars *p, int *flag, t_list *ret);
static int	creat_split(t_pars *p, int *flag, t_list *ret);
static int	end_of_parsing(t_pars *p, int *flag, t_list *ret);

int	parsing(const char *rd_line, int *flag, t_list *ret)
{
	t_pars	struc;

	init_parsing(&struc, flag);
	parsing_count_arg(&struc, flag, rd_line);
	if (creat_tab(&struc, flag, ret) == 1)
		return (1);
	parsing_count_caractere(&struc, flag, rd_line);
	if (creat_split(&struc, flag, ret) == 1)
		return (1);
	parse_arguments(&struc, flag, rd_line);
	if (end_of_parsing(&struc, flag, ret) == 1)
		return (1);
	return (0);
}

static void	init_parsing(t_pars *struc, int *flag)
{
	struc->i = 0;
	struc->compt = 1;
	struc->save_flag = *flag;
	struc->spt = 0;
	struc->new_flag = 0;
	struc->tmp_flag = 0;
}

static int	creat_tab(t_pars *p, int *flag, t_list *ret)
{
	if (*flag == 3 && p->compt != 1)
		p->compt--;
	p->spt = (char **) malloc(sizeof(char *) * (p->compt + 1));
	if (p->spt == NULL)
		return (error(MALLOC, "0"), annihilation(ret, free, DEBUG), 1);
	p->spt[p->compt] = NULL;
	p->tab = (int *) ft_calloc(p->compt, sizeof(int));
	if (p->tab == NULL)
		return (free(p->spt), error(MALLOC, "0"), \
		annihilation(ret, free, DEBUG), 1);
	p->i = 0;
	p->compt = 0;
	*flag = p->save_flag;
	p->new_flag = 0;
	p->tmp_flag = 0;
	return (0);
}

static int	creat_split(t_pars *p, int *flag, t_list *ret)
{
	p->i = 0;
	if (*flag == 3 && p->compt != 0)
		p->compt--;
	if (*flag != 0 && *flag == p->save_flag)
		p->tab[p->compt] += 1;
	while (p->i <= p->compt)
	{
		p->spt[p->i] = (char *) ft_calloc(sizeof(char), (p->tab[p->i] + 1));
		if (p->spt[p->i] == NULL)
		{
			while (p->i >= 0)
				free(p->spt[p->i--]);
			return (free(p->tab), free(p->spt), error(MALLOC, "0"), \
			annihilation(ret, free, DEBUG), 1);
		}
		p->i++;
	}
	free(p->tab);
	p->i = 0;
	p->compt = 0;
	*flag = p->save_flag;
	p->j = 0;
	p->tmp_flag = 0;
	return (0);
}

static int	end_of_parsing(t_pars *p, int *flag, t_list *ret)
{
	if (*flag != 3)
	{
		if (*flag != 0 && *flag == p->save_flag)
			p->spt[p->compt][p->j++] = '\n';
		p->spt[p->compt][p->j] = '\0';
	}
	p->i = 0;
	while (p->spt[p->i] && p->spt[p->i][0] != '\0')
	{
		if (tailing_list(ret, p->spt[p->i++], STRING, DEBUG) == 0)
		{
			while (p->spt[p->i])
				free(p->spt[p->i++]);
			free(p->spt);
			annihilation(ret, free, DEBUG);
			error(MALLOC, "0");
			return (1);
		}
	}
	if (p->j == 0 && p->spt[p->compt] == NULL)
		free(p->spt[p->compt]);
	if (p->i != p->compt)
		free(p->spt[p->i]);
	free(p->spt);
	return (0);
}
