/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:05:26 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/15 15:06:42 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**copy_env(char **env, int count)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	print_and_free_env(char **env, int count)
{
	int	i;

	sort_env(env, count);
	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], STDOUT_FILENO);
		free(env[i]);
		i++;
	}
	free(env);
}

static int	get_env_count(char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

void	builtin_env(t_cmd *cmd, char **env, int *exit_code)
{
	char	**env_copy;
	int		count;

	(void)cmd;
	count = get_env_count(env);
	env_copy = copy_env(env, count);
	if (!env_copy)
	{
		*exit_code = 127;
		return ;
	}
	print_and_free_env(env_copy, count);
	*exit_code = 0;
}
