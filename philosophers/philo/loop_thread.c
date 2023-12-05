/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:13:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/12/05 17:13:44 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_start(t_phi *phi);
static int	send_pair_phi_thinking(t_phi *phi);

void	*routine(void *data)
{
	t_phi	*phi;

	phi = (t_phi *)data;
	wait_start(phi);
	if (phi->data->nb_phi == 1)
		return (only_one_phi(phi), NULL);
	if (send_pair_phi_thinking(phi) == 1)
		return (NULL);
	if (phi->data->nb_phi % 2 == 1 && phi->wh_phi == phi->data->nb_phi)
		thinking(phi);
	while (1)
	{
		if (eating(phi) == 1)
			return (0);
		if (sleeping(phi) == 1)
			return (0);
		if (thinking(phi) == 1)
			return (0);
	}
	return (0);
}

static void	wait_start(t_phi *phi)
{
	long long	start;

	start = -1;
	while (start == -1)
	{
		pthread_mutex_lock(&phi->data->mut_start);
		start = phi->data->start_pg;
		pthread_mutex_unlock(&phi->data->mut_start);
	}
	pthread_mutex_lock(&phi->data->mut_ti_lt_meal);
	phi->ti_lt_meal = get_time();
	pthread_mutex_unlock(&phi->data->mut_ti_lt_meal);
}

static int	send_pair_phi_thinking(t_phi *phi)
{
	if ((phi->wh_phi % 2) == 0)
	{
		thinking(phi);
		if (phi->data->ti_eat > phi->data->ti_died)
			return (1);
		else
		{
			if (ft_usleep(phi->data->ti_eat / 2) == 1)
				return (error(U_SLEEP), 1);
		}
	}
	return (0);
}
