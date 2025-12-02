/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:44:29 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/16 18:02:37 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_existing_env(t_env *env_data, char ***env)
{
	char	*tmp;

	env_data->existing = get_env_value(env_data->key, *env);
	if (!env_data->existing)
	{
		tmp = ft_strjoin(env_data->key, "=");
		if (!tmp)
			return ;
		env_data->full = ft_strjoin(tmp, env_data->addition);
		free(tmp);
	}
	else
	{
		env_data->full = join_env_key_value_append(env_data->key,
				env_data->existing, env_data->addition);
		free(env_data->existing);
	}
	if (!env_data->full)
		return ;
	replace_env_entry(*env, env_data->index, env_data->full);
	free(env_data->full);
}

static void	append_new_env(t_env *env_data, char ***env)
{
	char	*tmp;

	tmp = ft_strjoin(env_data->key, "=");
	if (!tmp)
	{
		printf("[ERROR] Memory allocation failed for tmp '=' join.\n");
		return ;
	}
	env_data->full = ft_strjoin(tmp, env_data->addition);
	free(tmp);
	if (!env_data->full)
	{
		printf("[ERROR] Memory allocation failed for full key=value.\n");
		return ;
	}
	append_env_entry(env_data->full, env);
	free(env_data->full);
}

static int	extract_env_parts(char *arg, t_env *env_data)
{
	char	*equal;

	env_data->plus = ft_strnstr(arg, "+=", ft_strlen(arg));
	if (env_data->plus)
	{
		env_data->key = ft_substr(arg, 0, env_data->plus - arg);
		env_data->addition = ft_strdup(env_data->plus + 2);
	}
	else
	{
		equal = ft_strchr(arg, '=');
		if (!equal)
			return (0);
		env_data->key = ft_substr(arg, 0, equal - arg);
		env_data->addition = ft_strdup(equal + 1);
	}
	if (!env_data->key || !env_data->addition)
	{
		free(env_data->key);
		free(env_data->addition);
		return (0);
	}
	return (1);
}

static void	add_or_update_env(char *arg, char ***env)
{
	t_env	env_data;

	env_data.key = NULL;
	env_data.addition = NULL;
	env_data.existing = NULL;
	env_data.full = NULL;
	env_data.plus = NULL;
	env_data.index = 0;
	if (!arg)
		return ;
	if (!extract_env_parts(arg, &env_data))
		return ;
	env_data.index = find_env_index(*env, env_data.key);
	if (env_data.index >= 0)
		update_existing_env(&env_data, env);
	else
		append_new_env(&env_data, env);
	free(env_data.key);
	free(env_data.addition);
}

void	builtin_export(t_cmd *cmd, char ***env, int *exit_code)
{
	int	i;

	i = 1;
	*exit_code = 0;
	if (!cmd->args[1])
	{
		print_export_env(*env);
		return ;
	}
	while (cmd->args[i])
	{
		if (!is_valid_key(cmd->args[i]))
		{
			err(SHNAME ": line 1: export: ", cmd->args[i],
				": not a valid identifier\n");
			*exit_code = 1;
		}
		else if (ft_strchr(cmd->args[i], '='))
			add_or_update_env(cmd->args[i], env);
		else
			add_key_if_missing(cmd->args[i], env);
		i++;
	}
}
