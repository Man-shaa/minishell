/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:15:26 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/23 15:03:09 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parsing(t_data *data)
{
	if (!check_dup(data))
		return (err_msg("Doublons of redirections", NULL, NULL, 0));
	if (!check_cmd(data))
		return (err_msg("Missing a command", NULL, NULL, 0));
	return (1);
}

int	check_dup(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (tmp->next && tmp->type != WORD && tmp->next->type != WORD)
		{
			if (tmp->next->type != PIPE)
				return (0);
		}
		if (tmp->next && tmp->type == PIPE && tmp->next->type == PIPE)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_cmd(t_data *data)
{
	t_list	*tmp;
	int		count;

	tmp = data->list;
	count = 0;
	while (tmp)
	{
		if (is_cmd(data, tmp->str, data->env_path))
			count++;
		else if (tmp->type == PIPE)
		{
			if (count == 0)
				return (0);
			else
				count = 0;
		}
		tmp = tmp->next;
	}
	return (1);
}
