/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:08:13 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/29 14:51:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_param
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_eat_required;
	long			start_simu_timestamp;
	pthread_mutex_t	print_safe;
	int				philo_satisfied;
	pthread_mutex_t	mutex_philo_satisfied;
	int				end;
	pthread_mutex_t	mutex_end;
}	t_param;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				id_l_fork;
	int				id_r_fork;
	pthread_mutex_t	*mutex_l_fork;
	pthread_mutex_t	*mutex_r_fork;
	int				total_eaten;
	long			last_meal_timestamp;
	pthread_mutex_t	mutex_last_meal_tmstp;
	t_param			*param;
}	t_philo;

// initialize_simu.c
t_philo			*init_philos(t_param *prm, int n_p, pthread_mutex_t *frks);
pthread_mutex_t	*init_forks(int n_forks);
pthread_t		*start_simu(t_philo *philos, int n_philos);
void			wait_for_each_threads(pthread_t *threads, int n_philos);
int				init_simu(t_param *param);

// param.c
int				check_overflow(int number, int digit);
int				strtoint(char *str);
int				argv_to_param(t_param *param, int argc, char **argv);
t_param			*declare_param(char **argv, int argc);

// debug.c
void			debug_print_forks(t_philo *philos, int n_of_philos);
void			debug_print_params(t_param *param);

// philo_cycle.c
void			one_philo(t_param *param, t_philo *philo);
void			delay_harmony(t_param *param, t_philo *philo);
void			*philo_cycle(void *arg);

// philo_actions.c
void			locking_forks(t_philo *philo);
void			unlocking_forks(t_philo *philo);
int				is_eating(t_param *param, t_philo *philo, int time_to_eat);
void			is_sleeping(t_philo *philo, int time_to_sleep);

// simu_utils.c
long			get_timestamp(void);
void			get_accurate_sleep(int sleep_time);
void			print_safe(t_philo *philo, char *src);
void			destroy_mutexes(pthread_mutex_t *f, t_philo *p, t_param *prm);

// monitor.c
int				check_satisfied(t_param *param);
void			print_safe_died(t_philo *philo, char *src);
void			monitor_philos(t_philo *philos, t_param *param);