/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:39:44 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/21 10:56:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Ajoute le resulat du split a la fin de la structure t_list
// Return 1 si l'ajout a reussie, sinon 0 
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
