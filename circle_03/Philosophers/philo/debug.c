/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:07:10 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/16 10:16:21 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	debug_print_params(t_param *param)
{
	printf("[DEBUG] param->n_of_philos: %d\n", param->n_of_philos);
	printf("[DEBUG] param->time_to_die: %d\n", param->time_to_die);
	printf("[DEBUG] param->time_to_eat: %d\n", param->time_to_eat);
	printf("[DEBUG] param->time_to_sleep: %d\n", param->time_to_sleep);
	printf("[DEBUG] param->n_of_eat_required: %d\n", param->n_of_eat_required);
}

void	debug_print_forks(t_philo *p, int n_of_philos)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		printf("%d<-%d->%d\n", p[i].id_l_fork, p[i].id, p[i].id_r_fork);
		i++;
	}
}
