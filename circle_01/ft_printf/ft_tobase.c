/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:55:50 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 13:46:49 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tobase(unsigned long res, char *base)
{
	int				base_size;
	unsigned long	res_size;
	int				i;
	char			*buffer;

	base_size = 0;
	i = 0;
	res_size = res;
	while (base[base_size])
		base_size++;
	while (res_size > 0)
	{
		res_size = res_size / base_size;
		i++;
	}
	buffer = malloc((i + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[i--] = '\0';
	while (res > 0)
	{
		buffer[i--] = base[res % base_size];
		res = res / base_size;
	}
	return (buffer);
}
