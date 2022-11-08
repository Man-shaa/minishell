/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/08 16:02:31 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cree l'environnement dans la structure t_envp a partir de l'environnement
// bash ou de create_my_env
// Return 1 si la creation a reussie, sinon 0
int	create_env(t_data *data, char **envp)
{
	int		i;
	int		env_lgt;

	env_lgt = env_lenght(envp);
	if (env_lgt != 0)
	{
		if (!create_my_env(data))
			return (0);
		return (1);
	}
	i = 0;
	while (i < env_lgt)
	{
		if (!export(data, envp[i]))
			return (0);
		i++;
	}
	return (1);
}

// Cree un environnement minial si l'environnement de bash n'existe pas
// Return 1 si la creation a reussi, sinon 0
int	create_my_env(t_data *data)
{
	if (!export(data, "OLDPWD"))
		return (0);
	// replace_oldpwd_my_env(data->envp);
	if (!export(data, "PWD"))
		return (0);
	replace_pwd_my_env(data->envp);
	if (!export(data, "SHLVL=1"))
		return (0);
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
