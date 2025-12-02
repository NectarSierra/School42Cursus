/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:41 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/18 12:49:08 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_token	*parse_operator_token(char **input)
{
	if (**input == '<')
	{
		if (*(*input + 1) == '<')
			return (create_token_symbol(input, "<<", TOKEN_HEREDOC, 2));
		else
			return (create_token_symbol(input, "<", TOKEN_REDIR_IN, 1));
	}
	else if (**input == '>')
	{
		if (*(*input + 1) == '>')
			return (create_token_symbol(input, ">>", TOKEN_APPEND, 2));
		else
			return (create_token_symbol(input, ">", TOKEN_REDIR_OUT, 1));
	}
	else if (**input == '|')
		return (create_token_symbol(input, "|", TOKEN_PIPE, 1));
	return (NULL);
}

static int	handle_word_tokens(char **input, char *input_before_token,
	t_token_ctx *ctx)
{
	t_token	*multi;
	t_token	*new;

	multi = parse_word_token(input);
	if (!multi)
		return (0);
	while (multi)
	{
		new = multi;
		multi = multi->next;
		new->next = NULL;
		if (*(ctx->last)
			&& input_before_token == ctx->prev_input
			&& (*(ctx->last))->type == TOKEN_WORD
			&& new->type == TOKEN_WORD)
		{
			(*(ctx->last))->join_next = 1;
		}
		add_token(ctx->tokens, new);
		*(ctx->last) = new;
	}
	ctx->prev_input = *input;
	return (1);
}

static void	save_token(t_token *tok, char *input_before_token, t_token_ctx *ctx)
{
	if (*(ctx->last)
		&& input_before_token == ctx->prev_input
		&& (*(ctx->last))->type == TOKEN_WORD
		&& tok->type == TOKEN_WORD)
	{
		(*(ctx->last))->join_next = 1;
	}
	add_token(ctx->tokens, tok);
	*(ctx->last) = tok;
	ctx->prev_input = *(ctx->input);
}

static int	handle_next_token(t_token_ctx *ctx)
{
	t_token		*op;
	char		*input_before_token;

	skip_whitespace(ctx->input);
	if (!**(ctx->input))
		return (0);
	input_before_token = *(ctx->input);
	op = parse_operator_token(ctx->input);
	if (op)
	{
		save_token(op, input_before_token, ctx);
		return (1);
	}
	if (!handle_word_tokens(ctx->input, input_before_token, ctx))
		return (-1);
	return (1);
}

int	tokenize(char *input, t_token **tokens)
{
	t_token_ctx	ctx;
	t_token		*last;
	int			status;

	last = NULL;
	ctx.tokens = tokens;
	ctx.last = &last;
	ctx.prev_input = input;
	ctx.input = &input;
	while (**(ctx.input))
	{
		status = handle_next_token(&ctx);
		if (status == -1)
			return (free_tokens(tokens), 0);
		if (status == 0)
			break ;
	}
	return (1);
}
