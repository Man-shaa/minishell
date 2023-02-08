/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/08 16:13:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_return_val;

// Plusieurs here_doc dans 2 pipe separes

// valeur de retour de CTRL-\ pas bon (0 au lieu de 131)
// valeur de retour de CTRL-C pas bon (0 au lieu de 130)

// echo "$9HOME" OU "echo $:$=" essaye d'expand alors qu'il faut pas

// "|" conditional jump

// "export Hola=bonjour" PUIS "export Hola" Hola doit plus avoir "bonjour" :(
// qq part dans replace_value je pense

// CRASH ">echo>" 

int	main(int ac, char **av, char **envp)
{
	(void)av;
	g_return_val = 0;
	if (ac != 1)
		return (err_msg("Tuto (derien) : ./minishell", NULL, NULL, 1));
	handle_signal();
	get_prompt(envp);
	return (0);
}
