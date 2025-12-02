/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:40:47 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:48:23 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_var_char(char c)
{
	return (ft_is_alpha(c) || c == '_');
}

int	is_var_name_char(char c)
{
	return (ft_is_alpha(c) || ft_is_digit(c) || c == '_');
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_is_empty(char *str)
{
	while (*str)
	{
		if (!ft_is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_quoted(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}
