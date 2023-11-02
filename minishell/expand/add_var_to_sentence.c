/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_to_sentence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:50:06 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 19:10:49 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/expand.h"

static void	initiliaze_var_add(int i, t_add *add, char *rd_line, int *flag);
static void	fill_new_char(char *var, t_add *add, char *rd_line, int i);

char	*add_var_to_sentence(char *rd_line, char *var, int i, int *flag)
{
	t_add	add;

	initiliaze_var_add(i, &add, rd_line, flag);
	if (var == NULL)
		add.new = (char *) malloc(sizeof(char) * \
		(ft_strlen(rd_line) - add.len + 1 + add.quote));
	else
		add.new = (char *) malloc(sizeof(char) * \
		(ft_strlen(rd_line) - add.len + ft_strlen(var) + 1 + add.quote));
	if (add.new == NULL)
		return (error(MALLOC, "0"), NULL);
	add.j = -1;
	while (++add.j < i)
		add.new[add.j] = rd_line[add.j];
	i += add.len;
	add.len = 0;
	fill_new_char(var, &add, rd_line, i);
	return (add.new);
}

static void	initiliaze_var_add(int i, t_add *add, char *rd_line, int *flag)
{
	add->len = 0;
	add->j = i;
	add->quote = 0;
	if (*flag == 2)
		add->quote = 1;
	if (rd_line[i + 1] == '?')
		add->len = 2;
	else
		while (ft_isprint(rd_line[add->j]) && rd_line[add->j] != ' ' && \
			rd_line[add->j] != '\'' && rd_line[add->j] != '"' && \
			rd_line[add->j++] != '|')
			add->len++;
}

static void	fill_new_char(char *var, t_add *add, char *rd_line, int i)
{
	if (var != NULL)
	{
		if (var[0] > '9' || var[0] < '0')
		{
			while (var[add->len] != '=')
				add->len++;
			add->len++;
		}
		while (var[add->len])
			add->new[add->j++] = var[add->len++];
	}
	while (rd_line[i])
		add->new[add->j++] = rd_line[i++];
	add->new[add->j] = '\0';
}
