/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:15:12 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/17 19:20:14 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	apply_input_if_needed(t_cmd *cmd, int input_fd, int *has_stdin)
{
	if (*has_stdin)
		return ;
	if (cmd->heredoc_fd != -1)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
		*has_stdin = 1;
	}
	else if (input_fd != STDIN_FILENO)
	{
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
		*has_stdin = 1;
	}
}

int	open_redirection_file(t_redir *redir)
{
	if (redir->type == R_IN)
		return (open(redir->filename, O_RDONLY));
	else if (redir->type == R_OUT)
		return (open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (redir->type == R_APPEND)
		return (open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644));
	else if (redir->type == R_HEREDOC)
		return (open_heredoc_fd(redir->filename));
	return (-1);
}

int	open_all_redirections(t_cmd *cmd, int temp_fds[32])
{
	t_redir	*r;
	int		i;

	i = 0;
	r = cmd->redirs;
	while (r)
	{
		temp_fds[i] = open_redirection_file(r);
		if (temp_fds[i] == -1)
		{
			if (errno == EACCES)
				err(SHNAME ": ", r->filename, ": Permission denied\n");
			else
				err(SHNAME ": ", r->filename, ": " ERR_NO_FILE);
			while (i-- > 0)
				close(temp_fds[i]);
			return (0);
		}
		r = r->next;
		i++;
	}
	return (1);
}

void	dup_redirections(t_cmd *cmd, int temp_fds[32], t_fd_state *fds)
{
	t_redir	*r;
	int		i;

	i = 0;
	r = cmd->redirs;
	while (r)
	{
		if (r->type == R_IN || r->type == R_HEREDOC)
		{
			dup2(temp_fds[i], STDIN_FILENO);
			fds->has_stdin = 1;
		}
		else if (r->type == R_OUT || r->type == R_APPEND)
		{
			dup2(temp_fds[i], STDOUT_FILENO);
			fds->has_stdout = 1;
		}
		close(temp_fds[i]);
		r = r->next;
		i++;
	}
}

int	apply_redirections(t_cmd *cmd, int pipe_fd[2],
	int input_fd, t_exec_context *ctx)
{
	int			temp_fds[1024];
	t_fd_state	fds;

	(void)ctx;
	ft_bzero(temp_fds, sizeof(temp_fds));
	fds = (t_fd_state){0, 0};
	if (!open_all_redirections(cmd, temp_fds))
		return (0);
	dup_redirections(cmd, temp_fds, &fds);
	if (!fds.has_stdout && cmd->pipe_next && pipe_fd[1] != -1)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	apply_input_if_needed(cmd, input_fd, &fds.has_stdin);
	return (1);
}
