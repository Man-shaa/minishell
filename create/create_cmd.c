/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:03:31 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/13 19:31:08 by mfroissa         ###   ########.fr       */
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
	cmd->token = ft_calloc(count_tokens(data, (*i)) + 1, sizeof(char *));
	if (!cmd->token)
		return (NULL);
	cmd->token[count_tokens(data, (*i))] = 0;
	if (count_tokens(data, (*i)) > 0)
		cmd->type = ft_calloc(count_tokens(data, (*i)), sizeof(int));
	return (cmd);
}

int	get_cmd_struct(t_data *data)
{
	t_list	*tmp;
	t_cmd	*cmd;

	tmp = data->list;
	cmd = NULL;
	if (!start_cmd_struct(data, tmp, cmd))
		return (0);
	return (1);
}

int start_cmd_struct(t_data *data, t_list *tmp, t_cmd *cmd)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (tmp)
	{
		j = 0;
		k = 0;
		cmd = set_up_cmd(data, &i);
		if (!cmd)
			return (0);
		while (tmp && tmp->type != 6)
		{
			tmp = fill_cmd_struct(data, cmd, tmp, &j);
			tmp = fill_cmd_tokens(cmd, tmp, &k);
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
