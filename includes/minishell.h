/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/20 18:53:38 by mfroissa         ###   ########.fr       */
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

// ********************* CREATE ***********************

// create.c
t_data	*create_data(void);
t_list	*add_to_list(t_data *data, char *str);

// ******************** PARSING ***********************

// parsing.c
int		count_words(char *str);
int		count_chars(char *str, int n);
char	*ft_putwords(char *str, int n, char *mot);
char	*get_word(char *str, int index, char *mot, int n);
char	**ft_split(char *str, t_data *data);

// parsing_utils.c
int		count_chars_exp(char *str, int *count, int *n, int *i);
int		count_words_exp(char *str, int *i);
int		ft_putwords_exp(char *str, int *i);
int		is_in_charset(char c);

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