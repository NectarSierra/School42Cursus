/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/09 11:37:10 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_env_value(const char *var_name, char **env)
{
	int		len;
	int		i;

	if (!var_name || !env)
		return (NULL);
	len = ft_strlen(var_name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var_name, len) == 0 && env[i][len] == '=')
			return (ft_strdup(env[i] + len + 1));
		i++;
	}
	return (NULL);
}

void	sort_env(char **env, int size)
{
	int		i;
	int		swapped;
	char	*tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

char	*get_env(char **env, char *needle)
{
	int		i;
	size_t	len;

	if (!needle)
		return (NULL);
	len = ft_strlen(needle);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], needle, len) == 0 && env[i][len] == '=')
			return (ft_strdup(env[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

char	*check_env(char *arg, int *exit_code, char **env)
{
	char	*code_str;

	if (!arg || arg[0] != '$')
		return (ft_strdup(arg));
	if (arg[1] == '?' && arg[2] == '\0')
	{
		code_str = ft_itoa(*exit_code);
		if (!code_str)
			return (NULL);
		return (code_str);
	}
	return (get_env(env, arg + 1));
}
