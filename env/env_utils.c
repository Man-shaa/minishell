/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansha <mansha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/23 19:59:28 by mansha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return le nombre de variable de l'environnement bash ou 0 si il n'y en a pas
int	env_lenght(char **envp)
{
	int	i;

	i = 0;
	if (!*envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

// Cree un nouveau node pour la structure t_envp
// Return un pointeur sur t_envp ou NULL si l'allocation a rate 
t_envp	*ft_lstnew_env(char *str)
{
	t_envp	*new;

	new = ft_calloc(1, sizeof(t_envp));
	if (!new)
		return (0);
	new->tab = ft_split_env(str, '=');
	new->next = NULL;
	return (new);
}

// Ajoute un node a la fin de la structure t_envp
// Return 1 si l'operation a reussie, sinon 0
int	add_last_env(t_data *data, char *str)
{
	t_envp	*last;
	t_envp	*tmp;

	tmp = data->envp;
	last = ft_lstnew_env(str);
	if (!last)
		return (0);
	if (!data->envp)
	{
		data->envp = last;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	return (1);
}
