/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:39 by mansha            #+#    #+#             */
/*   Updated: 2023/01/10 19:27:07 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Ajoute le resulat du split a la fin de la structure t_list
// Return 1 si l'ajout a reussie, sinon 0 
int	add_last_list(t_data *data, char *str)
{
	t_list	*new;
	t_list	*last;

	new = ft_lstnew(str, redir_type(str));
	if (!new)
		return (0);
	last = ft_lstlast(data->list);
	if (!last)
	{
		data->list = new;
		return (1);
	}
	last->next = new;
	new->prev = last;
	return (1);
}

// Cree un nouveau node dans la structure t_list et initialise a NULL
// Return un pointeur sur t_list ou NULL si le malloc a rate
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

// Cherche le dernier node dans la strucure t_list
// Return le dernier node ou NULL si la structure n'existe pas
t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
