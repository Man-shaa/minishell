/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/03 16:44:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)
// faut il faire qq chose de particulier pour ecrire le contienu d'un fichier
// (echo [nom_du_fichier]) ou c'es gerer tout seul par l'execve ? 

#include "../includes/minishell.h"

void	echo(t_data *data, char *str)
{
	t_envp	*node;
	char	*res;

	node = data->envp;
	if (ft_strchr(str, '$'))
		ft_putstr(str);
	else
	{
		res = ignore_charset(str, "$(){}");
		node = search_node(data->envp, res);
		ft_free(res);
		ft_putstr(node->tab[1]);
	}
	write(1, "\n", 1);
}
