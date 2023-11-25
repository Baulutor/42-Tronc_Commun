/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/14 14:59:38 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_events(t_phi *phi, char *status)
{
	if (pthread_mutex_lock(&phi->data->mut_print) != 0)
		return (1);
	if (phi->data->is_dead == 0)
	{
		printf("%lld", get_time() - phi->data->start_pg);
		printf(" %d %s\n", phi->wh_phi, status);
	}
	if (pthread_mutex_unlock(&phi->data->mut_print) != 0)
		return (1);
	return (0);
}
