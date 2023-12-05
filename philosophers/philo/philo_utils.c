/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:24:17 by dbaule            #+#    #+#             */
/*   Updated: 2023/12/05 17:19:11 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(unsigned long i)
{
	unsigned long	split;

	split = 1000 * i;
	i = get_time() * 1000;
	while (split >= ((get_time() * 1000) - i))
	{
		if (usleep(100) == -1)
			return (1);
	}
	return (0);
}

int	only_one_phi(t_phi *phi)
{
	long long	ck_err;

	ck_err = get_time();
	printf("%lld ", ck_err - phi->data->start_pg);
	printf("%d has taken a fork\n", phi->wh_phi);
	ft_usleep(phi->data->ti_died - 1);
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error(ERR_TIME), -1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	destroying_mutex(t_philo *struc, int i, t_phi *phi)
{
	int	j;

	j = 0;
	if (pthread_mutex_destroy(&struc->mut_print) != 0)
		return (error(MUT_DES), 1);
	if (pthread_mutex_destroy(&struc->mut_ti_lt_meal) != 0)
		return (error(MUT_DES), 1);
	if (pthread_mutex_destroy(&struc->death) != 0)
		return (error(MUT_DES), 1);
	if (pthread_mutex_destroy(&struc->phi_eat) != 0)
		return (error(MUT_DES), 1);
	if (pthread_mutex_destroy(&struc->mut_start) != 0)
		return (error(MUT_DES), 1);
	while (j < i)
	{
		if (pthread_mutex_destroy(&phi->l_fork) != 0)
			return (error(MUT_DES), 1);
		j++;
	}
	return (0);
}

int	ti_eat_greater_ti_death(t_phi *phi)
{
	if (phi->data->ti_eat > phi->data->ti_died)
	{
		if (ft_usleep(phi->data->ti_died / 2) == 1)
			return (error(U_SLEEP), 1);
		return (1);
	}
	else
	{
		if (ft_usleep(phi->data->ti_eat - 1) == 1)
			return (error(U_SLEEP), 1);
	}
	return (0);
}
