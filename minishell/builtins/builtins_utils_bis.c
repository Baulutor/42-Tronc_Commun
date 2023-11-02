/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:36:13 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:45:57 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

int	count_name_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	check_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (!str[i])
		return (1);
	else
		return (0);
}
