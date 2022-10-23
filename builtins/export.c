/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansha <mansha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:02:43 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/23 19:51:35 by mansha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Print l'environnement de export de la struct t_envp
void	print_export(t_envp *envp)
{
	while (envp)
	{
		printf("declare -x %s=", envp->tab[0]);
		printf("\"%s\"\n", envp->tab[1]);
		envp = envp->next;
	}
}
