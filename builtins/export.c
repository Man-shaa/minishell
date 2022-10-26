/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:43 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/26 17:08:40 by msharifi         ###   ########.fr       */
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

// Print l'environnement de export de la struct t_envp
void	print_export(t_envp *envp)
{
	while (envp)
	{
		printf("declare -x %s=", envp->tab[0]);
		printf("\"%s\"\n", envp->tab[1]);
		envp = envp->next;
	}
}
