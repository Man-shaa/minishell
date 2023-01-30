/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/30 13:36:41 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_return_val;

#include "includes/minishell.h"

// here_doc Pioritaire quelque soit sa position dans readline ??

// "> out" fait plus rien

// Manuo ✖✖ <izeixn wc -l >>> out ????

// minishell: unexpected token or redirection invalid free seulement
// quand une premiere commande a ete effectuee auparavant (free_proc)

// CTRL-C dans un heredoc fonctionne pas (handle-signal() ?)

// unset PATH -> ls fonctionne quand meme sans 

int	main(int ac, char **av, char **envp)
{
	(void)av;
	g_return_val = 0;
	if (ac != 1)
		return (err_msg("Tuto : ./minishell", NULL, NULL, 1));
	handle_signal();
	get_prompt(envp);
	return (0);
}
