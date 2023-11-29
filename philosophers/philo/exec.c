/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/28 20:02:10 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *data);
static int	ck_finish(t_philo *phi, t_phi *ph);
static int	check_dead(t_phi *phi, int i, int *z);
static int	send_pair_phi_thinking(t_phi *phi);

int	exec(t_philo *struc, t_phi *phi)
{
	int	j;

	j = 0;
	while (j < struc->nb_phi)
	{
		if (pthread_create(&phi[j].phi, NULL, routine, &phi[j]) != 0)
			return (error(TH_CREATE), 1);
		j++;
	}
	ck_finish(struc, phi);
	j = 0;
	while (j < struc->nb_phi)
	{
		if (pthread_join(phi[j].phi, NULL) != 0)
			return (error(TH_JOIN), 1);
		j++;
	}
	return (0);
}

static void	*routine(void *data)
{
	t_phi	*phi;

	phi = (t_phi *)data;
	if (phi->data->nb_phi == 1)
		only_one_phi(phi);
	if (send_pair_phi_thinking(phi) == 1)
		return (NULL);
	while (1)
	{
		if (eating(phi) == 1)
			break ;
		if (sleeping(phi) == 1)
			break ;
		if (thinking(phi) == 1)
			break ;
	}
	return (0);
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
			if (ft_usleep(phi->data->ti_eat) == 1)
				return (error(U_SLEEP), 1);
		}
	}
	return (0);
}

static int	ck_finish(t_philo *phi, t_phi *ph)
{
	int	i;
	int	z;

	z = 1;
	while (1)
	{
		i = 0;
		while (i < phi->nb_phi)
		{
			if (check_dead(ph, i, &z) == 1)
				return (1);
			i++;
			if (z == phi->nb_phi)
				return (1);
		}
		if (usleep(200) == 1)
			return (error(U_SLEEP), 1);
	}
}

static int	check_dead(t_phi *phi, int i, int *z)
{
	if (pthread_mutex_lock(&phi->data->mut_print) != 0)
		return (error(MUT_LOCK), 1);
	if (get_time() - phi[i].ti_lt_meal >= phi->data->ti_died)
	{
		if (phi->data->is_dead != 1)
		{
			printf("%lld", get_time() - phi->data->start_pg);
			printf(" %d %s\n", phi[i].wh_phi, DEAD);
			phi->data->is_dead = 1;
		}
		if (pthread_mutex_unlock(&phi->data->mut_print) != 0)
			return (error(MUT_UNLOCK), 1);
		return (1);
	}
	if (phi->data->max_meal != -1)
	{
		if (phi[i].nb_meal == phi->data->max_meal)
			*z += 1;
	}
	if (pthread_mutex_unlock(&phi->data->mut_print) != 0)
		return (error(MUT_UNLOCK), 1);
	return (0);
}
