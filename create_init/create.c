/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansha <mansha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:16:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/23 19:53:02 by mansha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Malloc et initialise a NULL la struct t_data
// Return pointeur sur data si la creation a reussie, sinon NULL
t_data	*create_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd = NULL;
	data->list = NULL;
	data->envp = NULL;
	if (!create_env(data, envp))
		return (free_data(data), NULL);
	return (data);
}

// Ajoute le resulat du split a la fin de la structure t_list
// Return 1 si l'ajout a reussie, sinon 0 
int	add_last_list(t_data *data, char *str)
{
	t_list	*new;
	t_list	*last;
	
	new = ft_lstnew(str, ft_strchr(str));
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
