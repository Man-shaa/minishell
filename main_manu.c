/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/24 23:46:02 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)
// [env] si plusieurs '=' dans la meme ligne, seulement le premier est recup :(

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;

// 	(void)ac;
// 	// (void)envp;
// 	// char	**tab;

// 	// tab = ft_split_env(av[1], '=');
// 	// print_tab(tab);
// 	// free_tab(tab);
// 	(void)av;
	
// 	data = create_data(envp);
// 	if (!data)
// 		return (1);
// 	print_env(data->envp);
// 	free_data(data);
// 	return (0);
// }
