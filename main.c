/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 19:11:15 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	data = create_data();
	if (!data)
		return (1);
	data->cmd = create_cmd(data->cmd, av[1]);
	data->cmd = create_cmd(data->cmd, av[2]);
	print_cmd(data->cmd);
	free_data(data);
	return (0);
}
