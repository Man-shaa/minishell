/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:43 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/27 17:46:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Ajoute un node a la fin de la structure t_envp
// Return 1 si l'operation a reussie, sinon 0
int	export(t_data *data, char *str)
{
	t_envp	*last;
	t_envp	*tmp;

	if (!str || !str[0] || str[0] == '=')
		return (1);
	if (already_exist(data->envp, str))
		return (1);
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

// int	is_concat(t_envp *envp)

int	replace_value(t_envp *node, char *value)
{
	ft_free(node->tab[1]);
	node->tab[1] = ft_strdup(value);
	if (!node->tab[1])
		return (0);
	return (1);
}

// Determine si le nom de variable dans str existe deja dans t_envp
// et remplace sa valeur si c'est le cas
// Return 1 en cas de changement de valeur, sinon 0 
int	already_exist(t_envp *envp, char *str)
{
	char 	**tab;
	t_envp	*travel;

	tab = ft_split_env(str, '=');
	if (!tab)
		return (0);
	travel = envp;
	while (travel)
	{
		if (is_same(travel->tab[0], tab[0]))
		{
			if (!replace_value(travel, tab[1]))
				return (free_tab(tab), 0);
			return (free_tab(tab), 1);
			// or concat if "+="
		}
		travel = travel->next;
	}
	return (free_tab(tab), 0);
}

// Print l'environnement de export de la struct t_envp
void	print_export(t_envp *envp)
{
	while (envp)
	{
		if (envp->tab[1] && envp->tab[1][0])
		{
			printf("declare -x %s=", envp->tab[0]);
			printf("\"%s\"\n", envp->tab[1]);
		}
		else
			printf("declare -x %s\n", envp->tab[0]);
		envp = envp->next;
	}
}
