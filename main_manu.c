/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/21 16:46:32 by msharifi         ###   ########.fr       */
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
	t_cmd	*cmd;

	(void)ac;
	data = create_data(envp);
	if (!data)
		return (1);
	ft_split(av[1], data);
	get_cmd_struct(data);
	print_struct_cmd(data);
	cmd = data->cmd;
	while (cmd)
	{
		send_cmd(data, cmd);
		sleep(1);
		cmd = cmd->next;
	}
	print_env(data->envp);
	free_data(data);
	return (0);
}
