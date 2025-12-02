/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboland <rboland@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:34:34 by rboland           #+#    #+#             */
/*   Updated: 2025/07/18 09:34:34 by rboland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	cleanup_config2(t_config *config)
{
	if (config->map)
	{
		ft_free_split(config->map);
		config->map = NULL;
	}
	get_next_line(-42);
	config->map_width = 0;
	config->map_height = 0;
}

void	cleanup_config(t_config *config)
{
	if (config->north_texture)
	{
		free(config->north_texture);
		config->north_texture = NULL;
	}
	if (config->south_texture)
	{
		free(config->south_texture);
		config->south_texture = NULL;
	}
	if (config->west_texture)
	{
		free(config->west_texture);
		config->west_texture = NULL;
	}
	if (config->east_texture)
	{
		free(config->east_texture);
		config->east_texture = NULL;
	}
	cleanup_config2(config);
}
