/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:18:01 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 09:30:03 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_input_for_next_pipe(int pipe_fd[2], int *input_fd)
{
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
	if (*input_fd != STDIN_FILENO)
		close(*input_fd);
	*input_fd = pipe_fd[0];
}

static void	handle_signal_output(int sig, int *sigint_shown, int *sigquit_shown)
{
	if (sig == SIGINT && !*sigint_shown)
	{
		write(STDOUT_FILENO, "\n", 1);
		*sigint_shown = 1;
	}
	else if (sig == SIGQUIT && !*sigquit_shown)
	{
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		*sigquit_shown = 1;
	}
}

static void	handle_child_status(int status, int *exit_code,
									int *sigint_shown, int *sigquit_shown)
{
	int	sig;

	if (WIFEXITED(status))
		*exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGPIPE)
			return ;
		handle_signal_output(sig, sigint_shown, sigquit_shown);
		*exit_code = 128 + sig;
	}
}

void	wait_for_children(int *exit_code)
{
	int	status;
	int	sigint_shown;
	int	sigquit_shown;

	sigint_shown = 0;
	sigquit_shown = 0;
	while (wait(&status) > 0)
		handle_child_status(status, exit_code, &sigint_shown, &sigquit_shown);
}

int	is_builtin_no_pipe(t_cmd *cmd, int input_fd)
{
	return (!cmd->pipe_next && input_fd == STDIN_FILENO
		&& is_builtin(cmd->args[0]));
}
