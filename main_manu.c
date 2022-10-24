/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/24 23:50:11 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	print_env(data->envp);
	replace_pwd_my_env(data->envp);
	printf("\nAFTER\n\n");
	print_env(data->envp);

	printf("\n\nDEUXIEME FOIS !\n\n\n");

	print_env(data->envp);
	replace_pwd_my_env(data->envp);
	printf("\nAFTER\n\n");
	print_env(data->envp);
	free_data(data);
	return (0);
}
