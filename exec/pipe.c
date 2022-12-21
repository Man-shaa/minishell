/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:38:01 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 16:09:38 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_pipes(t_data *data)
{
	int		i;
	t_proc	*proc;

	proc = data->proc;
	i = 0;
	proc->n_pipes = pipe_count(data->cmd) - 1;
	if (proc->n_pipes <= 0)
	{
		proc->n_pipes = 0;
		return (1);
	}
	proc->pipe_fd = ft_calloc(2 * proc->n_pipes, sizeof(int));
	if (!proc->pipe_fd)
		return (0);
	while (i < proc->n_pipes)
	{
		if (pipe(proc->pipe_fd + 2 * i) < 0)
			return (err_msg("Pipe failed", NULL, NULL, 0));
		i++;
	}
	return (1);
}

void	close_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	close(proc->fd_in);
	close(proc->fd_out);
	while (i < proc->n_pipes)
	{
		close(proc->pipe_fd[i]);
		i++;
	}
}

