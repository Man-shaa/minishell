/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/19 10:46:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Cherche la variable "PATH=" qui contient tous les chemins possibles de commandes dans envp
char	*find_path_in_env(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		path = ft_strcmp(envp[i], "PATH=");
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}

// int	main(int ac, char **av, char **envp)
// {
// 	char	*path;

// 	(void)ac;
// 	(void)av;
// 	path = find_path_in_env(envp);
// 	if (!path)
// 		return (printf("PATH in env not found\n"), 1);
// 	printf("%s\n", path);
// 	return (0);
// }
