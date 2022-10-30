/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/26 18:50:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)
// faut il faire qq chose de particulier pour ecrire le contienu d'un fichier
// (echo [nom_du_fichier]) ou c'es gerer tout seul par l'execve ? 

#include "../includes/minishell.h"

void	echo(char *str)
{
	ft_putstr(str);
}
