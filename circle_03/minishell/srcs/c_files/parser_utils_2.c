/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:33 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:46:59 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Second Main parsing functions - parser_structure.c

t_redir	*create_redir(t_token **file_tok, t_token_type tok_type,
	t_parse_ctx *ctx)
{
	t_redir	*r;
	char	*filename;
	int		do_expand;
	int		quoted;

	if (!*file_tok)
		return (NULL);
	quoted = (*file_tok)->quoted;
	do_expand = (tok_type != TOKEN_HEREDOC);
	filename = concat_redir_filename(file_tok, ctx, do_expand);
	filename = safe_strdup_empty_if_needed(filename);
	if (!filename)
		return (NULL);
	r = malloc(sizeof(t_redir));
	if (!r)
		return (free(filename), NULL);
	r->filename = filename;
	r->quoted = quoted;
	r->next = NULL;
	if (!set_redir_type(r, tok_type))
		return (free(r->filename), free(r), NULL);
	return (r);
}

int	handle_redirection_token(t_token **tok, t_cmd *cmd, t_parse_ctx *ctx)
{
	t_token	*file_tok;
	t_redir	*r;

	file_tok = (*tok)->next;
	if (!file_tok || file_tok->type != TOKEN_WORD)
		return (print_syntax_error(NULL), 0);
	r = create_redir(&file_tok, (*tok)->type, ctx);
	if (!r)
		return (0);
	append_redir(cmd, r);
	*tok = file_tok;
	return (1);
}

int	handle_redir_token(t_token **tok, t_cmd *cmd, t_parse_ctx *ctx)
{
	int	flags;

	if (*(ctx->arg_buf))
	{
		flags = 0;
		if (ctx->arg_buf_expan)
			flags |= ARG_EXPANDED;
		if (!add_arg_token(cmd, *(ctx->arg_buf), ctx->is_first, flags))
		{
			free(*(ctx->arg_buf));
			return (0);
		}
		free(*(ctx->arg_buf));
		*(ctx->arg_buf) = NULL;
		ctx->arg_buf_expan = 0;
	}
	if (!handle_redirection_token(tok, cmd, ctx))
		return (0);
	if (*tok && (*tok)->type == TOKEN_WORD)
		*tok = (*tok)->next;
	return (1);
}

int	handle_word_token(t_token *tok, t_cmd *cmd, t_parse_ctx *ctx)
{
	char	*expanded;
	int		was_expanded;

	expanded = NULL;
	was_expanded = 0;
	if (!extract_expanded_word(tok, ctx, &expanded, &was_expanded))
		return (0);
	if (tok->join_next)
		return (append_to_buffer(tok, ctx, expanded, was_expanded));
	if (*(ctx->arg_buf))
		return (flush_buffer_to_arg(cmd, ctx, expanded));
	return (add_simple_arg(cmd, ctx, expanded, was_expanded));
}

int	handle_pipe_token(t_cmd **new, t_parse_ctx *ctx)
{
	int	flags;

	if (*(ctx->arg_buf))
	{
		flags = 0;
		if (ctx->arg_buf_expan)
			flags |= ARG_EXPANDED;
		if (!add_arg_token(*new, *(ctx->arg_buf), ctx->is_first, flags))
		{
			free(*(ctx->arg_buf));
			return (0);
		}
		free(*(ctx->arg_buf));
		*(ctx->arg_buf) = NULL;
	}
	ctx->arg_buf_expan = 0;
	(*new)->pipe_next = 1;
	add_cmd(ctx->head, ctx->last, new);
	*(ctx->is_first) = 1;
	*new = create_cmd_node();
	if (!*new)
		return (0);
	return (1);
}
