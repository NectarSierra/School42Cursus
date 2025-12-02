/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:57 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:48:35 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// other utils

void	err(const char *msg1, const char *msg2, const char *msg3)
{
	if (msg1)
		write(STDERR_FILENO, msg1, ft_strlen(msg1));
	if (msg2)
		write(STDERR_FILENO, msg2, ft_strlen(msg2));
	if (msg3)
		write(STDERR_FILENO, msg3, ft_strlen(msg3));
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_is_numeric(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_interactive_shell(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}
