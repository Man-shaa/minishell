/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 14:22:49 by msharifi         ###   ########.fr       */
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
		err_msg("env not found, specify an absolute path", NULL, NULL);
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
		if (execve(cmd->cmd_path, cmd->opt, env_tab) == -1)
			return (err_msg("execve failed !", NULL, NULL), 1);
	}
	waitpid(data->proc->pid, NULL, 0);
	return (0);
}

int	error_cmd(char **cmd)
{
	int	fd;
	DIR	*dir;

	if (!cmd && cmd[0])
		return (err_msg("minishell: ", cmd[0], "command not found: "), 127);
	fd = open(cmd[0], O_WRONLY);
	dir = opendir(cmd[0]);
	if (ft_strchr(cmd[0], '/'))
		err_msg("minishell: ", cmd[0], ": command not found");
	else if (fd == -1 && dir == NULL)
		err_msg("minishell: ", cmd[0], ": No such file or directory");
	else if (fd == -1 && dir != NULL)
		err_msg("minishell: ", cmd[0], ": is a directory");
	else if (fd != -1 && dir == NULL)
		err_msg("minishell: ", cmd[0], ": Permission denied");
	if (fd > 0)
		close(fd);
	if (dir)
		closedir(dir);
	return (126);
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
	return (1);
}
