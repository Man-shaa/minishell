/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/30 19:29:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument en bash (avec tab et 32)

// Quand export [VAR]=  le split tej le '=' donc pas moyen d'afficher juste "VAR="
// Comment gerer echo $(pwd), echo ${PWD}, bref echo d'une variable d'env ????

// export HA="""" consider les deux "" comme faisant partie de la string et les affiche

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	print_env(data->envp);
	if (!export(data, "HA=\"premier\""))
		return (free_data(data), 2);
	printf("AFTER ADD : \n");
	print_env(data->envp);
	if (!export(data, "HA+=deu\"x\'ie\"m\"e"))
		return (3);
	printf("AFTER CONCAT : \n");
	print_env(data->envp);
	if (!export(data, "HA=troisieme"))
		return (3);
	printf("AFTER REPLACE : \n");
	print_env(data->envp);
	unset(data, "\"\"H\"\'A");
	printf("AFTER UNSET : \n");
	print_env(data->envp);
	free_data(data);
	return (0);
}
