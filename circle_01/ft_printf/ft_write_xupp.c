/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xupp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:11:34 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 14:58:17 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_free(char *res_base)
{
	free(res_base);
	return (-1);
}

int	ft_write_xupp(unsigned int arg)
{
	unsigned long	arg_long;
	char			*res_base;
	int				i;

	arg_long = (unsigned long)arg;
	if (arg == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	res_base = ft_tobase(arg_long, "0123456789ABCDEF");
	if (!res_base)
		return (-1);
	i = 0;
	while (res_base[i])
	{
		if (write(1, &res_base[i], 1) == -1)
			return (ft_free(res_base));
		i++;
	}
	free(res_base);
	return (i);
}
