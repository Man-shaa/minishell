/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/20 15:05:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_redir(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return 0;
	while (cmd->token[i])
	{
		if (cmd->type[i] == 2)
		{
			data->proc->fd_in = open(cmd->token[i], O_RDONLY, 0644);
			if (data->proc->fd_in < 0)
				return (err_msg("open: No suche file or directory fd", NULL,
					NULL, 1));
			dup2(data->proc->fd_in, STDIN_FILENO);
			close(data->proc->fd_in);
		}
		else if (cmd->type[i] == 3)
		{
			data->proc->fd_out = open(cmd->token[i], O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
			if (data->proc->fd_out < 0)
				return (err_msg("open: No suche file or directory fd", NULL,
					NULL, 2));
			dup2(data->proc->fd_out, STDOUT_FILENO);
			close(data->proc->fd_out);
		}
		i++;
	}
	// print_tab(cmd->token);
	// print_int_tab(data, cmd->type);
	return (0);
}

// Execute les commandes (non builtins)
// Ne return rien si l'execution a reussie ou la valeur d'erreur
int	exec_binary(t_data *data, t_cmd *cmd)
{
	char	**env_tab;
	int		status;

	if (!cmd->cmd_path)
	{
		err_msg("env not found, specify an absolute path", NULL, NULL, 1);
		return (1);
	}
	handle_redir(data, cmd);
	data->proc->pid = fork();
	if (data->proc->pid == 0)
	{
		env_tab = get_env_tab(data->envp);
		// print_tab(env_tab);
		execve(cmd->cmd_path, cmd->opt, NULL);
		return (error_cmd(cmd->opt));
	}
	waitpid(data->proc->pid, &status, 0);
	if (data->proc->fd_out)
		dup2(STDOUT_FILENO, data->proc->fd_out);
	return (WEXITSTATUS(status));
}

// Envoies la commande a la fonction de builtins ou d'exec bin
// Return le retour de chaque commande effectuee
int	send_cmd(t_data *data, t_cmd *cmd)
{
	if (!cmd->cmd || is_same(cmd->cmd, "..") || is_same(cmd->cmd, "."))
		return (error_cmd(cmd->opt));
	else if (is_builtin(cmd->cmd))
		return (exec_builtin(data, cmd->cmd, cmd->opt));
	else if (is_cmd(data, cmd->cmd, data->env_path))
		return (exec_binary(data, cmd));
	return (0);
}
