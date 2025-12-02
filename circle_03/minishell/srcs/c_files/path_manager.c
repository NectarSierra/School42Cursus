/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:14:16 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/18 09:20:56 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*build_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

char	*search_in_path(char *path, char *cmd)
{
	char		*full;
	char		*dir;
	struct stat	sb;
	int			i;
	int			j;

	i = 0;
	while (path[i])
	{
		j = i;
		while (path[i] && path[i] != ':')
			i++;
		dir = ft_substr(path, j, i - j);
		if (!dir)
			return (NULL);
		full = build_path(dir, cmd);
		free(dir);
		if (full && stat(full, &sb) == 0 && S_ISREG(sb.st_mode)
			&& (sb.st_mode & S_IXUSR))
			return (full);
		free(full);
		if (path[i] == ':')
			i++;
	}
	return (NULL);
}

char	*add_path_to_cmd(char *cmd, char **env)
{
	char	*path;

	path = get_path(env);
	if (!path)
		return (NULL);
	return (search_in_path(path, cmd));
}

char	*path_manager(char *cmd, t_exec_context *ctx)
{
	char	*resolved;

	if (!cmd)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (check_exe_perm(cmd, cmd, ctx->exit_code) != 0)
			return (NULL);
		return (ft_strdup(cmd));
	}
	if (is_relative(cmd))
	{
		resolved = resolve_relative_path(cmd);
		if (!resolved)
			return (NULL);
		if (check_exe_perm(resolved, cmd, ctx->exit_code) != 0)
		{
			free(resolved);
			return (NULL);
		}
		return (resolved);
	}
	return (resolve_cmd_path(cmd, ctx));
}
