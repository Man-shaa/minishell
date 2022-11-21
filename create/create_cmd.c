/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:03:31 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 11:17:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		cmd->opt[words_to_pipe(data, i)] = 0;
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
