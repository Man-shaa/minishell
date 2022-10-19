/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/19 05:09:25 by msharifi         ###   ########.fr       */
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

typedef struct s_data
{
	t_cmd	*cmd;
	t_list	*list;
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


// ********************* CREATE ***********************

// create.c
t_data	*create_data(void);
t_list	*add_to_list(t_data *data, char *str);

// ******************** PARSING ***********************

// parsing.c
char	**ft_split(char *str);

// ********************* PRINT ************************

// print.c
void	print_tab(char **tab);
void	print_list(t_list *list);

// ********************* UTILS ************************

// list_utils.c
t_list	*ft_lstnew(char *str, int type);
t_list	*ft_lstlast(t_list *list);
t_list	*add_last(t_list *list, char *str);

// str_utils.c
int		ft_strlen(char *str);
int		ft_strchr(char *str);

#endif