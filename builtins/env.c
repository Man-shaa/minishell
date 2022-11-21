/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 11:37:51 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
