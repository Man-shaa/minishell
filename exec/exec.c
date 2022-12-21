/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 18:28:50 by msharifi         ###   ########.fr       */
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
	data->proc->pid = fork();
	if (data->proc->pid == 0)
	{
		if (!handle_redir(data, cmd))
			return (1);
		env_tab = get_env_tab(data->envp);
		execve(cmd->cmd_path, cmd->opt, env_tab);
		return (error_cmd(cmd->opt));
	}
	waitpid(data->proc->pid, &status, 0);
	return (WEXITSTATUS(status));
}

// Cree les pipes et s'occupe des redirections avant d'envoyer la commande
// a send_cmd
// Return 0 si il y a un probleme a la creation des pipes, sinon 0
int	execution(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	if (!create_pipes(data))
		return (0);
	redirect_pipe(data->proc);
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
