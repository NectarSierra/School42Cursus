/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:50 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/16 18:47:55 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_key_if_missing(char *key, char ***env)
{
	int	i;

	i = 0;
	if (!key || !*key)
		return ;
	while ((*env)[i])
	{
		if (ft_strcmp((*env)[i], key) == 0 || ft_strncmp((*env)[i], key,
				ft_strlen(key)) == 0)
			return ;
		i++;
	}
	append_env_entry(key, env);
}

char	*get_key_from_arg(const char *arg)
{
	int	len;

	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	return (ft_substr(arg, 0, len));
}

int	find_env_index(char **env, char *key)
{
	int		i;
	size_t	len;

	i = 0;
	if (!env || !key)
		return (-1);
	len = ft_strlen(key);
	while (env[i])
	{
		if ((ft_strncmp(env[i], key, len) == 0) && (env[i][len] == '='
			|| env[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

char	**malloc_env_copy(char **env, int extra)
{
	int		count;
	char	**new_env;

	count = 0;
	while (env[count])
		count++;
	new_env = malloc(sizeof(char *) * (count + 1 + extra));
	if (!new_env)
		return (NULL);
	new_env[count + extra] = NULL;
	return (new_env);
}

int	is_valid_key(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (0);
	if (arg[0] == '=' || arg[0] == '+')
		return (0);
	i = 0;
	while (arg[i] && arg[i] != '=' && !(arg[i] == '+' && arg[i + 1] == '='))
	{
		if (i == 0 && ft_isdigit(arg[i]))
			return (0);
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	if (arg[i] == '+' && arg[i + 1] != '=')
		return (0);
	return (1);
}
