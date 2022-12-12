/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:39:44 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/12 13:25:55 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (tmp->type == 1 && is_cmd(data, tmp->str, data->env_path)
			&& cappuccino == 0 && moccha == n)
			count += command_or_builtin(tmp->str, &cappuccino);
		else if (tmp->type == 1 && moccha == n)
			count++;
		else if (tmp->type != 1 && tmp->type != 6 && moccha == n)
			count -= 1;
		else if (tmp->type == 6)
			moccha++;
		tmp = tmp->next;
	}
	// printf("words to pipe : %d\n", count);
	return (count);
}

//return 0 si str est une commande return 1 si str est un builtin
int	command_or_builtin(char *str, int *cappuccino)
{
	int	count;

	count = 0;
	(*cappuccino)++;
	if (is_builtin(str))
		return (0);
	else
		return (1);
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
