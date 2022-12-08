/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/08 17:41:25 by mfroissa         ###   ########.fr       */
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
		if (!data->return_val)
			str = readline("Manuo ✖✖ ");
		else
			str = readline("✖ Manuo ✖ ");
		if (!data)
			return ;
		ft_split(str, data);
		get_cmd_struct(data);
		if (!parsing(data))
			return ;
		cmd = data->cmd;
		while (cmd)
		{
			data->return_val = send_cmd(data, cmd);
			// printf("Retour : %i\n", data->return_val);
			cmd = cmd->next;
		}
		ft_free(str);
		reset_data(data);
	}
	free_data(data);
}
