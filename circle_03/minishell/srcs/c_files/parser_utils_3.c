/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:34:40 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:47:37 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// parser_utils_1

int	add_arg_token(t_cmd *cmd, char *val, int *is_first, int flags)
{
	char	*dup;

	dup = ft_strdup(val);
	if (!dup)
		return (0);
	if (*is_first)
	{
		*is_first = 0;
		if (flags & ARG_EXPANDED)
			cmd->from_expansion = 1;
		return (create_first_arg(cmd, dup));
	}
	if (flags & ARG_JOIN)
		return (join_with_previous_arg(cmd, dup));
	return (append_arg(cmd, dup));
}

int	add_simple_arg(t_cmd *cmd, t_parse_ctx *ctx, char *expanded,
	int was_expanded)
{
	int	flags;

	flags = 0;
	if (was_expanded)
	{
		flags |= ARG_EXPANDED;
		cmd->from_expansion = 1;
	}
	if (!add_arg_token(cmd, expanded, ctx->is_first, flags))
		return (free(expanded), 0);
	free(expanded);
	return (1);
}

char	*concat_arg_buffer(char *buf, char *next)
{
	char	*joined;

	if (!buf)
		return (ft_strdup(next));
	joined = strjoin_and_free(buf, next);
	return (joined);
}

int	append_to_buffer(t_token *tok, t_parse_ctx *ctx, char *expanded,
		int was_expanded)
{
	if (was_expanded)
		ctx->arg_buf_expan = 1;
	if (tok->quoted)
		ctx->arg_buf_quote = &tok->quoted;
	*(ctx->arg_buf) = concat_arg_buffer(*(ctx->arg_buf), expanded);
	free(expanded);
	return (1);
}

int	flush_buffer_to_arg(t_cmd *cmd, t_parse_ctx *ctx, char *expanded)
{
	char	*final_arg;
	int		flags;

	flags = 0;
	final_arg = concat_arg_buffer(*(ctx->arg_buf), expanded);
	free(expanded);
	*(ctx->arg_buf) = NULL;
	if (ctx->arg_buf_expan)
	{
		flags |= ARG_EXPANDED;
		cmd->from_expansion = 1;
	}
	ctx->arg_buf_expan = 0;
	if (!add_arg_token(cmd, final_arg, ctx->is_first, flags))
		return (free(final_arg), 0);
	free(final_arg);
	return (1);
}
