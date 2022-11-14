/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/07 16:38:46 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av)
{
	char *str;
	t_data	*data;
	
	data = ft_calloc(1, sizeof(t_data));
	if (ac != 2)
		ft_putstr("2 args pls");
	str = av[1];
	str = "hell \"mina\"";
	ft_split(str, data);
	print_list(data->list);
	free_data(data);
	return (0);
}