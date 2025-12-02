/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:41:50 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 13:04:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_input_after_fork(t_cmd *cmd, int pipe_fd[2], int *input_fd)
{
	if (cmd->pipe_next)
		update_input_for_next_pipe(pipe_fd, input_fd);
	else if (*input_fd != STDIN_FILENO)
		close(*input_fd);
}

void	execute_child_process(t_cmd *cmd, int pipe_fd[2], int input_fd,
		t_exec_context *ctx)
{
	char		*cmd_path;
	t_proc_ctx	pctx;

	if (!cmd || !cmd->args || !cmd->args[0])
		safe_exit(cmd, ctx->env, 0);
	if (cmd->args[0][0] == '\0')
	{
		err("minishell: ", ": command not found\n", NULL);
		safe_exit(ctx->all_cmds, ctx->env, 127);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!apply_redirections(cmd, pipe_fd, input_fd, ctx))
		safe_exit(ctx->all_cmds, ctx->env, 1);
	if (is_builtin(cmd->args[0]))
	{
		execute_builtin(cmd, ctx->env, ctx->exit_code, ctx->all_cmds);
		safe_exit(ctx->all_cmds, ctx->env, *ctx->exit_code);
	}
	cmd_path = path_manager(cmd->args[0], ctx);
	if (!cmd_path)
		safe_exit(ctx->all_cmds, ctx->env, *ctx->exit_code);
	pctx = (t_proc_ctx){cmd, cmd_path, input_fd, {pipe_fd[0], pipe_fd[1]},
		ctx};
	handle_execve(&pctx);
}

void	restore_and_close_std_fds(int orig_stdin, int orig_stdout)
{
	if (orig_stdin != -1)
	{
		dup2(orig_stdin, STDIN_FILENO);
		if (orig_stdin > 2)
			close(orig_stdin);
	}
	if (orig_stdout != -1)
	{
		dup2(orig_stdout, STDOUT_FILENO);
		if (orig_stdout > 2)
			close(orig_stdout);
	}
}

void	close_saved_fds(int orig_stdin, int orig_stdout)
{
	if (orig_stdin > 2)
		close(orig_stdin);
	if (orig_stdout > 2)
		close(orig_stdout);
}

void	execute_builtin_no_pipe(t_cmd *cmd, t_exec_context *ctx)
{
	int	orig_stdin;
	int	orig_stdout;

	orig_stdin = dup(STDIN_FILENO);
	orig_stdout = dup(STDOUT_FILENO);
	if (!apply_redirections(cmd, (int [2]){-1, -1}, STDIN_FILENO, ctx))
	{
		close_saved_fds(orig_stdin, orig_stdout);
		*ctx->exit_code = 1;
		return ;
	}
	if (cmd->args && cmd->args[0] && ft_strcmp(cmd->args[0], "exit") == 0)
	{
		close_saved_fds(orig_stdin, orig_stdout);
		execute_builtin(cmd, ctx->env, ctx->exit_code, ctx->all_cmds);
		return ;
	}
	execute_builtin(cmd, ctx->env, ctx->exit_code, ctx->all_cmds);
	restore_and_close_std_fds(orig_stdin, orig_stdout);
}
