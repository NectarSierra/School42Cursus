/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:27:05 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/17 19:36:26 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*strip_outer_quotes(char *str, char quote)
{
	size_t	len;

	if (!str || !quote)
		return (str);
	len = ft_strlen(str);
	if (len >= 2 && str[0] == quote && str[len - 1] == quote)
		return (ft_substr(str, 1, len - 2));
	return (ft_strdup(str));
}

void	strip_result_if_needed(t_expand_ctx *ctx)
{
	char	*stripped;
	size_t	len;

	if (ctx->i_q)
	{
		stripped = strip_outer_quotes(ctx->res, ctx->i_q);
		free(ctx->res);
		ctx->res = stripped;
	}
	else
	{
		len = ft_strlen(ctx->res);
		if (len >= 2 && ((ctx->res[0] == '"' && ctx->res[len - 1] == '"')
				|| (ctx->res[0] == '\'' && ctx->res[len - 1] == '\'')))
		{
			stripped = ft_substr(ctx->res, 1, len - 2);
			free(ctx->res);
			ctx->res = stripped;
		}
	}
}

char	*return_or_free_empty(char *res)
{
	if (res && res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	extract_expanded_word(t_token *tok, t_parse_ctx *ctx, char **out,
	int *was_expanded)
{
	char	*expanded;

	*was_expanded = 0;
	if (tok->quoted == '\'')
	{
		*out = ft_strdup(tok->value);
		return (*out != NULL);
	}
	expanded = expand_word(tok->value, ctx->env, ctx->exit_code, tok->quoted);
	if (!expanded)
	{
		if (ft_strchr(tok->value, '$'))
		{
			*was_expanded = 1;
			*out = ft_strdup("");
			return (*out != NULL);
		}
		*out = ft_strdup("");
		return (*out != NULL);
	}
	if (expanded[0] == '\0' && ft_strchr(tok->value, '$'))
		*was_expanded = 1;
	*out = expanded;
	return (1);
}
