/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/21 13:57:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Print l'environnement dans t_envp
// Return 0 si tout s'set bien passe, 127 si il y a une erreur
int	print_env(t_envp *envp, char **args)
{
	int	i;

	i = 0;
	if (args && args[0])
	{
		while (args[i] && is_same(args[i], "env"))
			i++;
		if (args[i])
			return (err_msg("env: '", args[i], "' No such file or directory",
					127));
	}
	while (envp)
	{
		if (envp->tab[1])
		{
			printf("%s=", envp->tab[0]);
			printf("%s\n", envp->tab[1]);
		}
		else if (ft_strcmp(envp->tab[0], "="))
			printf("%s=", envp->tab[0]);
		envp = envp->next;
	}
	return (0);
}
