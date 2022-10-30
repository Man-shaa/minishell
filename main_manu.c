/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/29 17:38:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

// Quand export [VAR]=  le split tej le '=' donc pas moyen d'afficher juste "VAR="
// Comment gerer echo $(pwd), echo ${PWD}, bref echo d'une variable d'env ????

// export HA="""" doit ignore TOUS les "" pour en afficher que deux lors du print
// export HA='' chelou (donne HA="")
// export += a gerer

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	
	data = create_data(envp);
	if (!data)
		return (1);
	export(data, "HA=premier");
	print_export(data->envp);
	printf("\nAFTER ADD :\n\n");
	export(data, "HA+=deuxieme");
	print_export(data->envp);
	printf("\nAFTER REPLACE :\n\n");
	export(data, "HA=troisieme");
	printf("\nAFTER UNSET :\n\n");
	unset(data, "HA");
	print_export(data->envp);
	free_data(data);
	return (0);
}
