/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:19:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/17 19:44:22 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	safe_exit(t_cmd *cmds, char ***env, int code)
{
	free_commands(cmds);
	if (env && *env)
		free_strs(*env);
	exit(code);
}

int	open_heredoc_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("heredoc open");
	return (fd);
}

int	setup_pipe(int pipe_next, int pipe_fd[2], int *exit_code)
{
	if (pipe_next)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			*exit_code = 1;
			return (-1);
		}
	}
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
	return (0);
}

int	fork_command(int *exit_code)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		*exit_code = 1;
		return (-1);
	}
	return (pid);
}
