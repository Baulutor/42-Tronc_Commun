/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:23 by dbaule            #+#    #+#             */
/*   Updated: 2023/12/05 14:42:41 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_l_fork(t_phi *phi);
static int	take_r_fork(t_phi *phi);
static int	ck_fork(t_phi *phi);
static int	release_fork(t_phi *phi);

int	eating(t_phi *phi)
{
	if (ck_fork(phi) == 1)
		return (release_fork(phi), 1);
	if (print_events(phi, EATING) == 1)
		return (release_fork(phi), 1);
	phi->nb_meal++;
	if (phi->nb_meal == phi->data->max_meal)
	{
		pthread_mutex_lock(&phi->data->phi_eat);
		phi->data->table_meal++;
		pthread_mutex_unlock(&phi->data->phi_eat);
	}
	if (pthread_mutex_lock(&phi->data->mut_ti_lt_meal) != 0)
		return (release_fork(phi), error(MUT_LOCK), 1);
	phi->ti_lt_meal = get_time();
	if (pthread_mutex_unlock(&phi->data->mut_ti_lt_meal) != 0)
		return (error(MUT_UNLOCK), 1);
	if (ti_eat_greater_ti_death(phi) == 1)
		return (release_fork(phi), 1);
	if (release_fork(phi) == 1)
		return (1);
	return (0);
}

static int	release_fork(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->l_fork) != 0)
		return (error(MUT_UNLOCK), 1);
	phi->l_f = 0;
	if (pthread_mutex_unlock(&phi->l_fork) != 0)
		return (error(MUT_UNLOCK), 1);
	if (pthread_mutex_lock(phi->r_fork) != 0)
		return (error(MUT_LOCK), 1);
	*phi->r_f = 0;
	if (pthread_mutex_unlock(phi->r_fork) != 0)
		return (error(MUT_UNLOCK), 1);
	return (0);
}

static int	ck_fork(t_phi *phi)
{
	int	l_fork;
	int	r_fork;

	l_fork = 0;
	r_fork = 0;
	while (l_fork == 0 || r_fork == 0)
	{
		if (l_fork == 0)
			l_fork = take_l_fork(phi);
		if (l_fork == 1)
			return (1);
		if (r_fork == 0)
			r_fork = take_r_fork(phi);
		if (r_fork == 1)
			return (1);
		usleep(200);
	}
	return (0);
}

static int	take_l_fork(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->l_fork) != 0)
		return (error(MUT_LOCK), 1);
	if (phi->l_f == 0)
	{
		phi->l_f = 1;
		if (pthread_mutex_unlock(&phi->l_fork) != 0)
			return (error(MUT_LOCK), 1);
		if (print_events(phi, FORK) == 1)
			return (1);
		return (2);
	}
	if (pthread_mutex_unlock(&phi->l_fork) != 0)
		return (error(MUT_LOCK), 1);
	return (0);
}

static int	take_r_fork(t_phi *phi)
{
	if (pthread_mutex_lock(phi->r_fork) != 0)
		return (error(MUT_LOCK), 1);
	if (*phi->r_f == 0)
	{
		*phi->r_f = 1;
		if (pthread_mutex_unlock(phi->r_fork) != 0)
			return (error(MUT_LOCK), 1);
		if (print_events(phi, FORK) == 1)
			return (1);
		return (2);
	}
	if (pthread_mutex_unlock(phi->r_fork) != 0)
		return (error(MUT_LOCK), 1);
	return (0);
}
