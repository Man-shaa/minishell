/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:12:58 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 18:04:35 by msharifi         ###   ########.fr       */
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
		if (is_same(travel->tab[0], str))
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
	char	**tab;

	tab = ft_split_env(str, '=');
	if (!tab)
		return (0);
	new = ft_calloc(1, sizeof(t_envp));
	if (!new)
		return (0);
	tab[1] = ignore_charset(tab[1], "\'\"", 1);
	new->tab = tab;
	new->next = NULL;
	return (new);
}

void	ft_env_copy(char *dest, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = '=';
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
}

char	**fill_env_tab(t_envp *envp, char **env_tab)
{
	size_t	i;
	size_t	len_str;
	t_envp	*tmp;

	tmp = envp;
	len_str = 0;
	i = 0;
	while (tmp)
	{
		len_str = ft_strlen(tmp->tab[0]) + ft_strlen(tmp->tab[1]) + 1;
		env_tab[i] = ft_calloc(len_str + 1, 1);
		if (!env_tab[i])
			return (free_tab(env_tab), NULL);
		ft_env_copy(env_tab[i], tmp->tab[0], tmp->tab[1]);
		tmp = tmp->next;
		i++;
	}
	env_tab[i] = 0;
	return (env_tab);
}

char	**get_env_tab(t_envp *envp)
{
	size_t	i;
	t_envp	*tmp;
	char	**env;

	if (!envp)
		return (NULL);
	tmp = envp;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	env = fill_env_tab(envp, env);
	return (env);
}
