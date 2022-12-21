/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:39:51 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 16:19:19 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// open et dup2 a l'interieur de chaque pipe si il y a des redirections < > >>
// Return 1 si tout s'est bien passe, sinon 0
int	handle_redir(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return 0;
	while (cmd->token[i])
	{
		if (!open_fd(data->proc, cmd->token[i], cmd->type[i]))
			return (0);
		i++;
	}
	return (1);
}

int	open_fd(t_proc *proc, char *token, int type)
{
	if (type == 2)
	{
		proc->fd_in = open(token, O_RDONLY, 0644);
		if (proc->fd_in < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 1));
		dup2(proc->fd_in, STDIN_FILENO);
		close(proc->fd_in);
	}
	else if (type == 3)
	{
		proc->fd_out = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 2));
		dup2(proc->fd_out, STDOUT_FILENO);
		close(proc->fd_in);
	}
	else if (type == 5)
	{
		proc->fd_out = open(token, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 2));
		dup2(proc->fd_out, STDOUT_FILENO);
		close(proc->fd_in);
	}
	return (1);
}

void	double_dup2(int fd1, int fd2)
{
	dup2(fd1, STDIN_FILENO);
	// close(fd1);
	dup2(fd2, STDOUT_FILENO);
	// close(fd2);
}

void	redirect_pipe(t_proc *proc)
{
	int	pipe_index;

	pipe_index = 0;
	while (pipe_index < proc->n_pipes)
	{
		if (pipe_index == 0)
			double_dup2(proc->pipe_fd[0], proc->pipe_fd[1]);
		else if (pipe_index == proc->n_pipes - 1)
			double_dup2(proc->pipe_fd[2 * pipe_index - 2], proc->pipe_fd[2 * pipe_index - 1]);
		else
			double_dup2(proc->pipe_fd[2 * pipe_index - 2], proc->pipe_fd[2 * pipe_index + 1]);
		pipe_index++;
		close_pipes(proc);
	}
}
