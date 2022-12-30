/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/30 21:52:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// Y a des problemes avec wait quand il y a des builtins

// Gerer le leak de history (le sujet ne dit pas que c'est ok d'en avoir)

// retour de fork (status) impossible a recupere comme c'est actuellement

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul

// here_doc Pioritaire quelque soit sa position dans readline ??

// wc -l >>out ne gere pas standard input (stdin) | cat >>out Pareil
// "> out" pete un cable

// "<in ..." alors que in n'existe pas casse tout 

// ------ Mateo ------

// Juste [return] met un message a voir si on enleve

// echo '$PWD' qui devrait afficher $PWD (lire sujet a propos des quotes)

// "ls | cat" renvoies missing a command -> changer un is_builtin pour is_cmd
// qq part  dans le parsing

// Return 0 si str est une commande return 1 si str est un builtin -- inverse ?
// Manuo ✖✖ <in wc -l >>> out

// <in cat main.c | > out wc doublons of redirections alors que c'est bon

// "Doublons of redirections" leaks

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}
