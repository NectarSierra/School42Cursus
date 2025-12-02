/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:41 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/17 19:35:05 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	append_exit_code(t_expand_ctx *ctx)
{
	char	*code;

	code = ft_itoa(*(ctx->exit_code));
	if (!code)
		return (1);
	ctx->j += ft_strlcat(ctx->res + ctx->j, code, INPUT_SIZE - ctx->j);
	free(code);
	return (0);
}

int	append_env_var(t_expand_ctx *ctx)
{
	char	var[INPUT_SIZE];
	char	*val;
	int		k;

	k = 0;
	while (ctx->raw[ctx->i + k] && is_var_name_char(ctx->raw[ctx->i + k])
		&& k < INPUT_SIZE - 1)
	{
		var[k] = ctx->raw[ctx->i + k];
		k++;
	}
	var[k] = '\0';
	if (k == 0)
		return (ctx->res[(ctx->j)++] = '$', 0);
	ctx->i += k;
	val = get_env_value(var, ctx->env);
	if (val)
	{
		ctx->j += ft_strlcat(ctx->res + ctx->j, val, INPUT_SIZE - ctx->j);
		free(val);
	}
	return (0);
}

static void	process_expand_char(t_expand_ctx *ctx)
{
	if (!ctx->quote && is_quoted(&ctx->raw[ctx->i]) && ctx->i_q == 0)
	{
		ctx->quote = ctx->raw[ctx->i];
		ctx->res[(ctx->j)++] = ctx->raw[(ctx->i)++];
	}
	else if (ctx->quote && ctx->raw[ctx->i] == ctx->quote && ctx->i_q == 0)
	{
		ctx->quote = 0;
		ctx->res[(ctx->j)++] = ctx->raw[(ctx->i)++];
	}
	else if (ctx->raw[ctx->i] == '$' && ctx->quote != '\'')
	{
		ctx->i++;
		if (ctx->raw[ctx->i] == '?')
		{
			append_exit_code(ctx);
			ctx->i++;
		}
		else if (ctx->raw[ctx->i] == '\0' || !is_var_char(ctx->raw[ctx->i]))
			ctx->res[(ctx->j)++] = '$';
		else
			append_env_var(ctx);
	}
	else
		ctx->res[(ctx->j)++] = ctx->raw[(ctx->i)++];
}

static void	expand_word_loop(t_expand_ctx *ctx)
{
	ctx->i = 0;
	ctx->j = 0;
	ctx->quote = 0;
	while (ctx->raw[ctx->i] && ctx->j < INPUT_SIZE - 1)
		process_expand_char(ctx);
	ctx->res[ctx->j] = '\0';
}

char	*expand_word(char *raw, char **env, int *exit_code, int initial_quote)
{
	t_expand_ctx	ctx;

	if (!raw)
		return (NULL);
	ctx.raw = raw;
	ctx.env = env;
	ctx.exit_code = exit_code;
	ctx.i_q = initial_quote;
	ctx.res = ft_calloc(INPUT_SIZE, sizeof(char));
	if (!ctx.res)
		return (NULL);
	expand_word_loop(&ctx);
	strip_result_if_needed(&ctx);
	return (return_or_free_empty(ctx.res));
}
