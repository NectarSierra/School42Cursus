/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:31:44 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 11:46:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

volatile sig_atomic_t	g_last_signal = 0;

void	sigint_handler(int sig)
{
	g_last_signal = sig;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "^C\n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}

void	sigint_heredoc_handler(int sig)
{
	g_last_signal = sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(STDOUT_FILENO, "^C\n", 3);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	setup_signals(void)
{
	g_last_signal = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_heredoc_signals(void)
{
	g_last_signal = 0;
	signal(SIGINT, sigint_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
}
