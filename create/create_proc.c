/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:06:50 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/30 21:10:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cree et et initialise a 0 la structure t_proc
t_proc	*create_proc(void)
{
	t_proc	*proc;

	proc = ft_calloc(1, sizeof(t_proc));
	if (!proc)
		return (NULL);
	proc->n_pipes = 0;
	proc->pipe_fd = NULL;
	proc->fd_in = STDIN_FILENO;
	proc->fd_out = STDOUT_FILENO;
	proc->pid = NULL;
	return (proc);
}
