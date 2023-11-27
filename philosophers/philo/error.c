/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:27 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/27 12:47:27 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_bis(int ret);

void	error(int ret)
{
	if (ret == MALLOC)
		write(2, "Error : malloc function\n", 24);
	else if (ret == IN_MUTEX)
		write(2, "Error : fail to mutex_init\n", 27);
	else if (ret == NB_PARAM)
		write(2, "Error : wrong numbers of parameters\n", 36);
	else if (ret == POS_NB)
		write(2, "Error : please put only positive numbers\n", 41);
	else if (ret == BIG_NB)
		write(2, "Error : please write a number not this big\n", 43);
	else if (ret == ERR_TIME)
		write(2, "Error : cannot get the time\n", 28);
	else if (ret == U_SLEEP)
		write(2, "Error : usleep function didn't work\n", 36);
	else if (ret == TH_CREATE)
		write(2, "Error : pthread_create function didn't work\n", 44);
	else if (ret == TH_JOIN)
		write(2, "Error : pthread_join function didn't work\n", 42);
	else if (ret == MUT_DES)
		write(2, "Error : mutex_destroy function didn't work\n", 43);
	error_bis(ret);
}

void	error_bis(int ret)
{
	if (ret == MUT_LOCK)
		write(2, "Error : mutex_lock function didn't work\n", 40);
	else if (ret == MUT_UNLOCK)
		write(2, "Error : mutex_unlock function didn't work\n", 42);
	else if (ret == NB_PHI)
		write(2, "Error : please put only 1 to 200 philosophers\n", 46);
}
