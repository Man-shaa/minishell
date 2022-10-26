/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/26 17:13:12 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// quand export [VAR]=  le split tej le '=' donc pas moyen d'afficher juste "VAR="
// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	
	data = create_data(envp);
	if (!data)
		return (1);
	print_export(data->envp);
	export(data, "a=truc");
	printf("\nAFTER ADD :\n\n");
	print_export(data->envp);
	printf("\nAFTER DELETE :\n\n");
	unset(data->envp, "a");
	print_export(data->envp);
	free_data(data);
	return (0);
}
