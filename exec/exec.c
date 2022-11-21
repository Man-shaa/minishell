/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 13:43:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_binary(t_data *data)
{
	(void)data;
	return (1);
}

int	send_cmd(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	if (cmd->cmd && is_builtin(cmd->cmd))
		data->return_val = exec_builtin(data, cmd->cmd, cmd->opt); // Return_val a MAJ
	else if (cmd->cmd)
		data->return_val = exec_binary(data); // Return_val a MAJ
	return (1);
}
