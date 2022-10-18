/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 23:18:29 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	char *str = "echo     > m mateo";
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}