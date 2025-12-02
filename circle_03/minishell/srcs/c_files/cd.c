/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:06:07 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 09:42:01 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	execute_cd(char *path, int should_free, int *exit_code)
{
	char	*cwd;

	*exit_code = 1;
	if (chdir(path) != 0)
	{
		err(SHNAME ": line 1: cd: ", path, ": ");
		perror(NULL);
	}
	else
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
		{
			err("line 1: cd: error retrieving current directory: "
				"getcwd: cannot access parent directories: "
				"No such file or directory\n", NULL, NULL);
		}
		else
		{
			*exit_code = 0;
			free(cwd);
		}
	}
	if (should_free)
		free(path);
}

static char	*get_cd_path(t_cmd *cmd, char **env, int *should_free,
		int *exit_code)
{
	char	*home;

	if (!cmd->args[1])
	{
		home = get_env(env, "HOME");
		if (!home || !*home)
		{
			err(SHNAME ": line 1: cd: ", NULL, "HOME not set\n");
			*exit_code = 1;
			free(home);
			return (NULL);
		}
		*should_free = 1;
		return (home);
	}
	*should_free = 0;
	return (cmd->args[1]);
}

void	builtin_cd(t_cmd *cmd, char **env, int *exit_code)
{
	char	*path;
	int		should_free;

	if (cmd->args[1] && cmd->args[2])
	{
		err(SHNAME ": cd: ", NULL, "too many arguments\n");
		*exit_code = 1;
		return ;
	}
	path = get_cd_path(cmd, env, &should_free, exit_code);
	if (!path)
		return ;
	execute_cd(path, should_free, exit_code);
}
