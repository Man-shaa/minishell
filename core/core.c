/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/05 18:31:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	reset_data(t_data *data)
{
	if (data->list)
	{
		free_list(data->list);
		data->list = NULL;
	}
	if (data->cmd)
	{
		free_cmd(data->cmd);
		data->cmd = NULL;
	}
}

void	get_prompt(char **envp)
{
	char	*str;
	t_cmd	*cmd;
	t_data	*data;

	data = create_data(envp);
	while (42)
	{
		str = readline("Manuo ✖✖ ");
		if (!data)
			return ;
		ft_split(str, data);
		get_cmd_struct(data);
		if (!parsing(data))
			return ;
		cmd = data->cmd;
		while (cmd)
		{
			send_cmd(data, cmd);
			cmd = cmd->next;
		}
		ft_free(str);
		reset_data(data);
	}
	free_data(data);
}
