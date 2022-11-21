/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:49:19 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 10:58:19 by msharifi         ###   ########.fr       */
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

	tmp = data->cmd;
	while (tmp)
	{
		printf("CMD : %s	TOKEN : %s	TYPE : %d	I : %d\n", tmp->cmd, tmp->token, tmp->type, tmp->index);
		print_tab(tmp->opt);
		tmp = tmp->next;
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
		printf("%s\n", tab[i]);
		i++;
	}
	// printf("\n");
}
