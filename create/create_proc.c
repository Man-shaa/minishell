/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:06:50 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 15:49:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	proc->pid = -1;
	return (proc);
}
