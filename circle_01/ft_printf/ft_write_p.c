/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:40:02 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 15:05:12 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_free(char *res_base)
{
	free(res_base);
	return (-1);
}

int	ft_write_p(void *arg)
{
	unsigned long	res;
	char			*res_base;
	int				i;

	if (!arg)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	i = 0;
	res = (unsigned long) arg;
	if (write(1, "0x", 2) == -1)
		return (-1);
	res_base = ft_tobase(res, "0123456789abcdef");
	if (!res_base)
		return (-1);
	while (res_base[i])
	{
		if (write(1, &res_base[i++], 1) == -1)
			ft_free(res_base);
	}
	free(res_base);
	return (i + 2);
}
