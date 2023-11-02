/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:31:10 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 19:06:24 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

typedef struct t_expand
{
	char	*new;
	char	*tmp;
	char	*var;
	int		j;
	int		len_var;
}	t_expand;

typedef struct t_add
{
	int		j;
	int		len;
	int		quote;
	char	*new;
}	t_add;

char	*add_var_to_sentence(char *rd_line, char *var, int i, int *flag);
void	check_var_env(char *rd_line, t_expand *exp, int i, t_cmd *pip);
void	quote_check(int *flag, char *rd_line, int i);

#endif