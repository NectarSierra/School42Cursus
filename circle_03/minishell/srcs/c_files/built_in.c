/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:41 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 13:51:44 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "exit") == 0 || ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "export") == 0 || ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

void	execute_builtin(t_cmd *cmd, char ***env, int *exit_code,
		t_cmd *all_cmds)
{
	t_exec_context	ctx;

	ctx = (t_exec_context){all_cmds, env, exit_code};
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (!apply_redirections(cmd, (int [2]){-1, -1}, STDIN_FILENO, &ctx))
	{
		*exit_code = 1;
		return ;
	}
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		builtin_echo(cmd, exit_code);
	else if (ft_strcmp(cmd->args[0], "exit") == 0)
		builtin_exit(cmd, exit_code, env, all_cmds);
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		builtin_cd(cmd, *env, exit_code);
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		builtin_pwd(exit_code);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		builtin_export(cmd, env, exit_code);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		builtin_unset(cmd, env, exit_code);
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		builtin_env(cmd, *env, exit_code);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

// exit

void	builtin_exit(t_cmd *cmd, int *exit_code, char ***env, t_cmd *all_cmds)
{
	long	code;

	if (isatty(STDIN_FILENO) && !cmd->pipe_next)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (!cmd->args[1])
		safe_exit(all_cmds, env, *exit_code);
	if (!ft_is_numeric(cmd->args[1]))
	{
		err(SHNAME ": line 1: exit: ", cmd->args[1],
			": numeric argument required");
		safe_exit(all_cmds, env, 2);
	}
	if (cmd->args[2])
	{
		err(SHNAME ": line 1: exit: ", NULL, "too many arguments");
		*exit_code = 1;
		return ;
	}
	code = ft_atol(cmd->args[1]);
	*exit_code = (unsigned char)code;
	safe_exit(all_cmds, env, *exit_code);
}

void	builtin_pwd(int *exit_code)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		*exit_code = 0;
	}
	else
	{
		err(SHNAME ": line 1: pwd: ", strerror(errno), "\n");
		*exit_code = 1;
	}
}
