/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:38:01 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/20 14:04:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cree tous les pipes neccessaire a l'execution de la ligne de commande
// Return 1 si la creation a fonctionne, sinon 0
int	create_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < proc->n_pipes)
	{
		if (pipe(proc->pipe_fd[i]) < 0)
			return (err_msg("Pipe failed", NULL, NULL, 0));
		i++;
	}
	return (1);
}

// Cree le nombre de pipe necessaire
// Return 1 si tout s'est bien passe, sinon 0 (malloc rate)
int	create_pipes_array(t_data *data)
{
	int		i;
	t_proc	*proc;

	proc = data->proc;
	i = 0;
	proc->n_pipes = pipe_count(data->cmd);
	if (proc->n_pipes <= 0)
	{
		proc->n_pipes = 0;
		return (1);
	}
	proc->pipe_fd = ft_calloc(proc->n_pipes + 1, sizeof(int *));
	if (!proc->pipe_fd)
		return (0);
	while (i < proc->n_pipes)
	{
		proc->pipe_fd[i] = ft_calloc(2, sizeof(int));
		if (!proc->pipe_fd[i])
			return (free_int_tab(proc->pipe_fd, i), 0);
		i++;
	}
	proc->pipe_fd[i] = 0;
	if (!create_pipes(proc))
		return (free_int_tab(proc->pipe_fd, proc->n_pipes), 0);
	return (1);
}

// Close tous les pipes
void	close_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < proc->n_pipes)
	{
		close(proc->pipe_fd[i][0]);
		close(proc->pipe_fd[i][1]);
		i++;
	}
}
