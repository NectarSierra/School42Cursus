/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:19:11 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 14:59:02 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_d(int arg)
{
	if (ft_putnbr(arg) == -1)
		return (-1);
	return (ft_sizeputnbr(arg));
}
