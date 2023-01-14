/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/14 19:42:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	close_pipes(data->proc);
	wait_all_child(data->proc, data->proc->n_pipes + 1);
	handle_signal();
	return (1);
}

void	wait_all_child(t_proc *proc, int n)
{
	int	i;

	i = 0;
	if (!proc->pid)
		return ;
	while (i < n)
	{
		waitpid(proc->pid[i], NULL, 0);
		i++;
	}
}

// Execute les commandes (non builtins)
// Ne return rien si l'execution a reussie ou la valeur d'erreur
int	exec_binary(t_data *data, t_cmd *cmd)
{
	char	**env_tab;

	if (!cmd->cmd_path)
	{
		err_msg("env not found, specify an absolute path", NULL, NULL, 1);
		return (1);
	}
	data->proc->pid[cmd->index] = fork();
	if (data->proc->pid[cmd->index] == 0)
	{
		if (!redir(data, cmd))
			return (close_pipes(data->proc), 1);
		env_tab = get_env_tab(data->envp);
		printf("exec here\n\n");
		execve(cmd->cmd_path, cmd->opt, env_tab);
		return (free_tab(env_tab), error_cmd(cmd->opt));
	}
	return (1);
}

// Envoies la commande a la fonction de builtins ou d'exec bin
// Return le retour de chaque commande effectuee
int	send_cmd(t_data *data, t_cmd *cmd)
{
	signal(SIGQUIT, handle_sigquit);
	if (!cmd->cmd || !cmd->cmd[0] || is_same(cmd->cmd, "..") || is_same(cmd->cmd, "."))
		return (error_cmd(cmd->opt));
	else if (is_builtin(cmd->cmd))
		return (exec_builtin(data, cmd->cmd, cmd->opt));
	else if (is_cmd(data, cmd->cmd, data->env_path))
		return (exec_binary(data, cmd));
	return (1);
}
