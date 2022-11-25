/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/25 18:12:37 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(t_data *data, char **envp)
{
	char	*str;
	int		exit_status;
	t_cmd	*cmd;

	while (42)
	{
		str = readline("Manuo ✖✖ ");
		data = create_data(envp);
		if (!data)
			return ;
		ft_split(str, data);
		get_cmd_struct(data);
		cmd = data->cmd;
		while (cmd)
		{
			send_cmd(data, cmd);
			cmd = cmd->next;
		}
		free(str);
		exit_status = data->return_val;
		free_data(data);
	}
}
