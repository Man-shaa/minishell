/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/17 18:06:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int    main(int ac, char **av, char **envp)
{
	char	*str;
	t_data	*data;
	int		i;
	
	data = create_data(envp);
	if (ac != 2)
		return (ft_putstr("2 args pls\n"), 1);
	i = 0;
	str = av[1];
	ft_split(str, data);
	if (!check_dup(data))
		return (ft_putstr("2 tokens following each other"), 2);
	free_data(data);
	return (0);
}
