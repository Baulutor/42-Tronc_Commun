/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_quote_buil_exec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:13:18 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/30 17:25:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static void	count_quotes(int *i, int *j, int *flag, char *str);
static void	creat_new_str(int *j, char *str, char *new_str);

char	*trash_quote_buil_exec(char *str)
{
	int		i;
	int		j;
	char	*new_str;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	count_quotes(&i, &j, &flag, str);
	new_str = malloc(sizeof(char) * ((i - j) + 1));
	if (!new_str)
		return (free(str), NULL);
	creat_new_str(&j, str, new_str);
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static void	count_quotes(int *i, int *j, int *flag, char *str)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '"' && *flag == 0)
		{
			*j += 1;
			*flag = 1;
		}
		else if (str[*i] == '\'' && *flag == 0)
		{
			*j += 1;
			*flag = 2;
		}
		else if (str[*i] == '"' && *flag == 1)
		{
			*j += 1;
			*flag = 0;
		}
		else if (str[*i] == '\'' && *flag == 2)
		{
			*j += 1;
			*flag = 0;
		}
		*i += 1;
	}
}

static void	creat_new_str(int *j, char *str, char *new_str)
{
	int	i;
	int	flag;

	i = 0;
	*j = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '"' && flag == 0)
			flag = 1;
		else if (str[i] == '\'' && flag == 0)
			flag = 2;
		else if (str[i] == '"' && flag == 1)
			flag = 0;
		else if (str[i] == '\'' && flag == 2)
			flag = 0;
		if ((flag == 2 && str[i] != '\'') || (flag == 1 && str[i] != '"') \
		|| (flag == 0 && str[i] != '"' && str[i] != '\''))
		{
			new_str[*j] = str[i];
			*j += 1;
		}
		i++;
	}
}
