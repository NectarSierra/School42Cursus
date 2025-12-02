/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:57:50 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 12:19:02 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// utils_free.c

char	*strjoin_and_free(char *s1, const char *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
	{
		joined = ft_strdup(s1);
		free(s1);
		return (joined);
	}
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

void	free_redirections(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		if (tmp->filename)
			free(tmp->filename);
		free(tmp);
	}
}

void	free_commands(t_cmd *cmds)
{
	t_cmd	*tmp;
	int		i;

	while (cmds)
	{
		tmp = cmds;
		i = 0;
		if (cmds->args)
		{
			while (cmds->args[i])
				free(cmds->args[i++]);
			free(cmds->args);
		}
		if (cmds->heredoc_fd != -1)
			close(cmds->heredoc_fd);
		free_redirections(cmds->redirs);
		cmds = cmds->next;
		free(tmp);
	}
}
