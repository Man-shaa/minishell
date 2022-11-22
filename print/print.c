/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:49:19 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/22 20:00:08 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// print toutes les listes recuperees du split parsing
void	print_list(t_list *list)
{
	int	i;

	i = 1;
	while (list)
	{
		printf("\n");
		printf("*****************  [%i]  *****************\n\n", i);
		printf("STRING : %s\n", list->str);
		printf("TYPE : %d\n", list->type);
		i++;
		list = list->next;
	}
	printf("\n");
}

// print toutes les commandes/redirections de t_cmd recuperee de t_list
void	print_struct_cmd(t_data *data)
{
	t_cmd	*tmp;
	int	i;

	tmp = data->cmd;
	i = 0;
	while (tmp)
	{
		printf("CMD : %s	TOKEN : %s	TYPE : %d	I : %d\n", tmp->cmd, tmp->token, tmp->type, tmp->index);
		print_tab(tmp->opt);
		printf("COUNT = %d\n", words_to_pipe(data, i));
		printf("\n");
		tmp = tmp->next;
		i++;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	// printf("\n");
	while (tab[i])
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}
	// printf("\n");
}
