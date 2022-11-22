/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:39:44 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/22 20:08:15 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return le nombre d'options de la commande dans un bloc separe par des '|'
int	words_to_pipe(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		cappuccino;
	int		moccha;

	tmp = data->list;
	count = 0;
	moccha = 0;
	cappuccino = 0;
	while (tmp)
	{
		if (tmp->type == 1 && is_builtin(tmp->str)
			&& cappuccino == 0 && moccha == n)
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
