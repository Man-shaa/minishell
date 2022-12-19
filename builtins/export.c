/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:43 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 14:22:11 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	add_last_env(t_data *data, char *arg)
{
	t_envp	*tmp;
	t_envp	*last;

	tmp = data->envp;
	last = ft_lstnew_env(arg);
	if (!last)
		return (0);
	if (!data->envp)
		data->envp = last;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = last;
	}
	return (1);
}

// Ajoute un node a la fin de la structure t_envp
// Return 0 si l'operation a reussie, sinon 1
int	ft_export(t_data *data, char **args)
{
	int		i;

	i = 0;
	if (!args || !args[0])
		return (print_export(data->envp), 0);
	while (args[i])
	{
		if (!args[i] || !args[i][0] || args[i][0] == '='
			|| !is_valid_name(args[i]))
		{
			err_msg("export: `", args[i], "': not a valid identifier");
			return (1);
		}
		if (already_exist(data->envp, args[i]))
			return (0);
		if (!add_last_env(data, args[i]))
			return (1);
		i++;
	}
	return (0);
}

// Determine si le nom de variable dans str existe deja dans t_envp
// et remplace sa valeur si c'est le cas
// Return 1 en cas de changement de valeur, sinon 0 
int	already_exist(t_envp *envp, char *str)
{
	char	**tab;
	t_envp	*travel;

	tab = ft_split_env(str, '=');
	if (!tab)
		return (0);
	travel = envp;
	while (travel)
	{
		if (is_same(travel->tab[0], tab[0]))
		{
			if (concat(travel, tab))
				return (free_tab(tab), 1);
			if (!replace_value(travel, tab[1]))
				return (free_tab(tab), 1);
			return (free_tab(tab), 1);
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
