/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/29 01:15:51 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Test l'acces a av
// Return 1 si le chemin est absolu ou l'acces a reussi, sinon return 0
int	is_path(t_data *data, char *av)
{
	if (!av)
		return (1);
	if (!ft_strchr(av, '/'))
		return (1);
	if (access(av, F_OK | X_OK) == 0)
	{
		data->cmd->cmd_path = av;
		return (0);
	}
	return (1);
}

// Cherche la variable PATH qui contient tous les chemins possibles de
// commandes dans l'environnement
// Return PATH de l'environnement ou NULL si elle n'a pas ete trouvee
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

// Test tous les paths possibles de la variable d'environnement PATH
// Return 1 si un path est valide et le set dans cmd->cmd_path,
// sinon return 0
int	find_cmd_path(t_data *data, t_cmd *cmd)
{
	char	**all_paths;
	t_envp	*tmp;
	int		i;

	tmp = search_node(data->envp, "PATH=");
	if (!tmp)
		return (0);
	i = 0;
	all_paths = ft_split_normal(tmp->tab[1], ':');
	if (!all_paths)
		return (0);
	while (all_paths[i])
	{
		cmd->cmd_path = ft_strjoin(cmd->cmd_path, all_paths[i]);
		cmd->cmd_path = ft_strjoin(cmd->cmd_path, "/");
		cmd->cmd_path = ft_strjoin(cmd->cmd_path, cmd->cmd);
		if (is_path(data, cmd->cmd_path))
		{
			printf("%s\n", cmd->cmd_path);
			return (1);
		}
		i++;
	}
	cmd->cmd_path = NULL;
	printf("%s\n", cmd->cmd_path);
	return (0);
}
