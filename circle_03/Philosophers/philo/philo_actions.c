/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:57:42 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/21 09:24:00 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	locking_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->mutex_l_fork);
		print_safe(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->mutex_r_fork);
		print_safe(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->mutex_r_fork);
		print_safe(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->mutex_l_fork);
		print_safe(philo, "has taken a fork\n");
	}
}

void	unlocking_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(philo->mutex_l_fork);
		pthread_mutex_unlock(philo->mutex_r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex_r_fork);
		pthread_mutex_unlock(philo->mutex_l_fork);
	}
}

int	is_eating(t_param *param, t_philo *philo, int time_to_eat)
{
	locking_forks(philo);
	pthread_mutex_lock(&philo->mutex_last_meal_tmstp);
	philo->last_meal_timestamp = get_timestamp();
	pthread_mutex_unlock(&philo->mutex_last_meal_tmstp);
	print_safe(philo, "is eating\n");
	get_accurate_sleep(time_to_eat);
	unlocking_forks(philo);
	pthread_mutex_lock(&param->print_safe);
	pthread_mutex_unlock(&param->print_safe);
	if (philo->total_eaten > 0)
		philo->total_eaten -= 1;
	if (philo->total_eaten == 0)
	{
		pthread_mutex_lock(&param->mutex_philo_satisfied);
		philo->total_eaten = -1;
		param->philo_satisfied -= 1;
		pthread_mutex_unlock(&param->mutex_philo_satisfied);
		return (1);
	}
	return (-1);
}

void	is_sleeping(t_philo *philo, int time_to_sleep)
{
	print_safe(philo, "is sleeping\n");
	get_accurate_sleep(time_to_sleep);
}
