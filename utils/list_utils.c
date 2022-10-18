/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:31:06 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 22:55:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*ft_lstnew(char *str, int type)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (NULL);
	list->str = str;
	list->type = type;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*add_last(t_list *list, char *str, int type)
{
	t_list	*new;
	t_list	*last;

	new = ft_lstnew(str, type);
	if (!new)
		return (NULL);
	last = ft_lstlast(list);
	if (!last)
	{
		list = new;
		return (list);
	}
	last->next = new;
	new->prev = last;
	return (list);
}
