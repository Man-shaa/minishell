/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:37:46 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/17 18:39:01 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
