/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:49:19 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 22:47:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("\n\n");
}
