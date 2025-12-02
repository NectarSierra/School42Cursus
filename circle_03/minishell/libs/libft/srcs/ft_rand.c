/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:34:39 by matsauva          #+#    #+#             */
/*   Updated: 2025/03/06 14:35:02 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_rand(void)
{
	static unsigned int	seed;
	void				*malloc_seed;

	if (seed == 0)
	{
		malloc_seed = malloc(1);
		if (!malloc_seed)
			return (0);
		seed = (unsigned int)(unsigned long)malloc_seed;
		free(malloc_seed);
	}
	seed = (seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return (seed);
}
