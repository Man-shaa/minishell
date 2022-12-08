/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:03:31 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/08 17:42:45 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*set_up_cmd(t_data *data, int *i)
{
	t_cmd	*cmd;

	cmd = ft_cmdnew(*i);
	cmd->opt = ft_calloc(words_to_pipe(data, (*i)) + 1, sizeof(char *));
	if (!cmd->opt)
		return (NULL);
	cmd->opt[words_to_pipe(data, (*i))] = 0;
	return (cmd);
}

int	get_cmd_struct(t_data *data)
{
	t_list	*tmp;
	t_cmd	*cmd;
	int		i;
	int		j;

	tmp = data->list;
	i = 0;
	cmd = NULL;
	while (tmp)
	{
		j = 0;
		cmd = set_up_cmd(data, &i);
		if (!cmd)
			return (0);
		while (tmp && tmp->type != 6)
		{
			tmp = fill_cmd_struct(data, cmd, tmp, &j);
			tmp = tmp->next;
		}
		add_back(data, cmd);
		i++;
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}

t_list	*fill_cmd_struct(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	if (tmp->type == 1)
	{
		if (is_cmd(data, tmp->str, data->env_path) && cmd->cmd == NULL)
			handle_cmd(data, cmd, tmp, &(*j));
		else if (tmp->next && tmp->next->type == 2)
		{
			cmd->token = tmp->str;
			tmp = tmp->next;
			cmd->type = tmp->type;
		}
		else
		{
			cmd->opt[(*j)] = tmp->str;
			(*j)++;
		}
		return (tmp);
	}
	cmd->type = tmp->type;
	tmp = tmp->next;
	cmd->token = tmp->str;
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