/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:15:26 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/21 06:04:56 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_dup(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (tmp->next && tmp->type != 1 && tmp->next->type != 1)
		{
			if (tmp->next->type != 6)
				return (0);
		}
		if (tmp->next && tmp->type == 6 && tmp->next->type == 6)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	words_to_pipe(t_data *data, int	n)
{
	t_list	*tmp;
	int	count;
	int	cappuccino;
	int	moccha;

	tmp = data->list;
	count = 0;
	moccha = 0;
	cappuccino = 0;
	while (tmp)
	{
		if (tmp->type == 1 && is_builtin(tmp->str) && cappuccino == 0 && moccha == n)
			cappuccino++;
		else if (tmp->type == 1 && moccha == n)
			count++;
		else if (tmp->type != 1 && tmp->type != 6 && moccha == n)
			count -= 1;
		else if (tmp->type == 6)
			moccha++;
		tmp = tmp->next;
	}
	return (count);
}

void	get_cmd_struct(t_data *data)
{
	t_list	*tmp;
	t_cmd	*cmd;
	int		i;
	int		j;

	tmp = data->list;
	i = 0;
	// cmd = NULL;
	// data->cmd = cmd;
	while (tmp)
	{
		j = 0;
		cmd = ft_cmdnew(i);
		cmd->opt = ft_calloc(words_to_pipe(data, i) + 1, sizeof(char *));
		if (!cmd->opt)
			return ; //Rajouter valeur de retour d'erreur
		while (tmp && tmp->type != 6)
		{
			tmp = fill_cmd_struct(cmd, tmp, &j);
			tmp = tmp->next;
		}
		add_back(data, cmd);
		i++;
		if (tmp)
			tmp = tmp->next;
	}
}

t_list	*fill_cmd_struct(t_cmd *cmd, t_list *tmp, int *j)
{
	if (tmp->type == 1)
	{
		if (is_builtin(tmp->str)) //premier seulement
			cmd->cmd = tmp->str;
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
	}
	else
	{
		cmd->type = tmp->type;
		tmp = tmp->next;
		cmd->token = tmp->str;
		// fill_cmd_struct_exp(cmd, tmp);
	}
	return (tmp);
}
