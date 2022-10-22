/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/22 20:29:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash
// recuperation de variable LS_COLOR pas bonne si env existe

int	main(int ac, char **av, char **envp)
{
	t_data *data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	env(data->envp);
	// export(data->envp);
	free_data(data);
	return (0);
}