/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/26 16:45:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// Cherche la variable PATH qui contient tous les chemins possibles de
// commandes dans l'environnement
// Return PATH de l'environnement ou NULL si elle n'a pas ete trouvee
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



// Print l'environnement dans t_envp
void	print_env(t_envp *envp)
{
	while (envp)
	{
		if (envp->tab[1][0] != '\0')
		{
			printf("%s=", envp->tab[0]);
			printf("%s\n", envp->tab[1]);
		}
		else if (ft_strcmp(envp->tab[0], "="))
			printf("%s=", envp->tab[0]);
		envp = envp->next;
	}
	printf("\n");
}
