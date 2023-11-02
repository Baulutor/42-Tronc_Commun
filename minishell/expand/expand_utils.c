/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:05:14 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 19:09:30 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/expand.h"

static char	*is_in_env(char **env, char *cmp);

void	check_var_env(char *rd_line, t_expand *exp, int i, t_cmd *pip)
{
	exp->j = i + 1;
	exp->len_var = 0;
	while (ft_isprint(rd_line[exp->j]) && rd_line[exp->j] != ' ' && \
	rd_line[exp->j] != '\'' && rd_line[exp->j] != '"')
	{
		exp->tmp[exp->len_var] = rd_line[exp->j];
		exp->len_var++;
		exp->j++;
	}
	exp->tmp[exp->len_var] = '\0';
	exp->var = is_in_env(pip->env, exp->tmp);
	free(exp->tmp);
	exp->new = NULL;
}

void	quote_check(int *flag, char *rd_line, int i)
{
	if (*flag == 1 && rd_line[i] == '\'')
		*flag = 0;
	else if (*flag == 0 && rd_line[i] == '\'')
		*flag = 1;
	else if (*flag == 2 && rd_line[i] == '"')
		*flag = 0;
	else if (*flag == 0 && rd_line[i] == '"')
		*flag = 2;
}

static char	*is_in_env(char **env, char *cmp)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strlen(cmp) <= ft_strlen(env[i]) && \
		env[i][ft_strlen(cmp)] == '=' && \
		strncmp(env[i], cmp, ft_strlen(cmp)) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}
