/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:01:03 by dbaule            #+#    #+#             */
/*   Updated: 2023/11/27 20:31:41 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>

# define FORK "has taken a fork"
# define SLEEP "is sleeping"
# define EATING "is eating"
# define THINKING "is thinking"
# define DEAD "is dead"

typedef enum v_error
{
	MALLOC,
	IN_MUTEX,
	NB_PARAM,
	POS_NB,
	BIG_NB,
	ERR_TIME,
	U_SLEEP,
	TH_CREATE,
	TH_JOIN,
	MUT_LOCK,
	MUT_UNLOCK,
	MUT_DES,
	NB_PHI,
}	t_error;

typedef struct v_philo
{
	int				nb_phi;
	long			ti_died;
	long			ti_eat;
	long			ti_sleep;
	long			max_meal;
	long long		start_pg;
	pthread_mutex_t	mut_print;
	bool			is_dead;
}	t_philo;

typedef struct v_phi
{
	int				wh_phi;
	long			nb_meal;
	unsigned long	ti_lt_meal;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	bool			l_f;
	bool			*r_f;
	pthread_t		phi;
	pthread_t		dead;
	t_philo			*data;
}	t_phi;

int				parsing(int argc, char **argv);
int				init(t_philo *phi, char **argv);
int				init_phi(t_phi *ph, t_philo *struc);

void			error(int ret);

int				exec(t_philo *struc, t_phi *phi);
int				eating(t_phi *phi);
int				sleeping(t_phi *phi);
int				thinking(t_phi *phi);

int				print_events(t_phi *phi, char *status);
void			only_one_phi(t_phi *phi);
unsigned long	ft_atoi(const char *a);
int				ft_strlen(char *av);
int				destroying_mutex(t_philo *struc, int i, t_phi *phi);
int				ft_strncmp(const char *a, const char *b, size_t n);
long long		get_time(void);
int				ft_usleep(unsigned long i);
#endif