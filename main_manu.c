/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/29 18:20:36 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

// Quand export [VAR]=  le split tej le '=' donc pas moyen d'afficher juste "VAR="
// Comment gerer echo $(pwd), echo ${PWD}, bref echo d'une variable d'env ????

// export HA="""" doit ignore TOUS les "" pour en afficher que deux lors du print
// export HA='' chelou (donne HA="")

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	
	data = create_data(envp);
	if (!data)
		return (1);
	if (!export(data, "HA=premier"))
		return (free_data(data), 1);
	print_export(data->envp);
	printf("\nAFTER ADD :\n\n");
	if (!export(data, "HA++=deuxieme"))
		return (free_data(data), 2);
	print_export(data->envp);
	printf("\nAFTER REPLACE :\n\n");
	if (!export(data, "HA=troisieme"))
		return (free_data(data), 3);
	print_export(data->envp);
	printf("\nAFTER UNSET :\n\n");
	unset(data, "HA");
	print_export(data->envp);
	free_data(data);
	return (0);
}
