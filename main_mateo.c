/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/15 16:35:52 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int    main(int ac, char **av, char **envp)
{
	char	*str;
	char	**tab;
	t_data	*data;
	int		i;
	
	data = create_data(envp);
	if (ac != 2)
		return (ft_putstr("2 args pls\n"), 1);
	i = 0;
	str = av[1];
	tab = ft_split(str, data);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
	free_data(data);
	ft_free(tab);
	return (0);
}