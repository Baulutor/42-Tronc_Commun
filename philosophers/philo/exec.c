/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/12/05 17:16:39 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ck_finish(t_philo *phi, t_phi *ph);
static int	check_dead(t_phi *phi, int i);
static int	ck_max_meal(t_phi *phi);
static void	destroy_thread(t_phi *phi, int j);

int	exec(t_philo *struc, t_phi *phi)
{
	int	j;

	j = 0;
	while (j < struc->nb_phi)
	{
		if (pthread_create(&phi[j].phi, NULL, routine, &phi[j]) != 0)
			return (destroy_thread(phi, j), error(TH_CREATE), 1);
		j++;
	}
	pthread_mutex_lock(&struc->mut_start);
	struc->start_pg = get_time();
	pthread_mutex_unlock(&struc->mut_start);
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

static int	ck_finish(t_philo *phi, t_phi *ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < phi->nb_phi)
		{
			if (check_dead(ph, i) == 1)
				return (1);
			i++;
		}
		if (ft_usleep(1) == 1)
			return (error(U_SLEEP), 1);
	}
}

static int	check_dead(t_phi *phi, int i)
{
	if (pthread_mutex_lock(&phi->data->mut_ti_lt_meal) != 0)
		return (error(MUT_LOCK), 1);
	if (get_time() - phi[i].ti_lt_meal >= phi->data->ti_died)
	{
		if (pthread_mutex_unlock(&phi->data->mut_ti_lt_meal) != 0)
			return (error(MUT_UNLOCK), 1);
		if (pthread_mutex_lock(&phi->data->death) != 0)
			return (error(MUT_LOCK), 1);
		phi->data->is_dead = 1;
		if (pthread_mutex_unlock(&phi->data->death) != 0)
			return (error(MUT_UNLOCK), 1);
		printf("%lld", get_time() - phi->data->start_pg);
		printf(" %d %s\n", phi[i].wh_phi, DEAD);
		return (1);
	}
	if (pthread_mutex_unlock(&phi->data->mut_ti_lt_meal) != 0)
		return (error(MUT_UNLOCK), 1);
	if (phi->data->max_meal != -1)
	{
		if (ck_max_meal(phi) == 1)
			return (1);
	}
	return (0);
}

static int	ck_max_meal(t_phi *phi)
{
	if (pthread_mutex_lock(&phi->data->phi_eat) != 0)
		return (error(MUT_LOCK), 1);
	if (phi->data->table_meal == phi->data->nb_phi)
	{
		if (pthread_mutex_lock(&phi->data->death) != 0)
			return (error(MUT_LOCK), 1);
		phi->data->is_dead = 1;
		if (pthread_mutex_unlock(&phi->data->death) != 0)
			return (error(MUT_UNLOCK), 1);
		return (pthread_mutex_unlock(&phi->data->phi_eat), 1);
	}
	if (pthread_mutex_unlock(&phi->data->phi_eat) != 0)
		return (error(MUT_UNLOCK), 1);
	return (0);
}

static void	destroy_thread(t_phi *phi, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (pthread_join(phi[j].phi, NULL) != 0)
			return (error(TH_JOIN));
		i++;
	}
}
