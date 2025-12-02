/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:59 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 09:56:04 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
void	print_tokens(t_token *tokens)
{
	const char	*type_str[] =
	{
		[TOKEN_WORD] = "WORD",
		[TOKEN_PIPE] = "PIPE",
		[TOKEN_REDIR_IN] = "REDIR_IN",
		[TOKEN_REDIR_OUT] = "REDIR_OUT",
		[TOKEN_APPEND] = "APPEND",
		[TOKEN_HEREDOC] = "HEREDOC"
	};
	t_token	*cur = tokens;
	int		i = 0;

	printf("-------- TOKENS --------\n");
	while (cur)
	{
		printf("[%02d] type: %-10s | quoted: %c | join: %d | value: %s\n",
			i++,
			type_str[cur->type],
			cur->quoted ? cur->quoted : '-',
			cur->join_next,
			cur->value);
		cur = cur->next;
	}
	printf("------------------------\n");
}
*/
t_token	*create_token_symbol(char **input, const char *s, int type,
		int adv)
{
	char	*value;

	value = ft_strdup(s);
	if (!value)
		return (NULL);
	*input += adv;
	return (create_token(value, type));
}

const char	*redir_type_str(t_redir_type type)
{
	if (type == R_IN)
		return ("<");
	if (type == R_OUT)
		return (">");
	if (type == R_APPEND)
		return (">>");
	if (type == R_HEREDOC)
		return ("<<");
	return ("?");
}

static char	*extract_quoted(char **input)
{
	char	quote;
	char	*start;
	char	*str;

	quote = *(*input)++;
	start = *input;
	while (**input && **input != quote)
		(*input)++;
	if (**input != quote)
		return (err(MSG_QUOTE, NULL, NULL), NULL);
	str = ft_strndup(start, *input - start);
	if (!str)
		return (NULL);
	(*input)++;
	return (str);
}

static char	*extract_word(char **input)
{
	char	*start;
	char	*str;

	start = *input;
	while (**input && !ft_is_space(**input)
		&& !ft_strchr("|<>", **input)
		&& !is_char_quote(**input))
		(*input)++;
	str = ft_strndup(start, *input - start);
	return (str);
}

t_token	*parse_word_token(char **input)
{
	char	*str;
	t_token	*tok;
	char	quote;

	if (is_char_quote(**input))
	{
		quote = **input;
		str = extract_quoted(input);
		if (str == NULL)
			return (NULL);
	}
	else
	{
		str = extract_word(input);
		if (str == NULL)
			return (NULL);
		quote = 0;
	}
	tok = create_token(str, TOKEN_WORD);
	if (!tok)
		return (free(str), NULL);
	tok->quoted = quote;
	return (tok);
}
