/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:03:31 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/18 20:10:15 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Remplit la structure t_cmd avec les commandes et options recues
// Return un pointeur sur structure t_list
t_list	*fill_cmd_struct(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	if (tmp->type == 1)
	{
		if (is_cmd(data, tmp->str, data->env_path) && cmd->cmd == NULL)
			handle_cmd(data, cmd, tmp, j);
		else
		{
			// if (!tmp->str)
			// 	cmd->opt[(*j)] = ft_strndup("", 0);
			// else
				cmd->opt[(*j)] = tmp->str;
			(*j)++;
		}
		tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}

// Remplit le tableau de token de t_cmd
t_list	*fill_cmd_tokens(t_cmd *cmd, t_list *tmp, int *k)
{
	if (tmp && tmp->type != 1 && tmp->type != 6 && tmp->next)
	{
		cmd->type[(*k)] = tmp->type;
		tmp = tmp->next;
		cmd->token[(*k)] = tmp->str;
		(*k)++;
		tmp = tmp->next;
	}
	else if (tmp && tmp->type != 1 && tmp->type != 6 && !tmp->next)
	{
		cmd->type[(*k)] = tmp->type;
		cmd->token[(*k)] = NULL;
		(*k)++;
		tmp = tmp->next;
	}
	return (tmp);
}

// Remplit le tableau d'options cmd->opt dans t_cmd
void	handle_cmd(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	cmd->cmd = ft_strndup(tmp->str, 0);
	if (!is_builtin(tmp->str))
	{
		cmd->opt[(*j)] = tmp->str;
		(*j)++;
		find_cmd_path(data, cmd, data->env_path);
	}
}
