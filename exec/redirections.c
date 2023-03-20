/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:39:51 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/20 13:58:05 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// dup2 l'entree et sortie des pipes avec STDIN/OUT_FILENO
// Return 1 si tout s'est bien passe, sinon 0
int	handle_pipe_redir(t_data *data, t_cmd *cmd, t_proc *proc)
{
	if (cmd->index == 0)
	{
		if (!is_token(cmd, OUT))
			if (dup2(proc->pipe_fd[0][1], STDOUT_FILENO) == -1)
				return (err_msg("dup2 first pipe failed", NULL, NULL, 0));
	}
	else if (cmd->index == proc->n_pipes)
	{
		if (!is_token(cmd, IN) && !is_last_cmd_token_out(data, cmd->index) //a voir !
			&& !is_token(cmd, HERE))
			if (dup2(proc->pipe_fd[cmd->index - 1][0], STDIN_FILENO) == -1)
				return (err_msg("dup2 last pipe failed", NULL, NULL, 0));
	}
	else
	{
		if (!is_token(cmd, IN) && !is_token(cmd, HERE))
			if (dup2(proc->pipe_fd[cmd->index - 1][0], STDIN_FILENO) == -1)
				return (err_msg("dup2 pipe failed", NULL, NULL, 0));
		if (!is_token(cmd, OUT))
			if (dup2(proc->pipe_fd[cmd->index][1], STDOUT_FILENO) == -1)
				return (err_msg("dup2 pipe failed", NULL, NULL, 0));
	}
	close_pipes(proc);
	return (1);
}

int	handle_token_redir3(int cmd_pos)
{
	int		fd;
	char	*filename;
	char	*cmd_number;

	cmd_number = ft_itoa(cmd_pos);
	filename = ft_strjoin("/tmp/.heredoc_manuo", cmd_number);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	ft_free(cmd_number);
	ft_free(filename);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (err_msg("Dup2 heredoc failed", 0, NULL, 0), 0);
	close(fd);
	return (1);
}

int	handle_token_redir2(t_data *data, t_cmd *cmd, int cmd_pos, int m)
{
	if (cmd->type[cmd_pos] == APPEND)
	{
		data->proc->fd_out = open(cmd->token[cmd_pos],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (data->proc->fd_out < 0)
			return (err_msg("minishell: ", cmd->token[cmd_pos],
					": No such file or directory", 0));
		if (m == 1)
		{
			if (dup2(data->proc->fd_out, STDOUT_FILENO) == -1)
				return (close(data->proc->fd_out), 1);
		}
		close(data->proc->fd_out);
	}
	else if (data->proc->n_heredoc && is_last_heredoc(data, cmd, cmd_pos))
		return (handle_token_redir3(which_heredoc(data, cmd, cmd_pos)));
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
			return (err_msg("minishell: ", cmd->token[cmd_pos],
					": No such file or directory", 0));
		if (m == 1)
			if (dup2(data->proc->fd_in, STDIN_FILENO) == -1)
				return (close(data->proc->fd_in), 1);
		close(data->proc->fd_in);
	}
	else if (cmd->type[cmd_pos] == OUT)
	{
		data->proc->fd_out = open(cmd->token[cmd_pos],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->proc->fd_out < 0)
			return (err_msg("minishell: ", cmd->token[cmd_pos],
					": No such file or directory", 0));
		if (m == 1)
			if (dup2(data->proc->fd_out, STDOUT_FILENO) == -1)
				return (close(data->proc->fd_out), 1);
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
	while (cmd->token && cmd->token[i])
	{
		if (!handle_token_redir(data, cmd, i, m))
			return (1);
		i++;
	}
	if (data->proc->n_pipes > 0)
		if (!handle_pipe_redir(data, cmd, data->proc))
			return (err_msg("Dup2 failed", NULL, NULL, 1));
	return (0);
}
