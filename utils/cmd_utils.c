/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:39:44 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/03 18:50:01 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return le compteur de token dans une commande avec n pour l'index du pipe
int	count_tokens(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		index;

	tmp = data->list;
	count = 0;
	index = 0;
	if (tmp->type != 1 && !tmp->next)
		return (1);
	while (tmp)
	{
		if (tmp && (tmp->type != WORD && tmp->type != PIPE) && index == n
			&& tmp->next->type == WORD)
		{
			tmp = tmp->next;
			count++;
		}
		else if (tmp->type == PIPE)
			index++;
		tmp = tmp->next;
	}
	return (count);
}

// Return le compteur de type1 dans une commande avec n pour l'index du pipe
int	words_to_pipe(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		cappuccino;
	int		index;

	tmp = data->list;
	count = 0;
	index = 0;
	cappuccino = 0;
	while (tmp)
	{
		if (tmp->type == WORD && is_cmd(data, tmp->str, data->env_path)
			&& cappuccino == 0 && index == n)
			count += command_or_builtin(tmp->str, &cappuccino);
		else if (tmp->type == WORD && index == n)
			count++;
		else if (tmp->type != WORD && tmp->type != PIPE && index == n)
			count -= 1;
		else if (tmp->type == PIPE)
			index++;
		tmp = tmp->next;
	}
	if (count == -1)
		return (0);
	return (count);
}

// Return 0 si str est une commande return 1 si str est un builtin
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
