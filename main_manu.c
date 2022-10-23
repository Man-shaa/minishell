/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansha <mansha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/23 20:23:40 by mansha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)
// [env] si plusieurs '=' dans la meme ligne, seulement le premier est recup :(

int	main(int ac, char **av, char **envp)
{
	t_data *data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	print_env(data->envp);
	// print_export(data->envp);
	free_data(data);
	return (0);
}