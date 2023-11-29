/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:58 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/29 16:55:58 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		print_events(phi, SLEEP);
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
