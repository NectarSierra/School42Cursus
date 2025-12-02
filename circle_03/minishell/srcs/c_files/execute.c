/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:41 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 10:23:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	execute_redirection_only(t_cmd *cmd, t_exec_context *ctx,
	int pipe_fd[2], int input_fd)
{
	pid_t	pid;

	if (setup_pipe(cmd->pipe_next, pipe_fd, ctx->exit_code) == -1)
		return ;
	pid = fork_command(ctx->exit_code);
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		if (!apply_redirections(cmd, pipe_fd, input_fd, ctx))
			safe_exit(ctx->all_cmds, ctx->env, 1);
		safe_exit(ctx->all_cmds, ctx->env, 0);
	}
	update_input_after_fork(cmd, pipe_fd, &input_fd);
}

static int	handle_empty_or_redirect_only(t_cmd **cmds, int pipe_fd[2],
	int *input_fd, t_exec_context *ctx)
{
	t_cmd	*cmd;

	cmd = *cmds;
	if ((!cmd->args || !cmd->args[0])
		&& !cmd->redirs && cmd->heredoc_fd == -1)
	{
		return (*cmds = cmd->next, 1);
	}
	if ((!cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
		&& (cmd->redirs || cmd->heredoc_fd != -1))
	{
		execute_redirection_only(cmd, ctx, pipe_fd, *input_fd);
		return (*cmds = cmd->next, 1);
	}
	if (cmd->args && cmd->args[0] && cmd->args[0][0] == '\0')
	{
		if (cmd->from_expansion == 0)
		{
			err(SHNAME ": ", "", ": command not found\n");
			*ctx->exit_code = 127;
		}
		return (*cmds = cmd->next, 1);
	}
	return (0);
}

static void	handle_executable_command(t_cmd *cmd, int pipe_fd[2],
	int *input_fd, t_exec_context *ctx)
{
	pid_t	pid;

	if (is_builtin_no_pipe(cmd, *input_fd))
		execute_builtin_no_pipe(cmd, ctx);
	else
	{
		if (setup_pipe(cmd->pipe_next, pipe_fd, ctx->exit_code) == -1)
			return ;
		pid = fork_command(ctx->exit_code);
		if (pid == -1)
			return ;
		if (pid == 0)
			execute_child_process(cmd, pipe_fd, *input_fd, ctx);
		update_input_after_fork(cmd, pipe_fd, input_fd);
	}
}

static void	execute_single_command(t_cmd **cmds, int *input_fd,
	int pipe_fd[2], t_exec_context *ctx)
{
	t_cmd	*cmd;

	cmd = *cmds;
	if (!cmd)
		return ;
	if (handle_empty_or_redirect_only(cmds, pipe_fd, input_fd, ctx))
		return ;
	handle_executable_command(*cmds, pipe_fd, input_fd, ctx);
	*cmds = (*cmds)->next;
}

void	execute_commands(t_cmd *cmds, char ***env, int *exit_code)
{
	t_exec_context	ctx;
	int				pipe_fd[2];
	int				input_fd;

	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	ctx = (t_exec_context){cmds, env, exit_code};
	input_fd = STDIN_FILENO;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (cmds)
		execute_single_command(&cmds, &input_fd, pipe_fd, &ctx);
	wait_for_children(exit_code);
	setup_signals();
}
