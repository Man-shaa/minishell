/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/25 20:33:08 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	handle_signal();
	data = create_data(envp);
	get_prompt(data, envp);
	free_data(data);
	return (0);
}

// int    main(int ac, char **av, char **envp)
// {
// 	char	*str;
// 	t_data	*data;
// 	int		i;
	
// 	data = create_data(envp);
// 	if (ac != 2)
// 		return (ft_putstr("2 args pls\n"), 1);
// 	i = 0;
// 	str = av[1];
// 	ft_split(str, data);
// 	if (!check_dup(data))
// 		return (ft_putstr("2 tokens following each other\n"), 2);
// 	if (!check_cmd(data))
// 		return (ft_putstr("Pls put a command\n"), 3);
// 	if (!get_cmd_struct(data))
// 		return (1);
// 	print_struct_cmd(data);
// 	// printf("COUNT = %d", words_to_pipe(data, 4));
// 	free_data(data);
// 	return (0);
// }
