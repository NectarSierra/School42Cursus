/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:56:25 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/21 10:15:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_satisfied(t_param *param)
{
	int	satisfied;

	pthread_mutex_lock(&param->mutex_philo_satisfied);
	satisfied = param->philo_satisfied;
	pthread_mutex_unlock(&param->mutex_philo_satisfied);
	if (satisfied == 0)
	{
		pthread_mutex_lock(&param->mutex_end);
		param->end = 1;
		pthread_mutex_unlock(&param->mutex_end);
		return (1);
	}
	else
		return (0);
}

void	print_safe_died(t_philo *philo, char *src)
{
	long	time;
	t_param	*param;

	param = philo->param;
	pthread_mutex_lock(&param->print_safe);
	time = get_timestamp() - param->start_simu_timestamp;
	printf("%ld %d %s", time, philo->id, src);
	pthread_mutex_unlock(&param->print_safe);
}

void	monitor_philos(t_philo *philos, t_param *param)
{
	int		i;
	long	time;

	while (1)
	{
		i = 0;
		while (i < param->n_of_philos)
		{
			pthread_mutex_lock(&philos[i].mutex_last_meal_tmstp);
			time = get_timestamp() - philos[i].last_meal_timestamp;
			pthread_mutex_unlock(&philos[i].mutex_last_meal_tmstp);
			if (time > param->time_to_die)
			{
				pthread_mutex_lock(&param->mutex_end);
				param->end = 1;
				pthread_mutex_unlock(&param->mutex_end);
				print_safe_died(&philos[i], "died\n");
				return ;
			}
			i++;
		}
		if (check_satisfied(param) == 1)
			return ;
		usleep (1000);
	}
}
