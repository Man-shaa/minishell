/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:31:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/13 14:44:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_cmd_table
{
	char				*cmd;
	char				*cmd_path;
	struct s_cmd_table	*next;
}				t_cmd_table;

// ********************* ALLOC_FREE *******************

// alloc_free.c
void		*ft_calloc(size_t n, size_t size);
void		ft_free(void *addr);

// ********************* UTILS *******************

// list_utils.c
t_cmd_table	*ft_lstnew(char	*av);
t_cmd_table	*ft_lstlast(t_cmd_table *cmd_tbl);
int			add_last(t_cmd_table *cmd_tbl, char *av);

// str_utils.c
int			ft_strlen(char *str);
int			ft_strchr(char *str, int c);

#endif