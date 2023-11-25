/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:23 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/21 19:42:08 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_fork(t_phi *phi);
static int	check_dead(t_phi *phi, int flag);

int	eating(t_phi *phi)
{
	if (phi->data->ti_died < phi->data->ti_eat)
		return (ft_usleep(phi->data->ti_died), check_dead(phi, 1), 1);
	if (check_dead(phi, 0) == 1)
		return (1);
	if ((unsigned long)phi->data->max_meal == (unsigned long)phi->nb_meal)
		return (1);
	if (phi->wh_phi == phi->data->nb_phi)
	{
		if (take_fork_last(phi) == 1)
			return (1);
	}
	else if (take_fork(phi) == 1)
		return (1);
	phi->nb_meal += 1;
	if (print_events(phi, EATING) == 1)
		return (1);
	phi->ti_lt_meal = get_time();
	if (ft_usleep(phi->data->ti_eat) == 1)
		return (error(U_SLEEP), 1);
	if (pthread_mutex_unlock(phi->r_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(&phi->l_fork) != 0)
		return (1);
	return (0);
}

static int	take_fork(t_phi *phi)
{
	if (pthread_mutex_lock(phi->r_fork) != 0)
		return (1);
	if (print_events(phi, FORK) == 1)
		return (1);
	if (pthread_mutex_lock(&phi->l_fork) != 0)
		return (1);
	if (print_events(phi, FORK) == 1)
		return (1);
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
		check_dead(phi, 1);
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

static int	check_dead(t_phi *phi, int flag)
{
	if (get_time() - phi->ti_lt_meal >= (unsigned long)phi->data->ti_died \
	|| flag == 1)
	{
		if (pthread_mutex_lock(&phi->data->mut_print) != 0)
			return (1);
		if (phi->data->is_dead != 1)
		{
			printf("%lld", get_time() - phi->data->start_pg);
			printf(" %d %s\n", phi->wh_phi, DEAD);
			phi->data->is_dead = 1;
		}
		pthread_mutex_unlock(&phi->data->mut_print);
		return (1);
	}
	return (0);
}
