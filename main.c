/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/20 13:05:59 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_return_val;

// export "ls -l"

// env | env |

// export a=

// ls<<eof CTRL-C dans heredoc devrait pas faire le ls, (signaux hredoc)

// >double ls < dsfghj | cat infile existe pas, cat devrait pas s'executer

// exit a55 45

// . et .. pas le meme retour d'erreur

// Retour CRTL-C CRTL-D 

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
