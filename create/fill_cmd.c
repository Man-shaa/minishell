/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:03:31 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/14 14:53:41 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*fill_cmd_struct(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	if (tmp->type == 1)
	{
		if (is_cmd(data, tmp->str, data->env_path) && cmd->cmd == NULL)
			handle_cmd(data, cmd, tmp, j);
		else
		{
			cmd->opt[(*j)] = tmp->str;
			(*j)++;
		}
		tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}

t_list	*fill_cmd_tokens(t_cmd *cmd, t_list *tmp, int *k)
{
	if (tmp && tmp->type != 1 && tmp->type != 6)
	{
		cmd->type[(*k)] = tmp->type;
		tmp = tmp->next;
		cmd->token[(*k)] = tmp->str;
		(*k)++;
		tmp = tmp->next;
	}
	return (tmp);
}

void	handle_cmd(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	cmd->cmd = tmp->str;
	if (!is_builtin(tmp->str))
	{
		cmd->opt[(*j)] = tmp->str;
		(*j)++;
		find_cmd_path(data, cmd, data->env_path);
	}
}
