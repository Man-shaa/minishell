/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/21 23:41:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <signal.h>
# include <wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WORD		1
# define IN			2 // <	lire dans
# define OUT		3 // >	ecrire dans
# define HERE		4 // <<	heredoc
# define APPEND		5 // >>	redirection sortie en mode append
# define PIPE		6 // | ET

extern int	g_return_val;

typedef struct s_proc
{
	int		fd_in;
	int		fd_out;
	int		**pipe_fd;
	int		*fd_heredoc;
	int		n_heredoc;
	int		n_pipes;
	pid_t	*pid;
}				t_proc;

typedef struct s_cmd
{
	char			*cmd;
	char			*cmd_path;
	char			**opt;
	char			**token;
	int				*type;
	int				index;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_list
{
	char			*str;
	int				type;
	int				*dollar;
	struct s_list	*next;
}				t_list;

typedef struct s_envp
{
	char			**tab;
	struct s_envp	*next;
}				t_envp;

typedef struct s_data
{
	t_cmd	*cmd;
	t_list	*list;
	t_envp	*envp;
	t_proc	*proc;
	char	*env_path;
}				t_data;

// *************************** BUILTINS ***************************

// builtins.c
int		is_builtin(char *str);
void	send_to_individual_builtin(t_data *data, t_cmd *cmd, char **args);
int		send_builtin_fork(t_data *data, t_cmd *cmd, char **args);
int		exec_builtin(t_data *data, t_cmd *cmd, char **args);

// cd.c
int		is_a_dir(char *str);
int		check_cd(char **args, int m);
int		ft_cd(t_data *data, char **args, int m);

// echo.c
int		is_option_n(char *str);
int		echo_each_arg(char **args, int i);
int		ft_echo(char **args);
char	**ft_split_echo(char	*str, char set);

// env.c
int		print_env(t_envp *envp, char **args);

// exit.c
int		ft_exit(t_data *data, char **args);

// export.c
int		add_last_env(t_data *data, char *arg);
int		already_exist(t_envp *envp, char *str);
void	print_export(t_envp *envp);
int		ft_export(t_data *data, char **args, int i);

// pwd.c
int		print_pwd(void);
void	replace_oldpwd_my_env(t_envp *envp);
void	replace_pwd_my_env(t_envp *envp);

// unset.c
void	unset_option(t_data *data, char *arg);
int		ft_unset(t_data *data, char **args);

// ******************************** CORE **********************************

// core.c
void	reset_data(t_data *data, char *str);
void	get_prompt(char **envp);
char	*get_readline(t_data *data, char *str);

// ******************************* CREATE *********************************

// create_cmd.c
t_cmd	*set_up_cmd(t_data *data, int *i);
int		get_cmd_struct(t_data *data);
int		start_cmd_struct(t_data *data, t_list *tmp, t_cmd *cmd);

// create_data.c
t_data	*create_data(char **envp);

// create_env.c
int		env_length(char **envp);
int		create_my_env(t_data *data);
int		create_env(t_data *data, char **envp);

// create_list.c
t_list	*ft_lstnew(char *str, int type);
t_list	*ft_lstlast(t_list *list);
int		add_last_list(t_data *data, char *str);

// create_proc.c
t_proc	*create_proc(void);

// fill_cmd.c
t_list	*fill_cmd_struct(t_data *data, t_cmd *cmd, t_list *tmp, int *j);
t_list	*fill_cmd_tokens(t_cmd *cmd, t_list *tmp, int *k);
void	handle_cmd(t_data *data, t_cmd *cmd, t_list *tmp, int *j);

// ********************************* ERROR ********************************

// error.c
int		err_msg(char *start, char *str, char *end, int ret);
int		error_cmd(char **cmd);

// ********************************* EXEC *********************************

// exec.c
void	wait_all_child(t_data *data, int n);
int		execve_binary(t_data *data, t_cmd *cmd);
int		exec_binary(t_data *data, t_cmd *cmd);
int		send_cmd(t_data *data, t_cmd *cmd);
int		execution(t_data *data);

// heredoc.c
char	*expand_heredoc(t_envp *envp, char *str);
int		fill_heredoc(t_envp *envp, char *delim, int fd);
int		which_heredoc(t_data *data, t_cmd *cmd, int cmd_pos);
int		create_heredoc(t_cmd *cmd, t_data *data, int cmd_pos);
int		print_all_heredoc(t_data *data);

// pipe.c
int		create_pipes(t_proc *proc);
int		create_pipes_array(t_data *data);
void	close_pipes(t_proc *proc);

// redirections.c
int		handle_pipe_redir(t_data *data, t_cmd *cmd, t_proc *proc);
int		handle_token_redir3(int cmd_pos);
int		handle_token_redir2(t_data *data, t_cmd *cmd, int cmd_pos, int m);
int		handle_token_redir(t_data *data, t_cmd *cmd, int cmd_pos, int m);
int		redir(t_data *data, t_cmd *cmd, int m);

// ********************************* FREE *********************************

// free_2.c
void	free_tab_n(char **tab, int n);
void	ft_free(void *addr);
void	free_int_tab(int **tab, int last);
void	free_proc(t_proc *proc);
void	free_data_proc(t_data *data);

// free.c
void	free_tab(char **tab);
void	free_list(t_list *list);
void	free_envp(t_envp *envp);
void	free_cmd(t_cmd *cmd);
void	free_data(t_data *data);

// ******************************* PARSING ********************************

// dollars.c
char	*replace_ret_val(char *str, int index);
char	*replace_dollar(t_envp *envp, char *big_str, int *index);
char	*new_str(char *big_str, char *res, int *index);
void	handle_dollar(t_data *data, t_list *list);

// fill_dollar.c
int		fill_dollar_tab(t_list *tmp);
void	fill_dollar_dq(t_list *tmp, int *i, int *index);
void	fill_dollar_sq(t_list *tmp, int *i, int *index);
void	fill_dollar(t_list *tmp, int *i, int *index);

// parsing.c
int		check_pipe(t_data *data);
int		check_redir(char *str, int *i);
int		check_dup(t_data *data);
int		check_quotes(char *str, int i);
int		parsing(t_data *data);

//quotes_utils.c
int		ft_strlen_quotes(char *str, int i);
void	remove_dq(char *str, char *new, int *i, int *j);
void	remove_sq(char *str, char *new, int *i, int *j);
char	*remove_quotes(char *str);

// quotes.c
int		count_dollars(char *str);
int		handle_dollar_quote(t_data *data);
int		check_quotes_ret(char *str);

// ******************************** PRINT *********************************

// print_1.c
void	print_list(t_list *list);
void	print_struct_cmd(t_data *data);
void	print_tab(char **tab);
void	print_pipe_fd(int **tab, int until);

//print_2.c
void	print_int_tab(t_data *data, int *tab);
void	print_tab_index(int *tab, int n);

// ******************************** SIGNAL *********************************

// signal_2.c
void	handle_sighere(int sig_int);
void	handle_exec(int sig_int);
void	handle_sigint_exec(void);

// signal.c
void	handle_sigquit(int sig_quit);
void	handle_sigsegv(int sig_segv);
void	handle_sigint(int sig_int);
void	handle_signal(void);

// ******************************** SPLIT **********************************

// chars_quotes.c
int		count_chars_double(char *str, int *i, int *count, int n);
int		count_chars_double_inner(char *str, int *i, int *count, int n);
int		count_chars_single(char *str, int *i, int *count, int n);
int		count_chars_single_inner(char *str, int *i, int *count, int n);

// chars_utils.c
int		count_chars_cmd(char *str, int *i, int *count, int n);
int		count_chars_redir(char *str, int *i, int *count, int n);
int		count_chars_pipe(int *i, int *count, int n);

// split_index.c
int		get_index(char *str, int n);
int		get_index_exp(char *str, int *count, int *i, int n);
void	get_index_dq(char *str, int *count, int *i);
void	get_index_sq(char *str, int *count, int *i);

// split_utils.c
int		is_in_charset(char c);
int		is_end_of_string(char c);

// split.c
int		count_words(char *str);
int		count_chars(char *str, int n);
char	*ft_putwords(char *str, int n, char *mot);
int		ft_split(char *str, t_data *data);

// words_utils.c
int		count_words_cmd(char *str, int *i);
int		count_words_redir(char *str, int *i);
int		count_words_pipe(int *i);
int		count_words_quote(char *str, int *i, int *count);
int		count_words_single(char *str, int *i, int *count);

// ******************************** UTILS *********************************

// cmd_utils_two.c
void	add_back(t_data *data, t_cmd *cmd);
t_cmd	*ft_cmdnew(int index);
t_cmd	*ft_cmdlast(t_cmd *cmd);
int		pipe_count(t_cmd *cmd);

// cmd_utils.c
int		count_redir(t_data *data, int n);
int		count_tokens(t_data *data, int n);
int		words_to_pipe(t_data *data, int n);
int		command_or_builtin(char *str, int *cappuccino);

// env_list_utils.c
t_envp	*search_node(t_envp *envp, char *str);
t_envp	*ft_lstnew_env(char *str);
void	ft_env_copy(char *dest, char *s1, char *s2);
char	**fill_env_tab(t_envp *envp, char **env_tab);
char	**get_env_tab(t_envp *envp);

// exec_utils.c
int		is_path(t_cmd *cmd, char *av);
char	*find_path_in_env(char **envp);
int		is_absolute_path(t_cmd *cmd);
int		find_cmd_path(t_data *data, t_cmd *cmd, char *env_path);
int		is_cmd(t_data *data, t_cmd *cmd, char *str, char *env_path);

// export_utils.c
int		is_concat(char *str);
int		concat_inexist(t_data *data, char *str);
int		concat(t_envp *node, char **tab);
int		is_valid_name(char *str);
int		replace_value(t_envp *node, char *value);

// heredoc_utils.c
int		is_last_heredoc(t_data *data, t_cmd *cmd, int cmd_pos);
int		count_all_heredoc(t_data *data);

// redirections_utils.c
int		is_token(t_cmd *cmd, int type);
int		is_last_cmd_token_out(t_data *data, int index);
void	create_files(t_data *data, t_cmd *cmd);

// split_echo.c
int		word_count_echo(char *str, char set);
int		char_count_pos(char *str, int i, char set);
int		char_count_echo(char *str, char set, int pos);
char	*put_word_pos(char *str, int i, char *tab, char set);
char	*putword_echo(char *str, char *tab, char set, int pos);

// split_env.c
int		first_sep(char *str, char sep);
int		char_count_env(char *str, char set, int pos);
void	ft_putword_env(char *str, char *tab, char set, int pos);
char	**ft_split_env(char	*str, char set);

// split_normal.c
int		word_count_normal(char *str, char set);
int		char_count_normal(char *str, char set, int pos);
char	*putword_normal(char *str, char *tab, char set, int pos);
void	free_tab_split(char **tab, int i);
char	**ft_split_normal(char	*str, char set);

// str_utils_2.c
int		ft_isalpha(int a);
int		is_same(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*ignore_charset(char *str, char *charset, int n);

// str_utils_3.c
char	*ft_substr(char *str, int n);
int		is_sep(int a);
char	*ft_strdup_until(char *str, int n);
void	fill(char *str, long long nb, int j);
char	*ft_itoa(long long n);

// str_utils.c
size_t	ft_strlen(char *str);
int		redir_type(char *str);
void	ft_putstr(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strcmp(char *str, char *to_find);

// utils.c
void	*ft_calloc(size_t n, size_t size);
long	ft_atoi(const char *str);
void	ft_putnbr(int n);

#endif
