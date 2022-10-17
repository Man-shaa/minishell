/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/17 17:52:32 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
#include <readline/readline.h>
#include <readline/history.h>

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

// ********************* ALLOC_FREE *******************

// alloc_free.c
void		*ft_calloc(size_t n, size_t size);
void		ft_free(void *addr);

// ********************* UTILS *******************

// list_utils.c
t_cmd	*ft_lstnew(char	*av);
t_cmd	*ft_lstlast(t_cmd *cmd_tbl);
int			add_last(t_cmd *cmd_tbl, char *av);

// split_utils.c
int		redir(char *str);

// str_utils.c
int			ft_strlen(char *str);
int			ft_strchr(char *str, int c);

#endif