/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:59:19 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 13:22:28 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_u(unsigned int arg)
{
	if (ft_uputnbr(arg) == -1)
		return (-1);
	return (ft_sizeuputnbr(arg));
}
