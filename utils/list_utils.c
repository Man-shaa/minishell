/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:12:58 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/26 16:59:03 by msharifi         ###   ########.fr       */
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
