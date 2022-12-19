/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 15:32:12 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Execute les commandes (non builtins)
// Ne return rien si l'execution a reussie ou la valeur d'erreur
int	exec_binary(t_data *data, t_cmd *cmd)
{
	char	**env_tab;
	int		status;

	if (!data->env_path)
	{
		err_msg("env not found, specify an absolute path", NULL, NULL, 1);
		return (1);
	}
	if (!cmd->cmd_path)
		return (1);
	data->proc->pid = fork();
	if (data->proc->pid == 0)
	{
		env_tab = get_env_tab(data->envp);
		if (!env_tab)
			return (1);
		// print_tab(env_tab);
		execve(cmd->cmd_path, cmd->opt, env_tab);
		return (error_cmd(cmd->opt));
	}
	waitpid(data->proc->pid, &status, 0);
	return (WEXITSTATUS(status));
}

// Envoies la commande a la fonction de builtins ou d'exec bin
// Return le retour de chaque commande effectuee
int	send_cmd(t_data *data, t_cmd *cmd)
{
	if (!cmd->cmd || is_same(cmd->cmd, ".."))
		return (error_cmd(cmd->opt));
	else if (is_builtin(cmd->cmd))
		return (exec_builtin(data, cmd->cmd, cmd->opt));
	else if (is_cmd(data, cmd->cmd, data->env_path))
		return (exec_binary(data, cmd));
	return (0);
}
