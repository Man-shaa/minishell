/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/25 11:44:40 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(void)
{
	char	*str;
	char	**tab;
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	str = readline("Manuo 🤔 ✖✖ ");
	i = 0;
	tab = ft_split(str, data);
	while (tab[i])
	{
		printf("SPLIT : %s\n", tab[i]);
		free(tab[i]);
		i++;
	}	
}