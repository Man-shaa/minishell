/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/14 15:00:10 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Execute les commandes (non builtins)
// Ne return rien si l'execution a reussie ou la valeur d'erreur
int	exec_binary(t_data *data, t_cmd *cmd)
{
	char	**env_tab;

	if (!data->env_path)
	{
		err_msg("env not found, specify an absolute path", NULL, NULL, 2);
		return (1);
	}
	if (!cmd->cmd_path)
		return (1);
	data->proc->pid = fork();
	if (data->proc->pid == 0)
	{
		env_tab = get_env_tab(data->envp);
		// print_tab(cmd->opt);
		if (execve(cmd->cmd_path, cmd->opt, env_tab) == -1)
			return (err_msg("execve failed !", NULL, NULL, 2), 2);
	}
	waitpid(-1, NULL, 0);
	return (0);
}

int	error_cmd(char **cmd)
{
	int	fd;

	if (cmd && cmd[0])
	{
		fd = open(cmd[0], __O_DIRECTORY);
		if (fd >= 0)
		{
			close(fd);
			err_msg("minishell: : ", cmd[0], " is a directory", 2);
			return (126);
		}
		// close(fd);
	}
	err_msg("minishell: command not found: ", cmd[0], NULL, 2);
	return (127);
}

// Envoies la commande a la fonction de builtins ou d'exec bin
// Return le retour de chaque commande effectuee
int	send_cmd(t_data *data, t_cmd *cmd)
{
	if (!cmd->cmd)
		return (error_cmd(cmd->opt));
	else if (is_builtin(cmd->cmd))
		return (exec_builtin(data, cmd->cmd, cmd->opt));
	else if (is_cmd(data, cmd->cmd, data->env_path))
		return (exec_binary(data, cmd)); // valeur retour a set
	return (1);
}
