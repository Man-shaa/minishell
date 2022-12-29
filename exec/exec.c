/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/29 15:32:21 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	if (data->proc->n_pipes > 0) // 3 pro lignes etaient a redir, apres token
		if (!handle_pipe_redir(cmd, data->proc))
			return (1);
	data->proc->pid = fork();
	if (data->proc->pid == 0)
	{
		// printf("Avant redir, cmd->index = %d\n", cmd->index);
		if (!redir(data, cmd))
			return (close_pipes(data->proc), 1);
		// printf("Apres redir\n");
		close_pipes(data->proc);
		env_tab = get_env_tab(data->envp);
		execve(cmd->cmd_path, cmd->opt, env_tab);
		return (error_cmd(cmd->opt));
	}
	waitpid(data->proc->pid, &status, 0);
	close_pipes(data->proc);
	return (WEXITSTATUS(status));
}

// Cree les pipes et s'occupe des redirections avant d'envoyer la commande
// a send_cmd
// Return 0 si il y a un probleme a la creation des pipes, sinon 0
int	execution(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	if (!create_pipes_array(data))
		return (0);
	while (cmd)
	{
		data->return_val = send_cmd(data, cmd);
		cmd = cmd->next;
	}
	return (1);
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
	return (1);
}
