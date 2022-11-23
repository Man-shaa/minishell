/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/23 17:14:42 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_binary(t_data *data, t_cmd *cmd)
{
	(void)cmd;
	if (!data->path_env)
	{
		err_msg("env not found, specify a absolute path", NULL, NULL, 2);
		return (0);
	}
	if (!find_cmd_path(data, cmd))
		return (0);
	data->proc->pid = fork();
	if (data->proc->pid < 0)
		return (err_msg("minishell: Fork failed", NULL, NULL, 2), 0);
	if (data->proc->pid == 0)
	{
		
	}
	return (1);
}

int	send_cmd(t_data *data, t_cmd *cmd)
{
	if (cmd->cmd && is_builtin(cmd->cmd))
		data->return_val = exec_builtin(data, cmd->cmd, cmd->opt);
	else if (cmd->opt && cmd->opt[0])
		data->return_val = exec_binary(data, cmd); // valeur retour a MAJ
	return (1);
}
