/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/09 20:06:21 by mfroissa         ###   ########.fr       */
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

# define WORD	1
# define IN		2 // <	lire dans 
# define OUT	3 // >	ecrire dans
# define DELIM	4 // <<	heredoc
# define APPEND	5 // >>	redirection sortie en mode append
# define PIPE	6 // |	ET

typedef struct s_proc
{
	int		fd_in;
	int		fd_out;
	int		**pipe_fd;
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
	struct s_list	*next;
	struct s_list	*prev;
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
	int		return_val;
}				t_data;

// *************************** BUILTINS ***************************

// builtins.c
int		is_builtin(char *str);
int		exec_builtin(t_data *data, char *cmd, char **args);

// cd.c
int		ft_cd(t_data *data, char *str);

// echo.c
void	ft_echo(t_data *data, char **args);

// env.c
int		print_env(t_envp *envp, char **args);

// exit.c
int		ft_exit(t_data *data, char **args);

// export.c
int		ft_export(t_data *data, char **args);
int		already_exist(t_envp *envp, char *str);
void	print_export(t_envp *envp);

// pwd.c
void	print_pwd(void);
void	replace_pwd_my_env(t_envp *envp);
void	replace_oldpwd_my_env(t_envp *envp);

// unset.c
void	ft_unset(t_data *data, char *str);

// ******************************** CORE **********************************

// core.c
void	reset_data(t_data *data, char *str);
void	get_prompt(char **envp);
char	*get_readline(t_data *data, char *str);

// ******************************* CREATE *********************************

// create_cmd.c
int		get_cmd_struct(t_data *data);
int		start_cmd_struct(t_data *data, t_list *tmp, t_cmd *cmd);
t_cmd	*set_up_cmd(t_data *data, int *i);

// create_data.c
t_data	*create_data(char **envp);

// create_env.c
int		create_env(t_data *data, char **envp);
int		create_my_env(t_data *data);
int		env_length(char **envp);

// create_list.c
int		add_last_list(t_data *data, char *str);
t_list	*ft_lstnew(char *str, int type);
t_list	*ft_lstlast(t_list *list);

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
int		execution(t_data *data);
void	wait_all_child(t_proc *proc, int n);
int		exec_binary(t_data *data, t_cmd *cmd);
int		send_cmd(t_data *data, t_cmd *cmd);

// heredoc.c
int		create_heredoc(char *delim);

// pipe.c
int		create_pipes(t_proc *proc);
int		create_pipes_array(t_data *data);
void	close_pipes(t_proc *proc);

// redirections.c
int		is_token(t_cmd *cmd, int type);
int		handle_pipe_redir(t_cmd *cmd, t_proc *proc);
int		redir(t_data *data, t_cmd *cmd);
int		handle_token_redir(t_proc *proc, char *token, int type);

// ********************************* FREE *********************************

// free_2.c
void	free_int_tab(int **tab, int last);
void	free_proc(t_proc *proc);

// free.c
void	free_tab(char **tab);
void	free_list(t_list *list);
void	free_envp(t_envp *envp);
void	free_cmd(t_cmd *cmd);
void	free_data(t_data *data);

// ******************************* HISTORY ********************************

// history.c
void	add_to_history(char **av);

// ******************************* PARSING ********************************

// parsing.c
int		parsing(t_data *data);
int		check_dup(t_data *data);
int		check_cmd(t_data *data);

// ******************************** PRINT *********************************

// print.c
void	print_list(t_list *list);
void	print_struct_cmd(t_data *data);
void	print_tab(char **tab);
void	print_pipe_fd(int **tab, int until);
void	print_int_tab(t_data *data, int *tab);

// ******************************** SIGNAL *********************************

// signal.c
void	handle_sigquit(int sig_quit);
void	handle_sigsegv(int sig_segv);
void	handle_sigint(int sig_int);
void	handle_signal(void);

// ******************************** SPLIT **********************************

// split.c
int		count_words(char *str);
int		count_chars(char *str, int n);
char	*ft_putwords(char *str, int n, char *mot);
void	ft_split(char *str, t_data *data);

// split_utils.c
int		is_in_charset(char c);
int		is_end_of_string(char c);
int		get_index(char *str, int n);
int		get_index_exp(char *str, int *count, int *i, int n);

// words_utils.c
int		count_words_cmd(char *str, int *i);
int		count_words_redir(char *str, int *i);
int		count_words_pipe(int *i);
int		count_words_quote(char *str, int *i, int *count);
int		count_words_single(char *str, int *i, int *count);

// chars_utils.c
int		count_chars_cmd(char *str, int *i, int *count, int n);
int		count_chars_redir(char *str, int *i, int *count, int n);
int		count_chars_pipe(int *i, int *count, int n);
int		count_chars_quote(char *str, int *i, int *count, int n);
int		count_chars_single(char *str, int *i, int *count, int n);

// ******************************** UTILS *********************************

// cmd_utils_two.c
void	add_back(t_data *data, t_cmd *cmd);
t_cmd	*ft_cmdnew(int index);
t_cmd	*ft_cmdlast(t_cmd *cmd);
int		pipe_count(t_cmd *cmd);

// cmd_utils.c
int		count_tokens(t_data *data, int n);
int		words_to_pipe(t_data *data, int n);
int		command_or_builtin(char *str, int *cappuccino);

// echo_utils.c
int		ft_putstr_echo(t_data *data, char **str, int i);
int		is_option_n(char *str);
int		echo_env_var(t_data *data, char *args);

// export_utis.c
int		is_concat(char *str);
int		concat(t_envp *node, char **tab);
int		is_valid_name(char *str);
int		replace_value(t_envp *node, char *value);

// env_list_utils.c
t_envp	*search_node(t_envp *envp, char *str);
t_envp	*ft_lstnew_env(char *str);
char	**fill_env_tab(t_envp *envp, char **env_tab);
char	**get_env_tab(t_envp *envp);

// exec_utils.c
int		is_path(t_data *data, char *av);
char	*find_path_in_env(char **envp);
int		is_absolute_path(t_data *data, t_cmd *cmd);
int		find_cmd_path(t_data *data, t_cmd *cmd, char *env_path);
int		is_cmd(t_data *data, char *str, char *env_path);

// split_env.c
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

// str_utils.c
size_t	ft_strlen(char *str);
int		redir_type(char *str);
void	ft_putstr(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strcmp(char *str, char *to_find);

// utils.c
void	ft_free(void *addr);
void	*ft_calloc(size_t n, size_t size);
long	ft_atoi(const char *str);
void	ft_putnbr(int n);

#endif
