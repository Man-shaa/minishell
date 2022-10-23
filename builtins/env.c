/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansha <mansha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/23 19:52:20 by mansha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cree un environnement minial si l'environnement de bash n'existe pas
// Return 1 si la creation a reussi, sinon 0
int	create_my_env(t_data *data)
{
	if (!add_last_env(data, "PWD=A CHERCHER"))
		return (0);
	if (!add_last_env(data, "OLDPWD (A IMPLEMENTER)"))
		return (0);
	if (!add_last_env(data, "SHLVL=1 (A INCREMENTER)"))
		return (0);
	return (1);
}

// Cherche la variable PATH qui contient tous les chemins possibles de commandes dans l'environnement
// Return la variable PATH de l'environnement ou NULL si elle n'a pas ete trouvee
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

// Cree l'environnement dans la structure t_envp a partir de l'environnement bash ou de create_my_env
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
	return(1);
}

// Print l'environnement dans t_envp
void	print_env(t_envp *envp)
{
	while (envp)
	{
		if (envp->tab[1])
		{
			printf("%s=", envp->tab[0]);
			printf("%s\n", envp->tab[1]);
		}
		else
		{
			printf("\nSANS VALEUR : ");
			printf("%s=", envp->tab[0]);
			printf("%s\n\n", envp->tab[1]);
		}
		envp = envp->next;
	}
}