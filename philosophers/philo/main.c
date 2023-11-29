/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:48:44 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/14 11:24:42 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	struc;
	t_phi	*phi;

	if (parsing(argc, argv) == 1)
		return (1);
	if (init(&struc, argv) == 1)
		return (2);
	phi = malloc (sizeof(t_phi) * struc.nb_phi);
	if (!phi)
		return (pthread_mutex_destroy(&struc.mut_print), 3);
	if (init_phi(phi, &struc) == 1)
		return (free(phi), 4);
	if (exec(&struc, phi) == 1)
		return (destroying_mutex(&struc, struc.nb_phi, phi), \
		free(phi), 5);
	if (destroying_mutex(&struc, struc.nb_phi, phi) == 1)
		return (6);
	free(phi);
	return (0);
}
