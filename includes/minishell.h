/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/20 18:23:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <readline/readline.h>
# include <readline/history.h>

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

// ********************* ALLOC_FREE *******************

// alloc_free.c
void	*ft_calloc(size_t n, size_t size);
void	ft_free(void *addr);
void	free_tab(char **tab);
void	free_list(t_list *list);
void	free_data(t_data *data);

// ********************* BUILTINS *********************

// cd.c

// ******************* CREATE_INIT ********************

// create.c
t_data	*create_data(char **envp);
int		create_env(t_data *data, char **envp);
t_list	*add_to_list(t_data *data, char *str);

// *********************** ENV ************************

// env_utils.c
int		env_lenght(char **envp);
t_envp	*ft_lstnew_env(char *str);
t_envp	*add_last_env(t_data *data, char *str);

// env.c
int		is_env(char **envp);
char	*find_path_in_env(char **envp);

// ********************* PARSING **********************

// parsing.c
char	**ft_split(char *str, t_data *data);

// parsing_utils.c
int		count_chars_exp(char *str, int *count, int *n, int *i);
int		count_words_exp(char *str, int *i);

// ********************** PRINT ***********************

// print.c
void	print_tab(char **tab);
void	print_env(t_envp *envp);
void	print_list(t_list *list);

// ********************** UTILS ***********************

// list_utils.c
t_list	*ft_lstnew(char *str, int type);
t_list	*ft_lstlast(t_list *list);
t_list	*add_last(t_list *list, char *str);

// split_normal.c
int		word_count_normal(char *str, char set);
int		char_count_normal(char *str, char set, int pos);
char	*ft_putword(char *str, char *tab, char set, int pos);
char	**ft_split_normal(char	*str, char set);


// str_utils.c
int		ft_strlen(char *str);
int		ft_strchr(char *str);
char	*ft_strcmp(char *str, char *to_find);

#endif