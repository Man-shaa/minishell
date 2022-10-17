/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:11:04 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/17 20:12:07 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	char	*str;

	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	str = tab;
	while (n > 0)	
	{
		n--;
		str[n] = '\0';
	}
	return (tab);
}

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	if (tab)
		ft_free(tab);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd *save;

	save = cmd;
	while (cmd)
	{
		cmd = cmd->next;
		if (save->cmd_args)
			free_tab(save->cmd_args);
		if (save->cmd_path)
			ft_free(save->cmd_path);
		ft_free(save);
		save = cmd;
	}
}

// void	free_redir(t_redir *redir)
// {

// }

void	free_data(t_data *data)
{
	if (data->cmd)
		free_cmd(data->cmd);
	ft_free(data);
}
