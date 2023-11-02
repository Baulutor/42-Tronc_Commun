/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_read_utils_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:11:41 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/29 15:51:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/verif_read.h"

static int	check_output_redirect(t_cell *tmp, char *str);
static int	check_input_redirect(t_cell *tmp, char *str);

int	check_arg(t_list *spt)
{
	char	*str;
	t_cell	*tmp;

	tmp = spt->head;
	while (tmp != NULL)
	{
		str = (char *)tmp->data_cell->data;
		if (tmp->next != NULL && str[0] == '|' && \
		((char *)tmp->next->data_cell->data)[0] == '|')
			return (error(SYNTAX, "|"), g_status = 2, 1);
		if (str[0] == '<')
		{
			if (check_input_redirect(tmp, str) != 0)
				return (1);
		}
		else if (str[0] == '>')
		{
			if (check_output_redirect(tmp, str) != 0)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	check_output_redirect(t_cell *tmp, char *str)
{
	if (tmp->next != NULL)
	{
		if (str[1] == '\0' && (((char *)tmp->next->data_cell->data)[0] == '<'))
			return (error(SYNTAX, "<"), g_status = 2, 1);
		if (str[1] == '\0' && ((char *)tmp->next->data_cell->data)[0] == '>')
			return (error(SYNTAX, ">"), g_status = 2, 1);
	}
	if (str[1] == '\0' && tmp->next == NULL)
		return (error(SYNTAX, "newline"), g_status = 2, 1);
	else if (str[1] == '>' && str[2] == '\0' && tmp->next == NULL)
		return (error(SYNTAX, "newline"), g_status = 2, 1);
	else if (str[1] == '>' && str[2] == '>')
		return (error(SYNTAX, ">"), g_status = 2, 1);
	return (0);
}

static int	check_input_redirect(t_cell *tmp, char *str)
{
	if (tmp->next != NULL)
	{
		if (str[1] == '\0' && ((char *)tmp->next->data_cell->data)[0] == '<')
			return (error(SYNTAX, "<"), g_status = 2, 1);
		if (str[1] == '\0' && ((char *)tmp->next->data_cell->data)[0] == '>')
			return (error(SYNTAX, ">"), g_status = 2, 1);
	}
	if (str[1] == '\0' && tmp->next == NULL)
		return (error(SYNTAX, "newline"), g_status = 2, 1);
	else if (str[1] == '<')
	{
		if (str[2] == '\0' && tmp->next == NULL)
			return (error(SYNTAX, "newline"), g_status = 2, 1);
		else if (str[2] == '<')
			return (error(SYNTAX, "newline"), g_status = 2, 1);
	}
	else if (str[1] == '>')
		return (error(SYNTAX, "newline"), g_status = 2, 1);
	return (0);
}

int	check_expand(char *rd_line)
{
	size_t	i;

	i = 0;
	while (rd_line[i] == ' ' || rd_line[i] == '\t')
		i++;
	if (rd_line[i] == '\0')
		return (g_status = 0, 1);
	while (rd_line[i])
	{
		if (rd_line[i] != ' ' && rd_line[i] != '|' \
		&& rd_line[i] != '<' && rd_line[i] != '>')
			return (0);
		i++;
	}
	return (error(SYNTAX, "newline"), g_status = 1, 1);
}
