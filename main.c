/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/20 16:17:32 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// Gerer le leak de history (le sujet ne dit pas que c'est ok d'en avoir)

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul
// here_doc Pioritaire quelque soit sa position dans readline ??

// wc -l >>out ne gere pas standard input (stdin) | cat >>out Pareil
// "> out" pete un cable
// ------ Mateo ------

// Return 0 si str est une commande return 1 si str est un builtin -- inverse ?
// Manuo ✖✖ <in wc -l >>> out

// Doublons of redirections leaks de fou a regler (Mateo)

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}
