/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:45:01 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/26 10:24:48 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	one_philo(t_param *param, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_last_meal_tmstp);
	philo->last_meal_timestamp = get_timestamp();
	pthread_mutex_unlock(&philo->mutex_last_meal_tmstp);
	print_safe(philo, "has taken a fork\n");
	get_accurate_sleep(param->time_to_die);
}

void	delay_harmony(t_param *param, t_philo *philo)
{
	if (philo->id % 2 == 1)
		usleep(param->time_to_eat * 1000 / 2);
}

void	*philo_cycle(void *arg)
{
	t_philo	*philo;
	t_param	*param;

	philo = (t_philo *) arg;
	param = philo->param;
	if (param->n_of_philos == 1)
		return (one_philo(param, philo), NULL);
	delay_harmony(param, philo);
	while (1)
	{
		pthread_mutex_lock(&param->mutex_end);
		if (param->end == 1)
			return (pthread_mutex_unlock(&param->mutex_end), NULL);
		pthread_mutex_unlock(&param->mutex_end);
		is_eating(param, philo, param->time_to_eat);
		is_sleeping(philo, param->time_to_sleep);
		print_safe(philo, "is thinking\n");
	}
}
