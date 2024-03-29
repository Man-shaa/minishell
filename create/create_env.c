/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 21:36:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return le nombre de variable de l'environnement bash ou 0 si il n'y en a pas
int	env_length(char **envp)
{
	int	i;

	i = 0;
	if (!*envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

// Cree un environnement minial si l'environnement de bash n'existe pas
// Return 1 si la creation a reussi, sinon 0
int	create_my_env(t_data *data)
{
	char	**tab;

	tab = ft_calloc(4, sizeof(char *));
	tab[0] = ft_strndup("OLDPWD", 0);
	tab[1] = ft_strndup("PWD", 0);
	tab[2] = ft_strndup("SHLVL=1", 0);
	tab[3] = 0;
	if (ft_export(data, tab, 1))
		return (0);
	replace_pwd_my_env(data->envp);
	free_tab(tab);
	return (1);
}

// Cree l'environnement dans la structure t_envp a partir de l'environnement
// bash ou de create_my_env
// Return 1 si la creation a reussie, sinon 0
int	create_env(t_data *data, char **envp)
{
	int		env_lgt;

	env_lgt = env_length(envp);
	if (env_lgt == 0)
	{
		if (!create_my_env(data))
			return (0);
		return (1);
	}
	ft_export(data, envp, 1);
	data->env_path = find_path_in_env(envp);
	return (1);
}
