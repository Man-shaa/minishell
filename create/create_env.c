/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/24 23:31:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cree l'environnement dans la structure t_envp a partir de l'environnement
// bash ou de create_my_env
// Return 1 si la creation a reussie, sinon 0
int	create_env(t_data *data, char **envp)
{
	t_envp	*env;
	int		i;
	int		env_lgt;

	env_lgt = env_lenght(envp);
	if (env_lgt == 0)
	{
		if (!create_my_env(data))
			return (0);
		return (1);
	}
	i = 0;
	env = data->envp;
	while (i < env_lgt)
	{
		if (!add_last_env(data, envp[i]))
			return (0);
		i++;
	}
	return (1);
}

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