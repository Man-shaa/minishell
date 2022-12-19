/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/19 15:13:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// echo "skdf$PWDsfd     jkhsd" split zap les espaces et en mettre qu'un seul
// ".." pete un cable
// echo "$" ou plusieurs "$" ne les affiche pas (ignore_charset)

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	handle_signal();
	get_prompt(envp);
	return (0);
}

// int main(int argc, char *argv[])
// {
//     int status;
//     pid_t pid = fork();
// 	(void)argc;
// 	(void)argv;

//     if (pid == 0) {
//         // Processus enfant
//         return 42;
//     } else {
//         // Processus parent
//         waitpid(pid, &status, 0);
//         if (WIFEXITED(status)) {
//             printf("La valeur de retour du processus enfant est %d\n", WEXITSTATUS(status));
//         }
//     }

//     return 0;
// }