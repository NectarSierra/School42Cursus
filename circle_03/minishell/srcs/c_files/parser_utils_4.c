/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:38:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 10:47:44 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// parser_utils_ 4

int	append_arg(t_cmd *cmd, char *value)
{
	int		i;
	char	**args;

	i = 0;
	while (cmd->args[i])
		i++;
	args = malloc(sizeof(char *) * (i + 2));
	if (!args)
		return (0);
	ft_memcpy(args, cmd->args, sizeof(char *) * i);
	args[i] = value;
	args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = args;
	return (1);
}

int	create_first_arg(t_cmd *cmd, char *value)
{
	cmd->args = malloc(sizeof(char *) * 2);
	if (!cmd->args)
		return (0);
	cmd->args[0] = value;
	cmd->args[1] = NULL;
	return (1);
}

int	join_with_previous_arg(t_cmd *cmd, char *value)
{
	int		i;
	char	*new_arg;

	if (!cmd->args || !cmd->args[0])
		return (create_first_arg(cmd, ft_strdup(value)));
	i = 0;
	while (cmd->args[i])
		i++;
	new_arg = strjoin_and_free(cmd->args[i - 1], value);
	if (!new_arg)
		return (0);
	cmd->args[i - 1] = new_arg;
	return (1);
}

void	add_cmd(t_cmd **head, t_cmd **last, t_cmd **new)
{
	if (!*head)
		*head = *new;
	else
		(*last)->next = *new;
	*last = *new;
	*new = NULL;
}

t_cmd	*create_cmd_node(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->args = NULL;
	new->redirs = NULL;
	new->heredoc_fd = -1;
	new->pipe_next = 0;
	new->from_expansion = 0;
	new->next = NULL;
	return (new);
}
