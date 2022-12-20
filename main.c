/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/20 14:24:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// Gerer le leak de history (le sujet ne dit pas que c'est ok d'en avoir)

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul
// here_doc Pioritaire quelque soit sa position dans readline ??

// Return 0 si str est une commande return 1 si str est un builtin -- inverse ?

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}
