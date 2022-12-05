/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/05 17:01:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// history
// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque cmd bin
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// Valeur de retour quand cmd not found : [127]

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	// handle_signal();
	get_prompt(envp);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;
// 	char	**tab;
	
// 	tab = ft_calloc(2, sizeof(char *));
// 	tab[0] = ft_strndup("HA", 0);
// 	tab[1] = 0;
// 	// int		exit_status;
// 	// t_cmd	*cmd;

// 	(void)ac;
// 	data = create_data(envp);
// 	if (!data)
// 		return (1);
// 	(void)av;
// 	printf("\n BEFORE\n");
// 	print_export(data->envp);
// 	ft_export(data, tab);
// 	printf("\n AFTER\n");
// 	printf("\n");
// 	ft_free(tab[0]);
// 	tab[0] = ft_strndup("HA=MATT", 0);
// 	print_export(data->envp);
// 	printf("\n AFTER AFTER\n");
// 	printf("\n");
// 	ft_export(data, tab);
// 	print_export(data->envp);
// 	free_tab(tab);
// 	// ft_split(av[1], data);
// 	// get_cmd_struct(data);
// 	// cmd = data->cmd;
// 	// while (cmd)
// 	// {
// 	// 	send_cmd(data, cmd);
// 	// 	cmd = cmd->next;
// 	// }
// 	// exit_status = data->return_val;
// 	// return (exit_status);
// 	free_data(data);
// 	return (0);
// }
