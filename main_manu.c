/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/22 17:34:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash
// recuperation de variable LS_COLOR pas bonne

int	main(int ac, char **av, char **envp)
{
	t_data *data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	print_env(data->envp);
	free_data(data);
	return (0);
}