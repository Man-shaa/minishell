/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/21 13:56:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque builtin + cmd binaires
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// echo -n -n -n -n va annuler la nezline mais aussi zapper tous les autres -n

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)ac;
	data = create_data(envp);
	if (!data)
		return (1);
	ft_split(av[1], data);
	get_cmd_struct(data);
	print_struct_cmd(data);
	send_cmd(data);
	free_data(data);
	return (0);
}
