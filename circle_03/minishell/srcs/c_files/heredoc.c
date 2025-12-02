/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:41:45 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 14:27:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	reset_heredoc_prompt_stream(void)
{
	if (!isatty(STDIN_FILENO) && rl_outstream)
	{
		fclose(rl_outstream);
		rl_outstream = stdout;
	}
}

int	check_heredoc(t_redir *r, char *line)
{
	if (!line)
	{
		err("warning: here-document at line 2 delimited", NULL, NULL);
		err(" by end-of-file (wanted `EOF')\n", NULL, NULL);
		return (1);
	}
	if (ft_strcmp(line, r->filename) == 0)
		return (1);
	return (0);
}

// static char	*open_heredoc_file(int id, int *fd)
// {
// 	char	*id_str;
// 	char	*tmp_name;

// 	id_str = ft_itoa(id);
// 	tmp_name = ft_strjoin(".heredoc_tmp_", id_str);
// 	free(id_str);
// 	*fd = open(tmp_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (*fd < 0)
// 	{
// 		free(tmp_name);
// 		return (NULL);
// 	}
// 	return (tmp_name);
// }

static int	loop_heredoc_lines(t_heredoc_ctx *ctx)
{
	char	*line;

	while (1)
	{
		handle_heredoc_prompt_stream();
		line = readline("> ");
		reset_heredoc_prompt_stream();
		if (g_last_signal == SIGINT)
			return (handle_heredoc_interrupt(ctx->fd, line,
					ctx->exit_code, ctx->tmp_name));
		if (check_heredoc(ctx->r, line))
		{
			free(line);
			break ;
		}
		process_heredoc_line(line, ctx);
	}
	return (1);
}

static int	process_heredoc(t_redir *r, int id, char **env, int *exit_status)
{
	t_heredoc_ctx	ctx;
	char			*id_str;

	id_str = ft_itoa(id);
	ctx.tmp_name = ft_strjoin(".heredoc_tmp_", id_str);
	free(id_str);
	ctx.fd = open(ctx.tmp_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ctx.fd < 0)
		return (free(ctx.tmp_name), 0);
	ctx.r = r;
	ctx.env = env;
	ctx.exit_code = exit_status;
	if (!loop_heredoc_lines(&ctx))
		return (0);
	close(ctx.fd);
	if (r->filename)
		free(r->filename);
	r->filename = ctx.tmp_name;
	return (1);
}

int	collect_heredocs(t_cmd *cmd, char **env, int *exit_status)
{
	t_redir	*r;
	int		id;

	id = 0;
	r = cmd->redirs;
	setup_heredoc_signals();
	while (r)
	{
		if (r->type == R_HEREDOC)
		{
			if (!process_heredoc(r, id++, env, exit_status))
			{
				setup_signals();
				return (0);
			}
		}
		r = r->next;
	}
	setup_signals();
	return (1);
}
