/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:55:25 by eslamber          #+#    #+#             */
/*   Updated: 2023/10/28 19:08:47 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/expand.h"

static int	check_dollar_sign(int *flag, char **rd_line, t_expand *exp, int i);
static int	count_and_allocate(t_expand *exp, int i, char *rd_line, t_cmd *pip);

char	*expand(char *rd_line, t_cmd *pip, int *flag)
{
	int			i;
	t_expand	exp;

	i = 0;
	while (rd_line[i])
	{
		quote_check(flag, rd_line, i);
		if (check_dollar_sign(flag, &rd_line, &exp, i) == 1)
			return (NULL);
		if (rd_line[i] == '$' && ft_isalpha(rd_line[i + 1]) && *flag != 1)
		{
			if (count_and_allocate(&exp, i, rd_line, pip) == 1)
				return (NULL);
			exp.new = add_var_to_sentence(rd_line, exp.var, i, flag);
			if (exp.new != NULL)
			{
				free(rd_line);
				rd_line = exp.new;
			}
			exp.new = NULL;
		}
		if (rd_line[i] != '\0')
			i++;
	}
	return (rd_line);
}

static int	count_and_allocate(t_expand *exp, int i, char *rd_line, t_cmd *pip)
{
	exp->len_var = 0;
	exp->j = i + 1;
	while (ft_isprint(rd_line[exp->j]) && rd_line[exp->j] != ' ' && \
	rd_line[exp->j++] != '\'')
		exp->len_var++;
	if (rd_line[i + exp->len_var] == '"')
		exp->len_var--;
	exp->tmp = (char *) malloc(sizeof(char) * (exp->len_var + 1));
	if (exp->tmp == NULL)
		return (error(MALLOC, "0"), 1);
	check_var_env(rd_line, exp, i, pip);
	return (0);
}

static int	check_dollar_sign(int *flag, char **rd_line, t_expand *exp, int i)
{
	if (rd_line[0][i] == '$' && rd_line[0][i + 1] == '?' && *flag != 1)
	{
		exp->tmp = ft_itoa(g_status);
		if (exp->tmp == NULL)
			return (error(MALLOC, "0"), 1);
		exp->new = add_var_to_sentence(rd_line[0], exp->tmp, i, flag);
		free(exp->tmp);
		if (exp->new != NULL)
		{
			free(*rd_line);
			rd_line[0] = exp->new;
		}
		exp->new = NULL;
	}
	return (0);
}
