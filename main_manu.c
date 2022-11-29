/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/29 04:58:23 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// history
// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque cmd binaire
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// Valeur de retour quand cmd not found : [127]

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;

// 	(void)ac;
// 	(void)av;
// 	handle_signal();
// 	data = create_data(envp);
// 	get_prompt(data, envp);
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_status;
	t_cmd	*cmd;

	(void)ac;
	data = create_data(envp);
	if (!data)
		return (1);
	ft_split(av[1], data);
	get_cmd_struct(data);
	ft_split(av[2], data);
	get_cmd_struct(data);
	cmd = data->cmd;
	while (cmd)
	{
		send_cmd(data, cmd);
		cmd = cmd->next;
	}
	exit_status = data->return_val;
	free_data(data);
	return (exit_status);
}
