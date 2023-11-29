/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:50:57 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/13 16:16:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_pos_nb(char **argv);

int	parsing(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error(NB_PARAM), 1);
	if (check_pos_nb(argv) == 1)
		return (1);
	return (0);
}

static int	check_pos_nb(char **argv)
{
	int	i;
	int	z;

	i = 1;
	while (argv[i])
	{
		z = 0;
		while (argv[i][z] == ' ' || argv[i][z] == '\t')
			z++;
		if (!argv[i][z])
			return (error(POS_NB), 1);
		if (argv[i][z] == '+')
			z++;
		if (ft_atoi(argv[i]) == (long unsigned)-1 && ft_strlen(argv[i] + z) > 8)
			return (error(BIG_NB), 1);
		while (argv[i][z])
		{
			if (argv[i][z] < '0' || argv[i][z] > '9')
				return (error(POS_NB), 1);
			z++;
		}
		i++;
	}
	return (0);
}
