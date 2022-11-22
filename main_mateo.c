/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/22 19:59:19 by mfroissa         ###   ########.fr       */
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
	if (!get_cmd_struct(data))
		return (1);
	print_struct_cmd(data);
	// printf("COUNT = %d", words_to_pipe(data, 4));
	free_data(data);
	return (0);
}
