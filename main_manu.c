/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/05 19:44:48 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// history
// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque cmd bin
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// Valeur de retour quand cmd not found : [127]
// "echo $dsdg(pas dans env) hello" met un espace avant hello (qui devrait pas)

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	// handle_signal();
// 	get_prompt(envp);
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = create_data(envp);
	if (!data)
		return (1);
	ft_split(av[1], data);
	get_cmd_struct(data);
	printf("%i\n", find_cmd_path(data, data->cmd, data->env_path));
	// print_struct_cmd(data);
	free_data(data);
	return (0);
}
