/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/21 11:05:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	data = create_data(envp);
	if (!data)
		return (1);
	ft_split(av[1], data);
	get_cmd_struct(data);
	print_struct_cmd(data);
	free_data(data);
	return (0);
}
