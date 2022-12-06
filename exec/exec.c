/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/06 21:16:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_binary(t_data *data, t_cmd *cmd)
{
	(void)cmd;
	if (!data->env_path)
	{
		err_msg("env not found, specify an absolute path\n", NULL, NULL, 2);
		return (0);
	}
	if (cmd->cmd_path)
		execve(cmd->cmd_path, cmd->opt, data->envp->tab);
	return (1);
}

int	send_cmd(t_data *data, t_cmd *cmd)
{
	if (!cmd->cmd)
		return (err_msg("minishell: command not found: ", cmd->opt[0], "\n", 2), 1);
	if (is_builtin(cmd->cmd))
		data->return_val = exec_builtin(data, cmd->cmd, cmd->opt);
	else if (is_cmd(data, cmd->cmd, data->env_path))
		data->return_val = exec_binary(data, cmd); // valeur retour a set
	return (1);
}
