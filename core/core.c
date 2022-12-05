/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/05 15:40:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(char **envp)
{
	char	*str;
	int		exit_status;
	t_cmd	*cmd;
	t_data	*data;

	while (42)
	{
		data = create_data(envp);
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
		exit_status = data->return_val;
		free_data(data);
	}
}
