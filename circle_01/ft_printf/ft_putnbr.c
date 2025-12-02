/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:43:19 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 13:46:32 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	char	tochar;

	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
	}
	else if (nbr < 0)
	{
		if (write(1, "-", 1) == -1 || ft_putnbr(-nbr) == -1)
			return (-1);
	}
	else if (nbr > 9)
	{
		if (ft_putnbr(nbr / 10) == -1 || ft_putnbr(nbr % 10) == -1)
			return (-1);
	}
	else
	{
		tochar = nbr + '0';
		if (write(1, &tochar, 1) == -1)
			return (-1);
	}
	return (1);
}

int	ft_uputnbr(unsigned int nbr)
{
	char	tochar;

	if (nbr > 9)
	{
		if (ft_putnbr(nbr / 10) == -1 || ft_putnbr(nbr % 10) == -1)
			return (-1);
	}
	else
	{
		tochar = nbr + '0';
		if (write(1, &tochar, 1) == -1)
			return (-1);
	}
	return (1);
}
