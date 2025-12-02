/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:58:12 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/24 09:44:48 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

int	close_waitall(int n_cmd, int *wait_list, int *fd_io)
{
	int	status;
	int	i;
	int	issue;

	issue = 0;
	if (fd_io[0] > 0)
		close(fd_io[0]);
	close(fd_io[1]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	i = 0;
	while (i < n_cmd)
	{
		if (wait_list[i] > 0)
			waitpid(wait_list[i++], &status, 0);
		else
		{
			issue = 1;
			i++;
		}
	}
	return (issue);
}

int	classic_manager(int argc, char **argv, char **env)
{
	int	*wait_list;
	int	n_cmd;
	int	fd_io[2];
	int	i;
	int	j;

	i = 0;
	j = 0;
	n_cmd = get_n_cmd(argc, argv);
	fd_io[0] = open(argv[1], O_RDONLY);
	if (fd_io[0] < 0)
		fd_io[0] = error_input(argv[1], i++, n_cmd--);
	else
		dup2(fd_io[0], STDIN_FILENO);
	wait_list = malloc((n_cmd) * sizeof(int));
	if (!wait_list)
		return (malloc_err());
	while (j < (n_cmd - 1))
		wait_list[j++] = create_pipe(argv[(i++) + 2], env);
	fd_io[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	wait_list[j] = last_command(argc, argv, env, fd_io[1]);
	i = close_waitall(n_cmd, wait_list, fd_io);
	free(wait_list);
	return (i);
}

int	heredoc_manager(int argc, char **argv, char **env)
{
	int	*wait_list;
	int	fd_io[2];
	int	i;
	int	j;
	int	n_cmd;

	fd_io[0] = create_here_doc_pipe(argv);
	dup2(fd_io[0], STDIN_FILENO);
	n_cmd = get_n_cmd(argc, argv);
	wait_list = malloc(n_cmd * sizeof(int));
	if (!wait_list)
		return (malloc_err());
	i = 0;
	j = 0;
	while (j < (n_cmd - 1))
		wait_list[j++] = create_pipe(argv[(i++) + 3], env);
	fd_io[1] = open(argv[argc -1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	wait_list[i++] = last_command(argc, argv, env, fd_io[1]);
	i = close_waitall(n_cmd, wait_list, fd_io);
	free(wait_list);
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	if (argc >= 5)
	{
		if (str_cmp(argv[1], "here_doc") == 0)
		{
			if (argc >= 6)
				return (heredoc_manager(argc, argv, env));
		}
		else
			return (classic_manager(argc, argv, env));
	}
	return (0);
}
