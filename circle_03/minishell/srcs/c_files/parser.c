/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:57:50 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/18 13:11:08 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
void	print_cmds(t_cmd *cmds)
{
	int		i;
	t_cmd	*cur = cmds;
	t_redir	*r;

	printf("======== CMD DEBUG ========\n");
	while (cur)
	{
		printf("CMD:\n");
		if (cur->args)
		{
			i = 0;
			while (cur->args[i])
			{
				printf("  arg[%d]: \"%s\"\n", i, cur->args[i]);
				i++;
			}
		}
		else
			printf("  args: (null)\n");
		r = cur->redirs;
		while (r)
		{
			printf("  redir: %s \"%s\" (quoted: %c)\n",
				redir_type_str(r->type),
				r->filename,
				r->quoted ? r->quoted : '-');
			r = r->next;
		}
		printf("  heredoc_fd: %d\n", cur->heredoc_fd);
		printf("  pipe_next:  %d\n", cur->pipe_next);
		printf("  from_expansion: %d\n", cur->from_expansion);
		cur = cur->next;
		if (cur)
			printf("  --- pipe --->\n");
	}
	printf("===========================\n");
}
*/
// Main parser structure - parser.c

int	flush_arg_buffer(t_cmd *cmd, char **arg_buf, int *is_first,
	int from_expansion)
{
	int	flags;

	if (!*arg_buf)
		return (1);
	flags = 0;
	if (from_expansion)
		flags |= ARG_EXPANDED;
	if (!add_arg_token(cmd, *arg_buf, is_first, flags))
	{
		free(*arg_buf);
		return (0);
	}
	free(*arg_buf);
	*arg_buf = NULL;
	return (1);
}

int	process_node(t_token **curr, t_cmd **new, t_parse_ctx *ctx)
{
	if (!*curr)
		return (1);
	if ((*curr)->type == TOKEN_PIPE)
	{
		if (!handle_pipe_token(new, ctx))
			return (0);
		*curr = (*curr)->next;
		return (1);
	}
	if (is_redir_token((*curr)->type))
	{
		if (!*new || !handle_redir_token(curr, *new, ctx))
			return (0);
		return (1);
	}
	if (!*new || !handle_word_token(*curr, *new, ctx))
		return (0);
	*curr = (*curr)->next;
	return (1);
}

int	process_token_node(t_token **tokens, t_cmd **new, t_parse_ctx *ctx)
{
	t_token_type	type;
	t_token			*current;

	if (!*tokens)
		return (1);
	current = *tokens;
	type = current->type;
	if (!process_node(tokens, new, ctx))
		return (0);
	if (type == TOKEN_WORD && *tokens == current)
		*tokens = current->next;
	return (1);
}

int	process_tokens_loop(t_token *tokens, t_cmd_bundle *b,
	t_parse_ctx *ctx, char **arg_buf)
{
	while (tokens)
	{
		if (!b->new)
			b->new = create_cmd_node();
		if (!process_token_node(&tokens, &b->new, ctx))
		{
			free(*arg_buf);
			free_commands(b->head);
			return (0);
		}
	}
	if (b->new)
		add_cmd(&b->head, &b->last, &b->new);
	return (1);
}

int	parse_tokens(t_token *tokens, t_cmd **cmds, char **env, int *e)
{
	t_cmd_bundle	b;
	int				is_first;
	char			*arg_buf;
	int				arg_buf_quote;
	t_parse_ctx		ctx;

	b.head = NULL;
	b.last = NULL;
	b.new = NULL;
	is_first = 1;
	arg_buf = NULL;
	arg_buf_quote = 0;
	ctx = (t_parse_ctx){&b.new, &b.head, &b.last, &is_first, &arg_buf, env, e,
		0, &arg_buf_quote};
	if (!process_tokens_loop(tokens, &b, &ctx, &arg_buf))
		return (0);
	if (!flush_arg_buffer(b.new, &arg_buf, &is_first, ctx.arg_buf_expan))
		return (free_commands(b.head), 0);
	ctx.arg_buf_expan = 0;
	*(ctx.arg_buf_quote) = 0;
	if (b.new)
		add_cmd(&b.head, &b.last, &b.new);
	*cmds = b.head;
	return (1);
}
