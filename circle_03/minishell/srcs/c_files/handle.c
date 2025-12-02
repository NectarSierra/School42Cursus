/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:09:26 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 13:25:48 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
void	handle_execve(t_proc_ctx *pctx)
{
	if (!pctx->cmd_path)
	{
		if (pctx->pipe_fd[0] != -1 && pctx->pipe_fd[0] > 2)
			close(pctx->pipe_fd[0]);
		if (pctx->pipe_fd[1] != -1 && pctx->pipe_fd[1] > 2)
			close(pctx->pipe_fd[1]);
		if (pctx->input_fd != STDIN_FILENO && pctx->input_fd > 2)
			close(pctx->input_fd);
		safe_exit(pctx->exec->all_cmds, pctx->exec->env, 127);
	}
	execve(pctx->cmd_path, pctx->cmd->args, *pctx->exec->env);
	perror(SHNAME ": execve");
	safe_exit(pctx->exec->all_cmds, pctx->exec->env, *pctx->exec->exit_code);
}
	*/

void	handle_execve(t_proc_ctx *pctx)
{
	struct stat	sb;

	if (!pctx->cmd_path)
	{
		if (pctx->pipe_fd[0] != -1 && pctx->pipe_fd[0] > 2)
			close(pctx->pipe_fd[0]);
		if (pctx->pipe_fd[1] != -1 && pctx->pipe_fd[1] > 2)
			close(pctx->pipe_fd[1]);
		if (pctx->input_fd != STDIN_FILENO && pctx->input_fd > 2)
			close(pctx->input_fd);
		safe_exit(pctx->exec->all_cmds, pctx->exec->env, 127);
	}
	if (stat(pctx->cmd_path, &sb) == 0)
	{
		if (!S_ISREG(sb.st_mode)
			|| !(sb.st_mode & S_IXUSR || sb.st_mode & S_IXGRP
				|| sb.st_mode & S_IXOTH))
		{
			write(STDERR_FILENO, SHNAME ": Permission denied\n", 25);
			safe_exit(pctx->exec->all_cmds, pctx->exec->env, 126);
		}
	}
	execve(pctx->cmd_path, pctx->cmd->args, *pctx->exec->env);
	write(STDERR_FILENO, SHNAME ": execve failed\n", 20);
	safe_exit(pctx->exec->all_cmds, pctx->exec->env, 127);
}

int	handle_outfile_redir(t_redir *r, int *has_stdout)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (r->type == R_APPEND)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(r->filename, flags, 0644);
	if (fd == -1)
	{
		err("minishell: ", r->filename, ": Cannot open for writing\n");
		return (0);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		err("minishell: dup2 failed on outfile\n", NULL, NULL);
		return (0);
	}
	close(fd);
	*has_stdout = 1;
	return (1);
}

int	handle_infile_redir(t_redir *r, int *has_stdin)
{
	int	fd;

	fd = open(r->filename, O_RDONLY);
	if (fd == -1)
		return (err(SHNAME ": line 1: ", r->filename, ": " ERR_NO_FILE), 0);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (err(SHNAME ": dup2 failed on infile\n", NULL, NULL), 0);
	}
	close(fd);
	*has_stdin = 1;
	return (1);
}

int	handle_redir_file_fd(t_redir *r, int *has_stdin, int *has_stdout)
{
	if (r->type == R_IN)
		return (handle_infile_redir(r, has_stdin));
	else if (r->type == R_OUT || r->type == R_APPEND)
		return (handle_outfile_redir(r, has_stdout));
	return (1);
}

int	handle_single_redirection(t_cmd *cmd, t_redir *r, t_exec_context *ctx,
	t_fd_state *fds)
{
	if (r->type == R_HEREDOC)
	{
		cmd->heredoc_fd = open_heredoc_fd(r->filename);
		if (cmd->heredoc_fd == -1)
			safe_exit(ctx->all_cmds, ctx->env, 1);
		unlink(r->filename);
		return (1);
	}
	return (handle_redir_file_fd(r, &fds->has_stdin, &fds->has_stdout));
}
