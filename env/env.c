/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/22 17:33:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// pas finit fais le apres pd
int	create_my_env(t_data *data)
{
	data->envp = add_last_env(data, "PWD=A CHERCHER");
	data->envp = add_last_env(data, "OLDPWD (A IMPLEMENTER)");
	data->envp = add_last_env(data, "SHLVL=1 (A INCREMENTER)");
	return (1);
}

// Cherche la variable "PATH=" qui contient tous les chemins possibles de commandes dans envp
char	*find_path_in_env(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		path = ft_strcmp(envp[i], "PATH=");
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}

