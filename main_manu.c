/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/05 15:41:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// history
// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque cmd binaire
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// Valeur de retour quand cmd not found : [127]

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;
// 	int		exit_status;
// 	t_cmd	*cmd;

// 	(void)ac;
// 	data = create_data(envp);
// 	if (!data)
// 		return (1);
// 	ft_split(av[1], data);
// 	get_cmd_struct(data);
// 	cmd = data->cmd;
// 	while (cmd)
// 	{
// 		send_cmd(data, cmd);
// 		cmd = cmd->next;
// 	}
// 	exit_status = data->return_val;
// 	free_data(data);
// 	return (exit_status);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;
// 	char	*str;

// 	(void)ac;
// 	(void)av;
// 	data = create_data(envp);
// 	str = readline("test > ");
// 	printf("%s\n", str);
// 	if (is_same(str, "exit"))
// 	{
// 		// free_data(data);
// 		ft_exit(data, NULL);
// 	}
// 	free_data(data);
// 	return (0);
// }