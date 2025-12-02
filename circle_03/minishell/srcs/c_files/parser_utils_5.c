/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:42 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:48:01 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// parser_utils_redirs.c

int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

int	set_redir_type(t_redir *r, t_token_type tok_type)
{
	if (tok_type == TOKEN_REDIR_IN)
		r->type = R_IN;
	else if (tok_type == TOKEN_REDIR_OUT)
		r->type = R_OUT;
	else if (tok_type == TOKEN_APPEND)
		r->type = R_APPEND;
	else if (tok_type == TOKEN_HEREDOC)
		r->type = R_HEREDOC;
	else
		return (0);
	return (1);
}

void	append_redir(t_cmd *cmd, t_redir *redir)
{
	t_redir	*tmp;

	if (!cmd->redirs)
		cmd->redirs = redir;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = redir;
	}
}

static char	*expand_or_dup(t_token *tok, t_parse_ctx *ctx, int do_expand)
{
	if (!tok)
		return (NULL);
	if (do_expand)
		return (expand_word(tok->value, ctx->env, ctx->exit_code,
				tok->quoted));
	return (ft_strdup(tok->value));
}

char	*concat_redir_filename(t_token **tok, t_parse_ctx *ctx, int do_expand)
{
	t_token	*curr;
	char	*filename;
	char	*expanded;
	char	*joined;

	if (!tok || !*tok)
		return (NULL);
	curr = *tok;
	filename = NULL;
	while (curr && curr->type == TOKEN_WORD)
	{
		expanded = expand_or_dup(curr, ctx, do_expand);
		joined = strjoin_and_free(filename, expanded);
		if (expanded)
			free(expanded);
		if (!joined)
			return (NULL);
		filename = joined;
		if (!curr->join_next)
			break ;
		curr = curr->next;
	}
	*tok = curr;
	return (filename);
}
