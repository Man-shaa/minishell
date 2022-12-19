/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 13:05:15 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul
// ".." pete un cable
// echo "$" ou plusieurs "$" ne les affiche pas (ignore_charset)

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	// (void)envp;
	// int	fd;
	// fd = open("test", O_RDWR);
	// if (fd != -1)
	// 	close(fd);
	handle_signal();
	get_prompt(envp);
	return (0);
}
