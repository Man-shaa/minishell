/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/15 15:58:48 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char *str;
	char	**tab;
	t_data	*data;
	int	i;
	
	data = create_data(envp);
	if (ac != 2)
		ft_putstr("2 args pls");
	i = 0;
	str = av[1];
	tab = ft_split(str, data);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		free(tab[i]);
		i++;
	}
	free_data(data);
	ft_free(tab);
	return (0);
}