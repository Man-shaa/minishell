/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:34:48 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/08 16:18:21 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigquit(int sig_quit)
{
	(void)sig_quit;
	ft_putstr("Quit (core dumped)\n");
}

void	handle_sigsegv(int sig_segv)
{
	(void)sig_segv;
	err_msg(NULL, "exit", NULL, 1);
	exit(1);
}

void	handle_sigint(int sig_int)
{
	(void)sig_int;
	g_return_val = 130;
	ft_putstr("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_sighere(int sig_int)
{
	(void)sig_int;
	printf("\n");
	g_return_val = -42;
	close(0);
}

//	gere les signaux ctrl-\(SIGQUIT) & ctrl-C(SIGINT)
void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGSEGV, handle_sigsegv);
	signal(SIGINT, handle_sigint);
}
