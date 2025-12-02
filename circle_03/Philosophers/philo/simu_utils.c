/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:59:48 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/26 16:09:11 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_timestamp(void)
{
	struct timeval	clock;
	long			timestamp;

	gettimeofday(&clock, NULL);
	timestamp = (clock.tv_sec * 1000) + (clock.tv_usec / 1000);
	return (timestamp);
}

void	get_accurate_sleep(int sleep_time)
{
	long	start_tmstp;
	long	current_tmstp;

	start_tmstp = get_timestamp();
	while (1)
	{
		current_tmstp = get_timestamp();
		if ((current_tmstp - start_tmstp) >= sleep_time)
			break ;
		usleep(100);
	}
}

void	print_safe(t_philo *philo, char *src)
{
	long	time;
	t_param	*param;

	param = philo->param;
	pthread_mutex_lock(&param->mutex_end);
	pthread_mutex_lock(&param->print_safe);
	if (param->end == 0)
	{
		time = get_timestamp() - param->start_simu_timestamp;
		printf("%ld %d %s", time, philo->id, src);
	}
	pthread_mutex_unlock(&param->mutex_end);
	pthread_mutex_unlock(&param->print_safe);
}

void	destroy_mutexes(pthread_mutex_t *forks, t_philo *philos, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].mutex_last_meal_tmstp);
		i++;
	}
	pthread_mutex_destroy(&param->print_safe);
	pthread_mutex_destroy(&param->mutex_philo_satisfied);
	pthread_mutex_destroy(&param->mutex_end);
}
