/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/09 20:27:21 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// Y a des problemes avec wait quand il y a des builtins

// echo sd$psdg$PWD affiche pas le PWD

// Gerer le leak de history (le sujet ne dit pas que c'est ok d'en avoir)

// retour de fork (status) impossible a recupere comme c'est actuellement

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul

// here_doc Pioritaire quelque soit sa position dans readline ??

// wc -l >>out ne gere pas standard input (stdin) | cat >>out Pareil
// "> out" pete un cable

// "<in ..." alors que in n'existe pas casse tout 

// Manuo ✖✖ history fait tout crash

// ------ Mat	 ------

// echo '$PWD' qui devrait afficher $PWD (lire sujet a propos des quotes)

// Return 0 si str est une commande return 1 si str est un builtin -- inverse ?
// Manuo ✖✖ <izeixn wc -l >>> out

// "Doublons of redirections" leaks

// Pourquoi est ce que cat Makefile | wc return une erreur

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}
