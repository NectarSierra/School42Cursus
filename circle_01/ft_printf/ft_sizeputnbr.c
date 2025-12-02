/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeputnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:42:57 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 10:19:38 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sizeputnbr(int arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (1);
	if (arg == -2147483648)
		return (11);
	if (arg < 0)
	{
		i++;
		arg *= -1;
	}
	while (arg > 0)
	{
		arg = arg / 10;
		i++;
	}
	return (i);
}

int	ft_sizeuputnbr(unsigned int arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		return (1);
	if (arg < 0)
		arg -= arg;
	while (arg > 0)
	{
		arg = arg / 10;
		i++;
	}
	return (i);
}
