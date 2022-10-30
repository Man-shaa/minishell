/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:12:58 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/29 20:22:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cherche un node de t_envp grace au NOM de la variable (envp->tab[0])
// Return un pointeur sur la premiere occurence, sinon NULL
t_envp	*search_node(t_envp *envp, char *str)
{
	t_envp	*travel;

	travel = envp;
	while (travel)
	{
		if (ft_strcmp(travel->tab[0], str))
			return (travel);
		travel = travel->next;
	}
	return (NULL);
}

// Cree un nouveau node pour la structure t_envp
// Return un pointeur sur t_envp ou NULL si l'allocation a rate 
t_envp	*ft_lstnew_env(char *str)
{
	t_envp	*new;
	char	*var;
	char	**tab;

	tab = ft_split_env(str, '=');
	if (!tab)
		return (0);
	new = ft_calloc(1, sizeof(t_envp));
	if (!new)
		return (0);
	if (is_concat(tab[0]))
	{
		var = ft_strndup(tab[0], 0);
		ft_free(tab[0]);
		tab[0] = ft_strndup(var, ft_strlen(var) - 1);
		ft_free(var);
	}
	new->tab = tab;
	new->next = NULL;
	return (new);
}
