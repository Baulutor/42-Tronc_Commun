/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/27 12:50:45 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *data);
static int	ck_finish(t_philo *phi, t_phi *ph);
static int	ck_max_meal(t_phi *phi);

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
	if (pthread_mutex_destroy(&struc->mut_print) != 0)
		return (error(MUT_DES), 1);
	return (0);
}

static void	*routine(void *data)
{
	t_phi	*phi;

	phi = (t_phi *)data;
	if (phi->data->nb_phi == 1)
		only_one_phi(phi);
	if ((phi->wh_phi % 2) == 0)
	{
		thinking(phi);
		ft_usleep(phi->data->ti_eat);
	}
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

static int	ck_finish(t_philo *phi, t_phi *ph)
{
	int	flag;

	flag = 0;
	while (1)
	{
		if (pthread_mutex_lock(&phi->mut_print) != 0)
			return (error(MUT_LOCK), 1);
		if (phi->is_dead == 1)
			flag = 1;
		if (pthread_mutex_unlock(&phi->mut_print) != 0)
			return (error(MUT_UNLOCK), 1);
		if (flag == 1)
			return (0);
		if (pthread_mutex_lock(&phi->mut_print) != 0)
			return (error(MUT_LOCK), 1);
		if (phi->max_meal != -1 && ck_max_meal(ph) == 1)
			flag = 2;
		if (pthread_mutex_unlock(&phi->mut_print) != 0)
			return (error(MUT_UNLOCK), 1);
		if (flag == 2)
			return (0);
	}
}

static int	ck_max_meal(t_phi *phi)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < phi->data->nb_phi)
	{
		if (phi[i].nb_meal == phi->data->max_meal)
			j++;
		i++;
		if (j == phi->data->nb_phi)
			return (1);
	}
	return (0);
}
