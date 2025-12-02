/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:28:29 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 14:25:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	append_exit_code_heredoc(t_expand_ctx *ctx)
{
	char	*code;

	code = ft_itoa(*(ctx->exit_code));
	if (!code)
		return (1);
	ctx->j += ft_strlcat(ctx->res + ctx->j, code, INPUT_SIZE - ctx->j);
	free(code);
	return (0);
}

int	append_env_var_heredoc(t_expand_ctx *ctx)
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

void	expand_heredoc_loop(t_expand_ctx *ctx)
{
	ctx->i = 0;
	ctx->j = 0;
	while (ctx->raw[ctx->i] && ctx->j < INPUT_SIZE - 1)
	{
		if (ctx->raw[ctx->i] == '$')
		{
			ctx->i++;
			if (ctx->raw[ctx->i] == '?')
			{
				append_exit_code_heredoc(ctx);
				ctx->i++;
			}
			else if (!is_var_char(ctx->raw[ctx->i]))
				ctx->res[(ctx->j)++] = '$';
			else
				append_env_var_heredoc(ctx);
		}
		else
			ctx->res[(ctx->j)++] = ctx->raw[(ctx->i)++];
	}
	ctx->res[ctx->j] = '\0';
}

char	*expand_word_heredoc(char *raw, char **env, int *exit_code)
{
	t_expand_ctx	ctx;

	if (!raw)
		return (NULL);
	ctx.res = ft_calloc(INPUT_SIZE, sizeof(char));
	if (!ctx.res)
		return (NULL);
	ctx.raw = raw;
	ctx.env = env;
	ctx.exit_code = exit_code;
	expand_heredoc_loop(&ctx);
	return (ctx.res);
}

void	process_heredoc_line(char *line, t_heredoc_ctx *ctx)
{
	char	*expanded;

	if (!ctx->r->quoted)
	{
		expanded = expand_word_heredoc(line, ctx->env, ctx->exit_code);
		if (expanded)
		{
			ft_putendl_fd(expanded, ctx->fd);
			free(expanded);
		}
	}
	else
		ft_putendl_fd(line, ctx->fd);
	free(line);
}
