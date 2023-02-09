/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:39:51 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/09 18:29:01 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Compare type et chaque cmd->type en parcourant cmd->token
// Return 1 si cmd->type == type, sinon 0
int	is_token(t_cmd *cmd, int type)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return (0);
	while (cmd->token[i])
	{
		if (cmd->type[i] == type)
			return (1);
		i++;
	}
	return (0);
}

// dup2 l'entree et sortie des pipes avec STDIN/OUT_FILENO
// Return 1 si tout s'est bien passe, sinon 0
int	handle_pipe_redir(t_cmd *cmd, t_proc *proc)
{
	if (cmd->index == 0)
	{
		if (!is_token(cmd, OUT))
			if (dup2(proc->pipe_fd[0][1], STDOUT_FILENO) == -1)
				return (0);
	}
	else if (cmd->index == proc->n_pipes)
	{
		if (!is_token(cmd, IN) && !is_token(cmd, HERE))
			if (dup2(proc->pipe_fd[cmd->index - 1][0], STDIN_FILENO) == -1)
				return (0);
	}
	else
	{
		if (!is_token(cmd, IN) && !is_token(cmd, HERE))
			if (dup2(proc->pipe_fd[cmd->index - 1][0], STDIN_FILENO) == -1)
				return (0);
		if (!is_token(cmd, OUT))
			if (dup2(proc->pipe_fd[cmd->index][1], STDOUT_FILENO) == -1)
				return (0);
	}
	close_pipes(proc);
	return (1);
}

int	handle_token_redir2(t_data *data, t_cmd *cmd, int cmd_pos, int m)
{
	if (cmd->type[cmd_pos] == APPEND)
	{
		data->proc->fd_out = open(cmd->token[cmd_pos],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		if (m == 1)
		{
			if (dup2(data->proc->fd_out, STDOUT_FILENO) == -1)
				return (close(data->proc->fd_out), 1);
			close(data->proc->fd_out);
		}
		else
			close(data->proc->fd_out);
	}
	else if (cmd->type[cmd_pos] == HERE)
		if (!create_heredoc(data, cmd, data->proc->fd_in, cmd_pos))
			return (handle_signal(), 0);
	return (1);
}

// Open le token et dup2 fd_in/out en fonction du type < > >>
// Return 0 si tout s'est bien passe, sinon 1
int	handle_token_redir(t_data *data, t_cmd *cmd, int cmd_pos, int m)
{
	if (cmd->type[cmd_pos] == IN)
	{
		data->proc->fd_in = open(cmd->token[cmd_pos], O_RDONLY, 0644);
		if (data->proc->fd_in < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		if (m == 1)
		{
			if (dup2(data->proc->fd_in, STDIN_FILENO) == -1)
				return (close(data->proc->fd_in), 1);
			close(data->proc->fd_in);
		}
		close(data->proc->fd_out);
	}
	else if (cmd->type[cmd_pos] == OUT)
	{
		data->proc->fd_out = open(cmd->token[cmd_pos],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->proc->fd_out < 0)
			return (err_msg("open: No such file or directory", NULL, NULL, 0));
		if (m == 1)
		{
			if (dup2(data->proc->fd_out, STDOUT_FILENO) == -1)
				return (close(data->proc->fd_out), 1);
			close(data->proc->fd_out);
		}
		close(data->proc->fd_out);
	}
	return (handle_token_redir2(data, cmd, cmd_pos, m));
}

// S'occupe des redirections pipe et < > >>
// Return 0 si tout s'est bien passe, sinon 1
// Si [m] == 1, dup2
int	redir(t_data *data, t_cmd *cmd, int m)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return (0);
	while (cmd->token[i])
	{
		if (!handle_token_redir(data, cmd, i, m))
			return (1);
		i++;
	}
	if (data->proc->n_pipes > 0)
		if (!handle_pipe_redir(cmd, data->proc))
			return (err_msg("Dup2 failed", NULL, NULL, 1));
	return (0);
}
