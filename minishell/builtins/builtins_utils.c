/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:36:54 by dbaule            #+#    #+#             */
/*   Updated: 2023/10/28 21:45:37 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
#include "../incs/builtins.h"

static void	verif_echo_n(t_buil_ut *comp, char **arg, int *j, int *flag);

void	print_export(char **exp_env)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (exp_env[i])
	{
		j = 0;
		flag = 0;
		while (exp_env[i][j])
		{
			ft_printf("%c", exp_env[i][j++]);
			if (exp_env[i][j - 1] == '=' && flag++ == 0)
				ft_printf("\"");
		}
		if (flag != 0)
			ft_printf("\"");
		ft_printf("\n");
		i++;
	}
}

char	*rm_char(char *str, char c)
{
	size_t	i;
	size_t	z;
	char	*new_str;

	i = 0;
	z = 0;
	while (str[i])
		if (str[i++] == c)
			z++;
	new_str = malloc(sizeof(char) * (i - z + 1));
	if (!new_str)
		return (error(MALLOC, "0"), NULL);
	i = 0;
	z = 0;
	while (str[i])
	{
		if (str[i] != c)
			new_str[z++] = str[i];
		i++;
	}
	new_str[z] = '\0';
	free(str);
	return (new_str);
}

int	position_echo_n(char **arg, int *j, int *flag, int *option)
{
	t_buil_ut	comp;

	comp.i = 0;
	comp.k = 0;
	while (arg[++comp.i])
	{
		if (arg[comp.i][comp.k] != '-')
			return (comp.i);
		while (arg[comp.i][comp.k])
		{
			verif_echo_n(&comp, arg, j, flag);
			if (arg[comp.i][comp.k])
			{
				*flag = 2;
				*j = comp.k;
				*option = 0;
				return (comp.i);
			}
		}
		comp.k = 0;
	}
	return (comp.i);
}

static void	verif_echo_n(t_buil_ut *comp, char **arg, int *j, int *flag)
{
	if (arg[comp->i][comp->k + 1] && arg[comp->i][comp->k] == '-' && \
	arg[comp->i][comp->k + 1] == 'n' && *flag != 2)
	{
		*j = comp->k;
		comp->k++;
		while (arg[comp->i][comp->k] && arg[comp->i][comp->k] == 'n')
			comp->k++;
	}
}
