/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:52:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 13:23:50 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*resolve_cmd_path(char *cmd, t_exec_context *ctx)
{
	char	*resolved;
	int		perm;

	resolved = add_path_to_cmd(cmd, *ctx->env);
	if (!resolved)
	{
		err(SHNAME ": line 1: ", cmd, ": command not found\n");
		*ctx->exit_code = 127;
		return (NULL);
	}
	perm = check_exe_perm(resolved, cmd, ctx->exit_code);
	if (perm != 0)
	{
		free(resolved);
		return (NULL);
	}
	return (resolved);
}

int	is_relative(char *cmd)
{
	if (!cmd || cmd[0] == '/')
		return (0);
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}

int	check_exe_perm(char *cmd, char *printed_cmd, int *exit_code)
{
	struct stat	sb;

	if (stat(cmd, &sb) == -1)
	{
		err(SHNAME ": line 1: ", printed_cmd, ": No such file or directory\n");
		return (*exit_code = 127, 1);
	}
	if (S_ISDIR(sb.st_mode))
	{
		err(SHNAME ": line 1: ", printed_cmd, ": Is a directory\n");
		return (*exit_code = 126, 1);
	}
	if (!S_ISREG(sb.st_mode))
	{
		err(SHNAME ": line 1: ", printed_cmd, ": Not a regular file\n");
		return (*exit_code = 126, 1);
	}
	if (!(sb.st_mode & S_IXUSR))
	{
		err(SHNAME ": line 1: ", printed_cmd, ": Permission denied\n");
		return (*exit_code = 126, 1);
	}
	return (0);
}

char	*resolve_relative_path(char *cmd)
{
	char	*cwd;
	char	*tmp;
	char	*full;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	tmp = ft_strjoin(cwd, "/");
	free(cwd);
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

char	*safe_strdup_empty_if_needed(char *filename)
{
	if (filename)
		return (filename);
	return (ft_strdup(""));
}
