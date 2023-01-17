/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:36 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/17 15:14:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Ajoute le resulat du split a la fin de la structure t_list
void	add_back(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = ft_cmdlast(data->cmd);
	if (!tmp)
	{
		data->cmd = cmd;
		return ;
	}
	tmp->next = cmd;
}

// Cree un nouveau node dans la structure t_list et initialise a NULL
// Return un pointeur sur t_list ou NULL si le malloc a rate
t_cmd	*ft_cmdnew(int index)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->cmd_path = NULL;
	cmd->index = index;
	cmd->opt = NULL;
	cmd->token = NULL;
	cmd->type = 0;
	cmd->next = NULL;
	return (cmd);
}

// Cherche le dernier node dans la strucure t_list
// Return le dernier node ou NULL si la structure n'existe pas
t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

int	pipe_count(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	if (i > 0)
		i--;
	return (i);
}
