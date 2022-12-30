/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:49:19 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/30 18:45:35 by mfroissa         ###   ########.fr       */
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
	int		i;

	tmp = data->cmd;
	i = 0;
	while (tmp)
	{
		printf("CMD : %s	I : %d\n", tmp->cmd, tmp->index);
		printf("// CMD->TOKEN //\n");
		print_tab(tmp->token);
		printf("// CMD->TYPE //\n");
		print_int_tab(data, tmp->type);
		printf("// CMD->OPT //\n");
		print_tab(tmp->opt);
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
	while (tab[i])
	{
		printf("tab[%d] : %s\n", i, tab[i]);
		i++;
	}
}

void	print_pipe_fd(int **tab, int until)
{
	int	i;

	i = 0;
	if (!tab)
	{
		printf("tab NULL");
	}
	while (i < until)
	{
		printf("index : %d\n", i);
		printf("pipe_fd[%d][%d] : %d\n", i, 0, tab[i][0]);
		printf("pipe_fd[%d][%d] : %d\n", i, 1, tab[i][1]);
		printf("\n");
		i++;
	}
}

void	print_int_tab(t_data *data, int *tab)
{
	int	n;
	int	i;

	if (!tab)
		return ;
	n = count_tokens(data, 0);
	i = 0;
	printf("INT TAB SIZE : %d\n", n);
	while (i < n)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
}
