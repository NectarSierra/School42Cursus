/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:33:34 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/17 19:22:52 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_syntax_error(const char *token)
{
	if (!token || token[0] == '\0')
		err(SHNAME ": line 1" SYNTAX_ERR_NL, NULL, NULL);
	else
		err(SHNAME ": line 1" SYNTAX_ERR_MSG, token, "'\n");
}

static int	is_fully_empty(t_cmd *cmd)
{
	return ((!cmd->args || !cmd->args[0])
		&& !cmd->from_expansion
		&& !cmd->redirs
		&& cmd->heredoc_fd == -1);
}

int	validate_commands(t_cmd *cmds)
{
	t_cmd	*cmd;

	cmd = cmds;
	while (cmd)
	{
		if (is_fully_empty(cmd))
			return (print_syntax_error("|"), 0);
		if (cmd->pipe_next && (!cmd->next || is_fully_empty(cmd->next)))
			return (print_syntax_error("|"), 0);
		cmd = cmd->next;
	}
	return (1);
}
