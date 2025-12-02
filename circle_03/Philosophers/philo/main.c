/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:57:46 by nsaillez          #+#    #+#             */
/*   Updated: 2025/05/29 14:44:59 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_param	*param;

	if (argc != 5 && argc != 6)
		return (write(2, "Error - Need 4 or 5 arguments\n", 31), -1);
	param = declare_param(argv, argc);
	if (!param)
		return (-1);
	if (param->n_of_eat_required == 0)
		return (0);
	if (init_simu(param) != 1)
		return (-1);
	return (0);
}
