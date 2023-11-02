/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_read_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:08:50 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 17:30:33 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static t_cell	*moving_to_the_needed_cell(int *tab, int i, t_cell *tmp);

int	*counting_arg(int count, t_list *spt)
{
	int		*tab;
	int		i;
	int		j;
	t_cell	*tmp;

	i = 0;
	j = 0;
	tmp = spt->head;
	tab = malloc(sizeof(int *) * count);
	if (tab == NULL)
		return (error(MALLOC, NULL), NULL);
	while (tmp != NULL)
	{
		if (((char *)(tmp->data_cell->data))[0] == '|')
		{
			tab[j] = i;
			j++;
			i = -1;
		}
		i++;
		tmp = tmp->next;
	}
	tab[j] = i;
	return (tab);
}

char	**string_for_cmd_center(int *tab, int i, t_list *spt)
{
	int		j;
	char	**for_cmd;
	char	*buf;
	t_cell	*tmp;

	tmp = spt->head;
	tmp = moving_to_the_needed_cell(tab, i, tmp);
	for_cmd = (char **)malloc(sizeof(char *) * (tab[i] + 1));
	if (!for_cmd)
		return (error(MALLOC, "0"), NULL);
	j = 0;
	while (tab[i] > j)
	{
		buf = (char *)tmp->data_cell->data;
		if (buf[0] == '|')
			tmp = tmp->next;
		for_cmd[j] = ft_strdup((char *)tmp->data_cell->data);
		if (!for_cmd[j])
			return (error(MALLOC, "0"), anihilation(for_cmd), NULL);
		j++;
		tmp = tmp->next;
	}
	for_cmd[j] = 0;
	return (for_cmd);
}

static t_cell	*moving_to_the_needed_cell(int *tab, int i, t_cell *tmp)
{
	int	j;
	int	y;

	y = 0;
	j = 0;
	while (j < i)
	{
		y = 0;
		while (tab[j] && y < tab[j])
		{
			tmp = tmp->next;
			y++;
		}
		if (((char *)tmp->data_cell->data)[0] == '|')
			tmp = tmp->next;
		j++;
	}
	return (tmp);
}

char	*trash_quote(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
			j++;
		i++;
	}
	new_str = malloc(sizeof(char) * ((i - j) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
