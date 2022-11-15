/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:07 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
// # include <readline/readline.h>
// # include <readline/history.h>

# define WORD	1
# define IN		2 // <	lire dans 
# define OUT	3 // >	ecrire dans
# define DELIM	4 // <<	heredoc
# define APPEND	5 // >>	redirection sortie en mode append
# define PIPE	6 // |	ET

typedef struct s_cmd
{
	char			**cmd_args;
	char			*cmd_path;
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
}				t_data;

// *********************** FREE ***********************

// free.c
void	ft_free(void *addr);
void	free_tab(char **tab);
void	free_list(t_list *list);
void	free_envp(t_envp *envp);
void	free_data(t_data *data);

// ********************* BUILTINS *********************

// cd.c
int		cd(t_data *data, char *str);

// echo.c
void	echo(t_data *data, char *str);

// env.c
char	*find_path_in_env(char **envp);
void	print_env(t_envp *envp);

// exit.c

// export.c
int		export(t_data *data, char *str);
int		already_exist(t_envp *envp, char *str);
void	print_export(t_envp *envp);

// pwd.c
void	print_pwd(void);
void	replace_pwd_my_env(t_envp *envp);
void	replace_oldpwd_my_env(t_envp *envp);

// unset.c
void	unset(t_data *data, char *str);

// ******************* CREATE_INIT ********************

// create_data.c
t_data	*create_data(char **envp);

// create_env.c
int		create_env(t_data *data, char **envp);
int		create_my_env(t_data *data);
int		env_lenght(char **envp);

// create_list.c
int		add_last_list(t_data *data, char *str);
t_list	*ft_lstnew(char *str, int type);
t_list	*ft_lstlast(t_list *list);

// ********************* PARSING **********************

// split.c
int		count_words(char *str);
int		count_chars(char *str, int n);
char	*ft_putwords(char *str, int n, char *mot);
char	**ft_split(char *str, t_data *data);

// split_utils.c
int		is_in_charset(char c);
int		get_index(char *str, int n);
int		get_index_exp(char *str, int *count, int *i, int n);

// words_utils.c
int		count_words_cmd(char *str, int *i);
int		count_words_redir(char *str, int *i);
void	count_words_quote(char *str, int *i, int *count);


// chars_utils.c
int		count_chars_cmd(char *str, int *i, int *count, int n);
int		count_chars_redir(char *str, int *i, int *count, int n);
int		count_chars_pipe(int *i, int *count, int n);
int		count_chars_quote(char *str, int *i, int *count, int n);


// ********************** CORE ************************

// core.c
void	get_prompt(void);

// ********************** PRINT ***********************

// print.c
void	print_tab(char **tab);
void	print_list(t_list *list);

// ********************** UTILS ***********************

// export_utis.c
int		is_concat(char *str);
int		concat(t_envp *node, char **tab);
int		is_valid_name(char *str);
int		replace_value(t_envp *node, char *value);
char	*ignore_charset(char *str, char *charset);

// list_utils.c
t_envp	*search_node(t_envp *envp, char *str);
t_envp	*ft_lstnew_env(char *str);

// split_normal.c
int		char_count_env(char *str, char set, int pos);
char	*ft_putword_env(char *str, char *tab, char set, int pos);
char	**ft_split_env(char	*str, char set);

// str_utils.c
int		ft_strlen(char *str);
int		redir_type(char *str);
void	ft_putstr(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strcmp(char *str, char *to_find);

// str_utils_2.c
int		ft_isalnum(int a);
int		is_same(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
char	*ignore_charset(char *str, char *charset);

// utils.c
void	*ft_calloc(size_t n, size_t size);

#endif