/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:06:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/23 17:12:36 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	find_cmd_path(t_data *data, t_cmd *cmd)
{
	char	**all_paths;
	int		i;

	i = 0;
	all_paths = ft_split_normal(search_node(data->envp, "PATH=")->tab[1], ':');
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
