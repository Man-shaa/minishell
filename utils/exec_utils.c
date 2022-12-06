/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/06 20:06:26 by msharifi         ###   ########.fr       */
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
// Return 1 si un path est valide et le met dans cmd->cmd_path, sinon return 0
int	find_cmd_path(t_data *data, t_cmd *cmd, char *env_path)
{
	int		i;
	char	**all_paths;
	char	*path;

	i = 0;
	if (!cmd->cmd)
		return (0);
	all_paths = ft_split_normal(env_path, ':');
	if (!all_paths && is_path(data, cmd->cmd))
		return (err_msg("env not found, please specify a path directly\n", NULL, NULL, 2), 0);
	if (!is_path(data, cmd->cmd))
		return (free_tab(all_paths), 1);
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], "/");
		cmd->cmd_path = ft_strjoin(path, cmd->cmd);
		ft_free(path);
		if (access(cmd->cmd_path, F_OK | X_OK) == 0)
			return (free_tab(all_paths), 1);
		ft_free(cmd->cmd_path);
		i++;
	}
	free_tab(all_paths);
	return (err_msg("No such file or directory\n", NULL, NULL, 2), 0);
}

int	is_cmd(t_data *data, char *str, char *env_path)
{
	int		i;
	char	**all_paths;
	char	*path;
	char	*save;

	i = 0;
	all_paths = ft_split_normal(env_path, ':');
	if (!all_paths && is_path(data, str))
		return (err_msg("env not found, please specify a path directly\n", NULL, NULL, 2), 0);
	if (!is_path(data, str))
		return (free_tab(all_paths), 1);
	while (all_paths[i])
	{
		save = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(save, str);
		ft_free(save);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free(path), free_tab(all_paths), 1);
		ft_free(path);
		i++;
	}
	free_tab(all_paths);
	return (0);
}
