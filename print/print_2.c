/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:01:48 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/03 12:49:30 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_tab_index(int *tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < n)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
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
