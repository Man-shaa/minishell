/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/20 20:26:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	g_return_val;

// cat | euf 93w874w - ctrl c, echo $? verif bash

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
