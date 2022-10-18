/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 22:54:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	i = 1;
	data = create_data();
	if (!data)
		return (1);
	while (i < ac)
	{
		data->list = create_list(data, av[i], i);
		if (!data->list)
			return (free_data(data), 2);
		i++;
	}
	print_list(data->list);
	free_data(data);
	return (0);
}
