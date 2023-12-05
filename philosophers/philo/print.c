/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/27 20:40:25 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_events(t_phi *phi, char *status)
{
	if (pthread_mutex_lock(&phi->data->mut_print) != 0)
		return (error(MUT_LOCK), 1);
	pthread_mutex_lock(&phi->data->death);
	if (phi->data->is_dead == 1)
		return (pthread_mutex_unlock(&phi->data->mut_print), \
				pthread_mutex_unlock(&phi->data->death), 1);
	pthread_mutex_unlock(&phi->data->death);
	printf("%lld", get_time() - phi->data->start_pg);
	printf(" %d %s\n", phi->wh_phi, status);
	if (pthread_mutex_unlock(&phi->data->mut_print) != 0)
		return (error(MUT_UNLOCK), 1);
	return (0);
}
