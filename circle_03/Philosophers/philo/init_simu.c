/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:06 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/26 16:09:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*init_philos(t_param *param, int n_philos, pthread_mutex_t *forks)
{
	t_philo	*philos;
	int		i;
	int		total_eaten;

	philos = malloc(n_philos * sizeof(t_philo));
	if (!philos)
		return (write(2, "Failed: malloc\n", 15), NULL);
	i = 0;
	while (i < n_philos)
	{
		philos[i].id = i + 1;
		philos[i].id_l_fork = i;
		philos[i].id_r_fork = (i + 1) % n_philos;
		philos[i].mutex_l_fork = &forks[philos[i].id_l_fork];
		philos[i].mutex_r_fork = &forks[philos[i].id_r_fork];
		total_eaten = param->n_of_eat_required;
		if (pthread_mutex_init(&philos[i].mutex_last_meal_tmstp, NULL) != 0)
			return (free(philos), write(2, "Failed: mutex_init\n", 19), NULL);
		philos[i].total_eaten = total_eaten;
		philos[i].param = param;
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_forks(int n_forks)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(n_forks * sizeof(pthread_mutex_t));
	if (!forks)
		return (write(2, "Failed: malloc", 15), NULL);
	i = 0;
	while (i < n_forks)
	{
		if (pthread_mutex_init(&forks[i++], NULL) != 0)
			return (free(forks), write(2, "Failed: mutex_init\n", 19), NULL);
	}
	return (forks);
}

pthread_t	*start_simu(t_philo *philos, int n_philos)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(n_philos * sizeof(pthread_t));
	if (!threads)
		return (write(2, "Failed: malloc\n", 15), NULL);
	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_lock(&philos[i].mutex_last_meal_tmstp);
		philos[i].last_meal_timestamp = get_timestamp();
		pthread_mutex_unlock(&philos[i].mutex_last_meal_tmstp);
		if (pthread_create(&threads[i], NULL, &philo_cycle, &philos[i]) != 0)
		{
			free(threads);
			return (write(2, "Failed: pthread_create\n", 23), NULL);
		}
		i++;
	}
	return (threads);
}

void	wait_for_each_threads(pthread_t *threads, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

int	init_simu(t_param *param)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*threads;

	forks = init_forks(param->n_of_philos);
	if (!forks)
		return (free(param), -1);
	philos = init_philos(param, param->n_of_philos, forks);
	if (!philos)
		return (free(param), free(forks), -1);
	param->start_simu_timestamp = get_timestamp();
	threads = start_simu(philos, param->n_of_philos);
	if (!threads)
		return (free(param), free(forks), free(philos), -1);
	monitor_philos(philos, param);
	wait_for_each_threads(threads, param->n_of_philos);
	destroy_mutexes(forks, philos, param);
	return (free(param), free(forks), free(philos), free(threads), 1);
}
