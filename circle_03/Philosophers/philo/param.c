/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:58:12 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/21 13:30:16 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_overflow(int number, int digit)
{
	if (number > 214748364 || (number == 214748364 && digit > 7))
		return (-1);
	else
		return (0);
}

int	strtoint(char *str)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (write(2, "Error - arguments\n", 18), -1);
		if (check_overflow(number, str[i] - '0'))
			return (write(2, "Error - int overflow\n", 21), -1);
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number);
}

int	argv_to_param(t_param *param, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (strtoint(argv[i]) == -1)
			return (1);
		i++;
	}
	param->n_of_philos = strtoint(argv[1]);
	if (param->n_of_philos >= 256)
		param->n_of_philos = 256;
	param->time_to_die = strtoint(argv[2]);
	param->time_to_eat = strtoint(argv[3]);
	param->time_to_sleep = strtoint(argv[4]);
	if (argv[5] != NULL)
		param->n_of_eat_required = strtoint(argv[5]);
	else
		param->n_of_eat_required = -1;
	return (0);
}

t_param	*declare_param(char **argv, int argc)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (write(2, "Failed: malloc\n", 15), NULL);
	if (argv_to_param(param, argc, argv))
		return (free(param), NULL);
	if (pthread_mutex_init(&param->mutex_end, NULL) != 0)
		return (free(param), write(2, "Failed: mutex_init\n", 19), NULL);
	if (pthread_mutex_init(&param->print_safe, NULL) != 0)
		return (free(param), write(2, "Failed: mutex_init\n", 19), NULL);
	if (pthread_mutex_init(&param->mutex_philo_satisfied, NULL) != 0)
		return (free(param), write(2, "Failed: mutex_init\n", 19), NULL);
	param->philo_satisfied = param->n_of_philos;
	param->end = 0;
	return (param);
}
