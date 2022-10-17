/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:31:06 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/13 14:39:54 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd_table	*ft_lstnew(char	*av)
{
	t_cmd_table	*cmd_tbl;

	cmd_tbl = ft_calloc(1, sizeof(t_cmd_table));
	if (!cmd_tbl)
		return (NULL);
	cmd_tbl->cmd = av;
	cmd_tbl->next = NULL;
	return (cmd_tbl);
}

t_cmd_table	*ft_lstlast(t_cmd_table *cmd_tbl)
{
	if (!cmd_tbl)
		return (NULL);
	while (cmd_tbl->next)
		cmd_tbl = cmd_tbl->next;
	return (cmd_tbl);
}

int	add_last(t_cmd_table *cmd_tbl, char *av)
{
	t_cmd_table	*new;
	t_cmd_table	*last;

	new = ft_lstnew(av);
	if (!new)
		return (0);
	last = ft_lstlast(cmd_tbl);
	if (!last)
	{
		cmd_tbl = new;
		return (1);
	}
	last->next = new;
	return (1);
}
