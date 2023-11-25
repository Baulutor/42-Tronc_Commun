/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:24:17 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/13 11:22:23 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(unsigned long i)
{
	unsigned long	split;

	split = 1000 * i;
	if (usleep(split / 4) == -1)
		return (1);
	if (usleep(split / 4) == -1)
		return (1);
	if (usleep(split / 4) == -1)
		return (1);
	if (usleep(split / 4) == -1)
		return (1);
	return (0);
}

void	only_one_phi(t_phi *phi)
{
	printf("%lld ", get_time() - phi->data->start_pg);
	printf("%d has taken a fork\n", phi->wh_phi);
	ft_usleep(phi->data->ti_died);
	printf("%lld", get_time() - phi->data->start_pg);
	printf(" %d %s\n", phi->wh_phi, DEAD);
	phi->data->is_dead = 1;
}

int	take_fork_last(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->l_fork) != 0)
		return (1);
	if (print_events(phi, FORK) == 1)
		return (1);
	if (pthread_mutex_lock(phi->r_fork) != 0)
		return (1);
	if (print_events(phi, FORK) == 1)
		return (1);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error(ERR_TIME), 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
