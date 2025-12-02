/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:48:38 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 13:50:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_heredoc_interrupt(int fd, char *line, int *exit_status,
	char *tmp_name)
{
	free(line);
	close(fd);
	unlink(tmp_name);
	*exit_status = 130;
	setup_signals();
	return (0);
}
