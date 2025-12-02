/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:02 by matsauva          #+#    #+#             */
/*   Updated: 2025/04/23 14:26:39 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "ft_printf.h" // printf is allowed
# include "get_next_line.h"
# include "libft.h"
# include <errno.h> // errno
# include <stdio.h>     // printf, perror
# include <fcntl.h> // open, close
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>    // signal, sigaction
# include <stdlib.h>    // malloc, free, exit
# include <string.h>    // strerror
# include <sys/ioctl.h> // Provides ioctl() and FIONREAD s
# include <sys/stat.h>
# include <sys/types.h> // pid_t
# include <sys/wait.h>  // wait, waitpid
# include <unistd.h>    // write, read, close, fork, execve

# define INPUT_SIZE 8192 // Max expanded arg size
# define PROMPT "\001\033[0;32m\002minishell$ \001\033[0m\002"
# define CTRLC "^C\n"
# define SHNAME "minishell"
# define ERR_SYNTAX "syntax error"
# define ERR_QUOTE "missing closing quote"
# define ERR_HEREDOC_INTERRUPTED "warning: heredoc interrupted by Ctrl+C"
# define ERR_NO_FILE "No such file or directory\n"
# define MSG_HEREDOC "minishell: warning: heredoc interrupted by Ctrl+C\n"
# define MSG_QUOTE "minishell: syntax error : missing closing quote\n"
# define SYNTAX_ERR_MSG ": syntax error near unexpected token `"
# define SYNTAX_ERR_NL ": syntax error near unexpected token `newline'\n"
# define ARG_JOIN 1
# define ARG_EXPANDED 2

extern volatile sig_atomic_t	g_last_signal;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC
}								t_token_type;

typedef enum e_redir_type
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}								t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*filename;
	int				quoted;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	int				heredoc_fd;
	int				pipe_next;
	int				from_expansion;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_token
{
	char			*value;
	int				type;
	int				join_next;
	int				quoted;
	struct s_token	*next;
}	t_token;

typedef struct s_exec_context
{
	t_cmd			*all_cmds;
	char			***env;
	int				*exit_code;
}	t_exec_context;

typedef struct s_proc_ctx
{
	t_cmd			*cmd;
	char			*cmd_path;
	int				input_fd;
	int				pipe_fd[2];
	t_exec_context	*exec;
}	t_proc_ctx;

typedef struct s_fd_state
{
	int				has_stdin;
	int				has_stdout;
}	t_fd_state;

typedef struct s_parse_ctx
{
	t_cmd			**new;
	t_cmd			**head;
	t_cmd			**last;
	int				*is_first;
	char			**arg_buf;
	char			**env;
	int				*exit_code;
	int				arg_buf_expan;
	int				*arg_buf_quote;
}	t_parse_ctx;

typedef struct s_expand_ctx
{
	char			*raw;
	char			*res;
	char			**env;
	int				*exit_code;
	int				j;
	size_t			i;
	char			quote;
	int				i_q;
}	t_expand_ctx;

typedef struct s_cmd_bundle
{
	t_cmd	*head;
	t_cmd	*last;
	t_cmd	*new;
}	t_cmd_bundle;

typedef struct s_env
{
	char	*key;
	char	*plus;
	char	*existing;
	char	*full;
	char	*addition;
	int		index;
}	t_env;

typedef struct s_token_ctx
{
	t_token	**tokens;
	t_token	**last;
	char	*prev_input;
	char	**input;
}	t_token_ctx;

typedef struct s_heredoc_ctx
{
	t_redir	*r;
	int		fd;
	char	*tmp_name;
	char	**env;
	int		*exit_code;
}	t_heredoc_ctx;

void		print_syntax_error(const char *token);
void		prompt_loop(char ***env, int *exit_code);
void		setup_signals(void);
void		setup_heredoc_signals(void);
int			tokenize(char *input, t_token **tokens);
void		remove_quotes_inplace(char *str);
int			parse_tokens(t_token *tokens, t_cmd **cmds, char **env,
				int *exit_code);
t_token		*parse_word_token(char **input);
int			collect_heredocs(t_cmd *cmds, char **env, int *exit_code);
int			append_exit_code(t_expand_ctx *ctx);
int			append_env_var(t_expand_ctx *ctx);
char		*expand_word(char *raw, char **env, int *exit_code, int quoted);
int			apply_redirections(t_cmd *cmd, int pipe_fd[2], int input_fd,
				t_exec_context *ctx);
int			validate_commands(t_cmd *cmds);
char		*strjoin_and_free(char *s1, const char *s2);
int			is_quoted(char *str);
int			ft_is_space(char c);
int			ft_is_empty(char *str);
void		trim_trailing_whitespace(char *str);
void		skip_whitespace(char **input);
int			ft_is_digit(char c);
int			ft_is_alpha(char c);
int			ft_is_numeric(const char *str);
int			is_var_char(char c);
int			is_var_name_char(char c);
void		free_tokens(t_token **tokens);
void		free_commands(t_cmd *cmds);
void		add_token(t_token **list, t_token *new);
void		execute_commands(t_cmd *cmds, char ***env, int *exit_code);
t_token		*create_token(char *value, t_token_type type);
int			is_redir_token(t_token_type type);
t_cmd		*create_cmd_node(void);
void		add_cmd(t_cmd **head, t_cmd **last,	t_cmd **new);
int			is_single_quote_token(const char *s);
int			is_builtin(char *cmd);
void		execute_builtin(t_cmd *cmd, char ***env, int *exit_code,
				t_cmd *all_cmds);
void		builtin_exit(t_cmd *cmd, int *exit_code, char ***env,
				t_cmd *all_cmds);
long		ft_atol(const char *str);
void		builtin_cd(t_cmd *cmd, char **env, int *exit_code);
void		builtin_pwd(int *exit_code);
void		builtin_echo(t_cmd *cmd, int *exit_code);
void		builtin_env(t_cmd *cmd, char **env, int *exit_code);
void		builtin_export(t_cmd *cmd, char ***env,	int *exit_code);
void		builtin_unset(t_cmd *cmd, char ***env,	int *exit_code);
char		*path_manager(char *cmd, t_exec_context *ctx);
char		*path_relative(char *cmd);
char		*add_path_to_cmd(char *cmd, char **env);
int			check_exe_perm(char *cmd, char *printed_cmd, int *exit_code);
char		*get_env(char **env, char *needle);
char		*get_env_value(const char *var_name, char **env);
char		*check_env(char *arg, int *exit_code, char **env);
void		err(const char *msg1, const char *msg2,	const char *msg3);
void		sort_env(char **env, int size);
void		safe_exit(t_cmd *cmds, char ***env, int code);
void		free_strs(char **strs);
int			open_heredoc_fd(char *filename);
int			handle_single_redirection(t_cmd *cmd, t_redir *r,
				t_exec_context *ctx, t_fd_state *fds);
void		handle_execve(t_proc_ctx *pctx);
int			apply_redirections(t_cmd *cmd, int pipe_fd[2],
				int input_fd, t_exec_context *ctx);
int			is_builtin_no_pipe(t_cmd *cmd, int input_fd);
int			fork_command(int *exit_code);
void		update_input_for_next_pipe(int pipe_fd[2], int *input_fd);
void		update_input_after_fork(t_cmd *cmd, int pipe_fd[2], int *input_fd);
void		wait_for_children(int *exit_code);
void		process_heredoc_line(char *line, t_heredoc_ctx *ctx);
int			create_first_arg(t_cmd *cmd, char *value);
char		*concat_arg_buffer(char *buf, char *next);
int			add_arg_token(t_cmd *cmd, char *val, int *is_first, int flags);
int			handle_word_token(t_token *tok, t_cmd *cmd, t_parse_ctx *ctx);
int			is_relative(char *cmd);
char		*resolve_relative_path(char *cmd);
int			join_with_previous_arg(t_cmd *cmd, char *value);
void		print_single_export(char *entry);
void		print_export_env(char **env);
void		append_env_entry(char *arg, char ***env);
void		replace_env_entry(char **env, int index, char *arg);
char		*join_env_key_value_append(char *key, char *existing_value,
				char *addition);
void		add_key_if_missing(char *key, char ***env);
char		*get_key_from_arg(const char *arg);
int			find_env_index(char **env, char *key);
char		**malloc_env_copy(char **env, int extra);
int			is_valid_key(char *arg);
char		*resolve_cmd_path(char *cmd, t_exec_context *ctx);
int			flush_arg_buffer(t_cmd *cmd, char **arg_buf, int *is_first,
				int from_expansion);
int			flush_arg_buffer_and_add(t_cmd *cmd, t_parse_ctx *ctx, char *exp);
void		print_tokens(t_token *tokens);
void		print_cmds(t_cmd *cmds);
const char	*redir_type_str(t_redir_type type);
int			flush_buffer_to_arg(t_cmd *cmd, t_parse_ctx *ctx, char *expanded);
int			append_to_buffer(t_token *tok, t_parse_ctx *ctx, char *expanded,
				int was_expanded);
int			is_char_quote(char c);
t_token		*create_token_symbol(char **input, const char *s, int type,
				int adv);
char		*return_or_free_empty(char *res);
void		strip_result_if_needed(t_expand_ctx *ctx);
int			setup_pipe(int pipe_next, int pipe_fd[2], int *exit_code);
void		execute_builtin_no_pipe(t_cmd *cmd, t_exec_context *ctx);
void		execute_child_process(t_cmd *cmd, int pipe_fd[2], int input_fd,
				t_exec_context *ctx);
char		*concat_redir_filename(t_token **tok, t_parse_ctx *ctx,
				int do_expand);
char		*concat_arg_buffer(char *buf, char *next);
int			create_first_arg(t_cmd *cmd, char *value);
int			handle_redirection_token(t_token **tok, t_cmd *cmd,
				t_parse_ctx *ctx);
int			handle_redir_token(t_token **tok, t_cmd *cmd, t_parse_ctx *ctx);
int			process_token_node(t_token **tokens, t_cmd **new, t_parse_ctx *ctx);
int			process_node(t_token **curr, t_cmd **new, t_parse_ctx *ctx);
int			is_interactive_shell(void);
int			handle_pipe_token(t_cmd **new, t_parse_ctx *ctx);
int			set_redir_type(t_redir *r, t_token_type tok_type);
void		append_redir(t_cmd *cmd, t_redir *redir);
int			extract_expanded_word(t_token *tok, t_parse_ctx *ctx, char **out,
				int *was_expanded);
int			add_simple_arg(t_cmd *cmd, t_parse_ctx *ctx, char *expanded,
				int was_expanded);
int			append_arg(t_cmd *cmd, char *value);
char		*safe_strdup_empty_if_needed(char *filename);
void		handle_heredoc_prompt_stream(void);
int			handle_heredoc_interrupt(int fd, char *line, int *exit_status,
				char *tmp_name);

#endif