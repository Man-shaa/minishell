/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/14 14:56:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_cmd_table	*create_command_table(int ac, char **av)
{
	int			i;
	t_cmd_table	*cmd_tbl;

	i = 0;
	while (i < ac)
	{
		if (!add_last(cmd_tbl, av[i]))
			return (NULL);
		i++;
	}
	return (cmd_tbl);
}

int	main(int ac, char **av)
{
	char	*str;
	t_cmd_table	cmd_tbl;

	cmd_tbl = create_command_table(ac, av);
	return (0);
}
