/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:51:23 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 11:58:02 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	remove_empty_first_arg(t_cmd *cmd)
{
	int	i;
	int	j;

	free(cmd->args[0]);
	i = 1;
	j = 0;
	while (cmd->args[i])
		cmd->args[j++] = cmd->args[i++];
	cmd->args[j] = NULL;
	if (j == 0)
	{
		free(cmd->args);
		cmd->args = NULL;
	}
}

void	normalize_args(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->args
			&& cmd->args[0]
			&& cmd->args[0][0] == '\0'
			&& cmd->from_expansion
			&& cmd->args[1])
			remove_empty_first_arg(cmd);
		cmd = cmd->next;
	}
}

int	handle_input(char *input, char ***env, int *exit_code)
{
	t_token	*tokens;
	t_cmd	*cmds;

	tokens = NULL;
	cmds = NULL;
	if (!tokenize(input, &tokens))
		return (*exit_code = 2, 0);
	if (!parse_tokens(tokens, &cmds, *env, exit_code))
		return (free_tokens(&tokens), *exit_code = 2, 0);
	free_tokens(&tokens);
	normalize_args(cmds);
	if (!collect_heredocs(cmds, *env, exit_code))
		return (free_commands(cmds), *exit_code = 2, 0);
	if (!validate_commands(cmds))
		return (free_commands(cmds), *exit_code = 2, 0);
	execute_commands(cmds, env, exit_code);
	if (cmds)
		free_commands(cmds);
	return (1);
}

static char	*read_input(int is_interactive)
{
	char	*input;
	char	*newline;

	if (is_interactive)
		return (readline(PROMPT));
	input = get_next_line(STDIN_FILENO);
	if (!input)
		return (NULL);
	newline = ft_strchr(input, '\n');
	if (newline)
		*newline = '\0';
	return (input);
}

void	prompt_loop(char ***env, int *exit_code)
{
	char	*input;
	int		is_interactive;

	setup_signals();
	is_interactive = is_interactive_shell();
	while (1)
	{
		input = read_input(is_interactive);
		if (!input)
		{
			if (is_interactive)
				write(STDERR_FILENO, "exit\n", 5);
			break ;
		}
		if (ft_is_empty(input))
		{
			free(input);
			continue ;
		}
		if (is_interactive)
			add_history(input);
		handle_input(input, env, exit_code);
		free(input);
	}
}

/*

void	prompt_loop(char ***env, int *exit_code)
{
	char	*input;

	setup_signals();
	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			return ;
		if (ft_is_empty(input))
		{
			free(input);
			continue ;
		}
		handle_input(input, env, exit_code);
		free(input);
	}
}
*/