/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/13 17:57:59 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul
// echo "skdf$PWDsfd jkhsd"
// echo "$PWD$OLDPWD"
// echo "skjdh$? sdg"

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}
