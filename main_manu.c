/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/12/08 19:17:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// history
// ft_atoi avant pour recup d'argument du prompt (avec tab et 32)
// Ajouter les valeurs de retour de chaque cmd bin
// nouvelle structure t_pipex ? pour les pid, char *cmd_path
// Valeur de retour quand cmd not found : [127]
// "echo $dsdg(pas dans env) hello" met un espace avant hello (qui devrait pas)
// Manuo "clear" msg d'erreur automatique + retour data->return_val chelou

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	// char	**tab1;
	// char	**tab2;
	// tab1 = ft_calloc(2, sizeof(char *));
	// tab2 = ft_calloc(3, sizeof(char *));
	// tab1[0] = ft_strndup("ls", 0);
	// tab1[1] = 0;
	// tab2[0] = ft_strndup("wc", 0);
	// tab2[1] = ft_strndup("-l", 0);
	// tab2[2] = 0;


	// int	i = 0;
	// int	fd[2];
	// int	pid;
	// while (i < 2)
	// {
	// 	pid = fork();
	// 	if (pipe (fd) == -1)
	// 		return (1);
	// 	if (pid == 0)
	// 	{
	// 		dup2(fd[1], STDOUT_FILENO);
	// 		close(fd[0]);
	// 		close(fd[1]);
	// 		if (execve("/usr/bin/ls", tab1, envp) == -1)
	// 			return (2);
	// 	}
	// }
	// close (fd[0]);
	// close (fd[1]);
	// waitpid(pid, NULL, 0);
	// free_tab(tab1);
	// free_tab(tab2);
	return (0);
}

// int	main(int ac, char **av, char **envp)
// {
// 	t_data	*data;

// 	(void)ac;
// 	(void)av;
// 	data = create_data(envp);
// 	if (!data)
// 		return (1);
// 	ft_split(av[1], data);
// 	// printf("%i\n", find_cmd_path(data, av[1], data->env_path));
// 	get_cmd_struct(data);
// 	// is_cmd(data, data->cmd, data->env_path);
// 	print_struct_cmd(data);
// 	free_data(data);
// 	return (0);
// }
