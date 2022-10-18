/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 19:11:55 by msharifi         ###   ########.fr       */
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

typedef struct s_cmd
{
	char			**cmd_args;
	char			*cmd_path;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_redir
{
	char			*type;
	char			*porte;
	struct s_redir	*next;
}				t_redir;

typedef struct s_data
{
	t_cmd	*cmd;
	t_redir	*redir;
}				t_data;

// ********************* ALLOC_FREE *******************

// alloc_free.c
void	*ft_calloc(size_t n, size_t size);
void	ft_free(void *addr);
void	free_tab(char **tab);
void	free_cmd(t_cmd *cmd);
void	free_data(t_data *data);

// ********************* CREATE ***********************

// create.c
t_data	*create_data(void);
t_cmd	*create_cmd(t_cmd *cmd, char *str);

// ********************* PRINT ************************

// print.c
void	print_tab(char **tab);
void	print_cmd(t_cmd	*cmd);

// ********************* UTILS ************************

// list_utils.c
t_redir	*ft_lstnew_redir(void);
t_cmd	*ft_lstnew_cmd(void);
t_cmd	*ft_lstlast_cmd(t_cmd *cmd_tbl);
t_cmd	*add_last_cmd(t_cmd *cmd, char *av);

// slip_normal.c
int		word_count_normal(char *str, char set);
int		char_count_normal(char *str, char set, int pos);
char	*ft_putword_normal(char *str, char *tab, char set, int pos);
char	**ft_split_normal(char	*str, char set);


// str_utils.c
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);

#endif