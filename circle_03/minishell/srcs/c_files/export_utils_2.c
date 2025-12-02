/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:24:45 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/23 13:50:49 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_single_export(char *entry)
{
	char	*equal;

	equal = ft_strchr(entry, '=');
	if (equal)
	{
		*equal = '\0';
		printf("declare -x %s=\"%s\"\n", entry, equal + 1);
		*equal = '=';
	}
	else
		printf("declare -x %s\n", entry);
}

void	print_export_env(char **env)
{
	int		i;
	char	**sorted;
	int		count;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	sorted = malloc(sizeof(char *) * (count + 1));
	if (!sorted)
	{
		printf("[ERROR] Memory allocation failed for sorted array.\n");
		return ;
	}
	while (i < count)
	{
		sorted[i] = env[i];
		i++;
	}
	sorted[i] = NULL;
	sort_env(sorted, count);
	i = 0;
	while (sorted[i])
		print_single_export(sorted[i++]);
	free(sorted);
}

void	append_env_entry(char *arg, char ***env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = malloc_env_copy(*env, 1);
	if (!new_env)
		return ;
	while ((*env)[i])
	{
		new_env[i] = ft_strdup((*env)[i]);
		i++;
	}
	new_env[i] = ft_strdup(arg);
	new_env[i + 1] = NULL;
	i = 0;
	while ((*env)[i])
		free((*env)[i++]);
	free(*env);
	*env = new_env;
}

void	replace_env_entry(char **env, int index, char *arg)
{
	free(env[index]);
	env[index] = ft_strdup(arg);
}

char	*join_env_key_value_append(char *key, char *existing_value,
		char *addition)
{
	size_t	total_len;
	char	*full_value;

	total_len = ft_strlen(key) + ft_strlen(existing_value)
		+ ft_strlen(addition) + 2;
	full_value = malloc(total_len);
	if (!full_value)
	{
		printf("[ERROR] Memory allocation failed for full_value.\n");
		return (NULL);
	}
	ft_strlcpy(full_value, key, total_len);
	ft_strcat(full_value, "=");
	ft_strcat(full_value, existing_value);
	ft_strcat(full_value, addition);
	return (full_value);
}
