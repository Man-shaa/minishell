/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/20 18:55:37 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sighere(int sig_segv)
{
	(void)sig_segv;
	printf("\n");
	g_return_val = -42;
	close(0);
}

void	handle_sigsegvhere(int sig_segv)
{
	(void)sig_segv;
	printf("\n");	
	g_return_val = -43;
	close(0);
}

void	handle_heredoc(void)
{
	signal(SIGINT, handle_sighere);
	signal(SIGSEGV, handle_sigsegvhere);
}

void	handle_sigint_exec(void)
{
	signal(SIGINT, handle_exec);
}

void	handle_exec(int sig_int)
{
	(void)sig_int;
	g_return_val = 130;
	ft_putstr("\n");
}
