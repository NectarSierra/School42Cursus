/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <matsauva@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:31:44 by nsaillez          #+#    #+#             */
/*   Updated: 2025/04/15 09:35:44 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**copy_env(char **env)
{
	int		count;
	char	**copy;
	int		i;

	count = 0;
	i = 0;
	while (env[count])
		count++;
	copy = malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	while (i < count)
	{
		copy[i] = ft_strdup(env[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[count] = NULL;
	return (copy);
}

int	main(int argc, char **argv, char **env)
{
	int		exit_status;
	char	**env_copy;

	(void)argc;
	(void)argv;
	exit_status = 0;
	env_copy = copy_env(env);
	if (!env_copy)
		return (1);
	rl_catch_signals = 0;
	setup_signals();
	prompt_loop(&env_copy, &exit_status);
	return (free_strs(env_copy), exit_status);
}
