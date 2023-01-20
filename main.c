/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/20 13:57:01 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// here_doc Pioritaire quelque soit sa position dans readline ??

// "> out" fait plus rien

// Manuo ✖✖ <izeixn wc -l >>> out ????

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (ac != 1)
		return (err_msg("Tuto : ./minishell", NULL, NULL, 1));
	handle_signal();
	get_prompt(envp);
	return (0);
}
