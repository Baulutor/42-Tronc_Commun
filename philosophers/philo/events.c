/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:23 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/28 17:37:01 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_fork(t_phi *phi);
static int	ck_fork(t_phi *phi);

int	eating(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->data->mut_print) != 0)
		return (error(MUT_LOCK), 1);
	if ((unsigned long)phi->data->max_meal == (unsigned long)phi->nb_meal)
		return (pthread_mutex_unlock(&phi->data->mut_print), 1);
	if (phi->data->is_dead == 1)
		return (pthread_mutex_unlock(&phi->data->mut_print), 1);
	if (pthread_mutex_unlock(&phi->data->mut_print) != 0)
		return (error(MUT_UNLOCK), 1);
	if (ck_fork(phi) == 1)
		return (1);
	if (print_events(phi, EATING) == 1)
		return (1);
	if (phi->data->ti_eat > phi->data->ti_died)
	{
		if (ft_usleep(phi->data->ti_died) == 1)
			return (error(U_SLEEP), 1);
		if (pthread_mutex_unlock(&phi->data->mut_fork) != 0)
			return (error(MUT_UNLOCK), 1);
		return (1);
	}
	else
	{
		if (ft_usleep(phi->data->ti_eat) == 1)
			return (error(U_SLEEP), 1);
	}
	if (pthread_mutex_lock(&phi->data->mut_fork) != 0)
		return (error(MUT_UNLOCK), 1);
	phi->l_f = 0;
	*phi->r_f = 0;
	if (pthread_mutex_unlock(&phi->data->mut_fork) != 0)
		return (error(MUT_UNLOCK), 1);
	return (0);
}

static int	ck_fork(t_phi *phi)
{
	int	ck_fork;

	ck_fork = 0;
	while (ck_fork == 0)
	{
//		if (get_time() - phi->ti_lt_meal >= (unsigned long)phi->data->ti_died)
//			return (1);
		ck_fork = take_fork(phi);
		if (ck_fork == 1)
			return (1);
	}
	return (0);
}

static int	take_fork(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->data->mut_fork) != 0)
		return (error(MUT_LOCK), 1);
	if (phi->l_f == 0 && *phi->r_f == 0)
	{
		phi->l_f = 1;
		*phi->r_f = 1;
		if (pthread_mutex_unlock(&phi->data->mut_fork) != 0)
			return (error(MUT_LOCK), 1);
		if (print_events(phi, FORK) == 1)
			return (1);
		if (print_events(phi, FORK) == 1)
			return (1);
		return (2);
	}
	if (pthread_mutex_unlock(&phi->data->mut_fork) != 0)
		return (error(MUT_LOCK), 1);
	return (0);
}

int	thinking(t_phi *phi)
{
	if ((unsigned long)phi->data->max_meal == (unsigned long)phi->nb_meal)
		return (1);
	if (print_events(phi, THINKING) == 1)
		return (1);
	return (0);
}

int	sleeping(t_phi *phi)
{
	if (phi->data->ti_died < phi->data->ti_sleep)
	{
		ft_usleep(phi->data->ti_died);
		return (1);
	}
	if (phi->data->max_meal == phi->nb_meal)
		return (1);
	if (print_events(phi, SLEEP) == 1)
		return (1);
	if (ft_usleep(phi->data->ti_sleep) == 1)
		return (error(U_SLEEP), 1);
	return (0);
}
