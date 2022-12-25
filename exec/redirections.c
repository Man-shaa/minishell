/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:39:51 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/25 21:45:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// RAJOUTER SECURITE DUP2 ET PRENDRE EN COMPTTE VALEUR DE RETOUR hande_redir()
int	handle_pipe_redir(t_cmd *cmd, t_proc *proc)
{
	if (cmd->index == 0)
	{
		// dup2(proc->fd_in, STDIN_FILENO);
		dup2(proc->pipe_fd[1], STDOUT_FILENO);
	}
	else if (cmd->index == proc->n_pipes)
	{
		dup2(proc->pipe_fd[2 * cmd->index - 2], STDIN_FILENO);
		printf("pipe[%d] : %d\n", 2 * cmd->index - 2, proc->pipe_fd[2 * cmd->index - 2]);
		// dup2(proc->fd_out, STDOUT_FILENO);
	}
	else
	{
		dup2(proc->pipe_fd[2 * cmd->index - 2], STDIN_FILENO);
		dup2(proc->pipe_fd[2 * cmd->index + 1], STDOUT_FILENO);
	}
	close_pipes(proc);
	return (1);
}

// open et dup2 a l'interieur de chaque pipe si il y a des redirections < > >>
// Return 1 si tout s'est bien passe, sinon 0
int	redir(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return (1);
	if (data->proc->n_pipes > 0)
		if (!handle_pipe_redir(cmd, data->proc))
			return (0);
	while (cmd->token[i])
	{
		if (!handle_token_redir(data->proc, cmd->token[i], cmd->type[i]))
			return (0);
		i++;
	}
	return (1);
}
// if (data->cmd_count == 0)
// 			double_dup2(data->fd_infile, data->pipe[1]);
// 		else if (data->cmd_count == data->cmd_nb - 1)
// 			double_dup2(data->pipe[2 * data->cmd_count - 2], data->fd_outfile);
// 		else
// 			double_dup2(data->pipe[2 * data->cmd_count - 2],
// 				data->pipe[2 * data->cmd_count + 1]);
// 		close_pipes(data);

// Open le token et dup2 fd_in/out en fonction du type < > >>
// Return 1 si tout s'est bie passe, sinon 0
int	handle_token_redir(t_proc *proc, char *token, int type)
{
	if (type == IN)
	{
		proc->fd_in = open(token, O_RDONLY, 0644);
		if (proc->fd_in < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		dup2(proc->fd_in, STDIN_FILENO);
		close(proc->fd_in);
	}
	else if (type == OUT)
	{
		proc->fd_out = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		dup2(proc->fd_out, STDOUT_FILENO);
		close(proc->fd_out);
	}
	else if (type == APPEND)
	{
		proc->fd_out = open(token, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		dup2(proc->fd_out, STDOUT_FILENO);
		close(proc->fd_out);
	}
	return (1);
}

// Utile ??
void	double_dup2(int fd1, int fd2)
{
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}
