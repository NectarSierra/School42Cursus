/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:07:33 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 13:47:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_heredoc_prompt_stream(void)
{
	int	fd;

	if (!isatty(STDIN_FILENO))
	{
		fd = open("/dev/null", O_WRONLY);
		if (fd != -1)
			rl_outstream = fdopen(fd, "w");
	}
}

void	remove_env_var(char ***env, int index)
{
	int		i;
	int		j;
	char	**new_env;
	int		count;

	count = 0;
	while ((*env)[count])
		count++;
	new_env = malloc(sizeof(char *) * count);
	if (!new_env)
		return ;
	i = 0;
	j = 0;
	while (i < count)
	{
		if (i != index)
			new_env[j++] = ft_strdup((*env)[i]);
		i++;
	}
	new_env[j] = NULL;
	i = 0;
	while ((*env)[i])
		free((*env)[i++]);
	free(*env);
	*env = new_env;
}

void	builtin_unset(t_cmd *cmd, char ***env, int *exit_code)
{
	int	i;
	int	index;

	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_key(cmd->args[i]))
		{
			err(SHNAME ": unset: ", cmd->args[i], ": not a valid identifier\n");
			*exit_code = 1;
		}
		else
		{
			index = find_env_index(*env, cmd->args[i]);
			if (index >= 0)
				remove_env_var(env, index);
			*exit_code = 0;
		}
		i++;
	}
}
